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
    unsigned int x = (255 << 24) | (255 << 16) | (255 << 8) | (1); // inizialisation 1 2 3 4 byte
    unsigned int y = ~(0b00000000 << 24);
    x &= ~((127 << 24) | (125 << 16)); // Set to 3 and 2 byte to 0
    printf("x equals %0b\n", x);
    printf("y equals %0b\n", y);
    unsigned int z = (x & (255 << 16)) >> 16; // peek 3 byte
    printf("z equals %0b\n", z);
    unsigned char p = *((u_int8_t *)&x + 2); // peek 3 byte
    printf("p equals %0b\n", p);
    unsigned int t = (x & ~(255 << 8)) | (6 << 8); // update 2 byte
    printf("t equals %0b\n", t);

    int socket_desc = 0,
        sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "Hello";

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

        // Receive a reply from the client
        if (recv(sock, client_message, 200, 0) < 0)
        {
            printf("recv failed");
            break;
        }

        printf("Client reply: %s\n", client_message);

        if (strncmp(pMessage, client_message, 5) == 0)
        {
            strcpy(message, "Hi there!\n");
        }
        else
        {
            strcpy(message, "Invallid Message!");
        }

        // Send some data
        if (send(sock, message, strlen(message), 0) < 0)
        {
            printf("Send failed");
            return 1;
        }

        close(sock);
        sleep(1);
    }
    return 0;
}