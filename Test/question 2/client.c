#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    
    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = ntohs(6002);
    clientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(clientSocket, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) == 0? 
    printf("Bind Done\n") : printf("Bind Error\n") ;

    char msg[100] = "Hello KIIT";

    printf("%s\n", msg);

    struct sockaddr_in server;
    server.sin_family  = AF_INET;
    server.sin_port = ntohs(6001);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(clientSocket, msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(struct sockaddr));
    return 0;

}
