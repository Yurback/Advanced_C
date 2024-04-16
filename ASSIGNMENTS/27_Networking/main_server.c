#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

enum message_type
{
    GET,
    POST,
    SET,
    UPDATE,
    DELETE
};

struct message_client
{
    int client_id;
    int message;
    int data;
};

int createServer(void)
{
    int err = -1;
    err = socket(AF_INET, SOCK_STREAM, 0);
    if (err == -1)
    {
        printf("Can't to build server\n");
        exit(1);
    }
    return err;
}

void setServer(int host, int numberClient)
{
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_family = AF_INET;
    remote.sin_port = htons(9800);
    int err = bind(host, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    if (err < 0)
    {
        printf("Bind socket failed\n");
        exit(1);
    }
    listen(host, 10);
    printf("Ready to listen %d clients\n", numberClient);
    return;
}

int main(void)
{
    struct message_client req = {0};
    int content = 0;
    // char buf[200] = {0};
    char *greet = "Hello from server";
    char answer[10] = {0};
    struct sockaddr_in client;
    int clientLen = sizeof(struct sockaddr_in);
    int myserver = createServer();
    setServer(myserver, 10);

    while (1)
    {
        int call = accept(myserver, (struct sockaddr *)&client, (socklen_t *)&clientLen);
        if (call < 0)
        {
            printf("Accept call failed\n");
            continue;
        }
        printf("Connection accepted\n");

        int err = recv(call, &req, sizeof(req), 0);
        if (err < 0)
        {
            printf("recv failed");
            continue;
        }
        if (req.client_id == 1 && req.message == POST)
        {
            content = req.data - 1;
        }
        printf("Id: %d, Client message: %s, Data: %d\n", req.client_id, (req.message == 1) ? "POST" : "GET", req.data);

        if (req.client_id != 1 && content != 0)
        {
            sprintf(answer, "%d", content);
            printf("the greet is %s\n", answer);
            err = send(call, answer, strlen(answer), 0);
        }
        else
        {
            err = send(call, greet, strlen(greet), 0);
        }
        if (err < 0)
        {
            printf("send failed\n");
            continue;
        }
        printf("message was successfully send\n");

        close(call);
    }
}