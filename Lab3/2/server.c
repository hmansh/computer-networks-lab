#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(){
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = ntohs(6011);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr)) == 0 ? printf("Done Binding\n") : printf("Error While Binding\n");

    char msg[100] = "Thank You";

    printf("Sent to Client : %s\n", msg);

    struct sockaddr_in server;
    server.sin_family  = AF_INET;
    server.sin_port = ntohs(6011);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(serverSocket, msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(struct sockaddr));
    
    return 0;
}