#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void)
{
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreateSocket(int hSocket)
{
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    /*Internet address family*/
    remote.sin_family = AF_INET;

    // Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); // Local port

    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

int main(void)
{
    int socket_desc = 0,
        sock = 0, clientLen = 0, n = 0;
    struct sockaddr_in client;
    char client_message[4097] = {0};
    char message[4097] = {0};

    // Create socker
    socket_desc = socketCreate();
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }

    printf("Socket created\n");

    // Bind
    if (bindCreateSocket(socket_desc) < 0)
    {
        // print the error message
        perror("bind failed.");
        return 1;
    }

    printf("bind done\n");

    // Listen
    listen(socket_desc, 3);

    // Accept and incoming connection
    while (1)
    {
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);

        // accept connection from an incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&clientLen);

        if (sock < 0)
        {
            perror("accept failed");
            return 1;
        }

        printf("Connection accepted\n");
        memset(client_message, '\0', sizeof(client_message));

        while ((n = read(sock, client_message, 4096)) > 0)
        {
            fprintf(stdout, "\n%s\n", client_message);
            if (client_message[n - 1] == '\n')
            {
                break;
            }
            memset(client_message, 0, 4096);
        }
        if (n < 0)
            printf("ERROR occured");

        // now send a response.
        snprintf((char *)message, sizeof(message), "HTTP/1.0 200 OK\r\n\r\nHello");

        write(sock, (char *)message, strlen((char *)message));
        close(sock);
    }
}
