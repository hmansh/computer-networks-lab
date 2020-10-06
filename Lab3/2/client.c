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

    char msg[100];
    struct sockaddr_in tempSendAddr;

    int len = sizeof(struct sockaddr);

    recvfrom(clientSocket, msg, 100, 0, (struct sockaddr *)&tempSendAddr, &len);

    printf("Recieved from Server : %s\n", msg);

    return 0;

}