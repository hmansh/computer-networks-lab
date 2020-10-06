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

    int msg[100] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0 ; i < 7; i++){
        printf("%d ", msg[i]);
    }
    printf("\n");

    struct sockaddr_in server;
    server.sin_family  = AF_INET;
    server.sin_port = ntohs(6011);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(clientSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(struct sockaddr));

    struct sockaddr_in tempsendaddr;

    int largest;
    int len = sizeof(struct sockaddr);

    recvfrom(clientSocket, &largest, 100, 0, (struct sockaddr *)&tempsendaddr, &len);
    printf("\nReceive from Server : %d\n", largest);

}