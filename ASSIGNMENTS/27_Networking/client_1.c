#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

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

short socketCreate(void)
{
    short hSocket = 0;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (hSocket == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }
    return hSocket;
}

int socketConnect(int hSocket)
{
    int iRetval = -1;
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(9800);

    iRetval = connect(hSocket, (const struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    if (iRetval < 0)
    {
        perror("connect failed.\n");
        return 1;
    }
    return iRetval;
}

int socketSend(int hSocket, struct message_client *Rqst, short lenRqst)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; // 20 Secs Timeout
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

int socketReceive(int hSocket, char *Rsp, short RvcSize)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; // 20 Secs Timeout
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }

    shortRetval = recv(hSocket, Rsp, RvcSize, 0);

    return shortRetval;
}

int main(int argc, char *argv[])
{
    struct message_client payload = {0};
    int hSocket = 0, read_size = 0;
    // struct sockaddr_in server;
    // char sendToServer[100] = {0};
    char server_reply[200] = {0};

    // Create socket
    hSocket = socketCreate();
    printf("Socket is created\n");

    socketConnect(hSocket);
    printf("Successfully connected with server\n");

    printf("Enter the Message: ");
    char buffer[100];
    fgets(buffer, 100, stdin);
    if (atoi(buffer) == POST)
    {
        payload.data = atoi(argv[2]);
        payload.message = atoi(buffer);
    }
    else
    {
        payload.message = GET;
        payload.data = 0;
    }
    payload.client_id = atoi(argv[1]);

    // Send data to the server
    socketSend(hSocket, &payload, sizeof(payload));

    // Received the data from the server
    read_size = socketReceive(hSocket, server_reply, 200);
    if (read_size == -1)
    {
        printf("Nothing to recieve\n");
        return 0;
    }
    printf("Server Response: %s\n\n", server_reply);

    close(hSocket);

    return 0;
}