#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    
    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = ntohs(6009);
    clientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(clientSocket, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) == 0? printf("Binding Done\n") : printf("Error While Binding\n") ;

    char msg[100] = "KALINGA UNIVERSITY";

    printf("Sent to Server : %s", msg);

    struct sockaddr_in server;
    server.sin_family  = AF_INET;
    server.sin_port = ntohs(6011);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(clientSocket, msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(struct sockaddr));

    struct sockaddr_in tempsendaddr;
    
    char buf[100];
    int len = sizeof(struct sockaddr);

    recvfrom(clientSocket, buf, 100, 0, (struct sockaddr *)&tempsendaddr, &len);
    printf("\nReceive from Server : %s\n", buf);

}