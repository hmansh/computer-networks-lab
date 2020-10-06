#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    client_socket < 0 ? printf("Error Making Socket\n") : printf("Socket Successful\n");

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(6009);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int stat = connect(client_socket, (struct sockaddr *) & server_address, sizeof(server_address));
    stat == -1 ? printf("Error During Connect\n") : printf("Connection Working\n");

    int client_message[256] = {25, 28, 45, 30, 60, 40};
    printf("Sending : ");
        for (int i = 0; i < 6; i++){
        printf("%d ",client_message[i]);
    }
    send(client_socket, client_message, sizeof(client_message), 0);
    
    
    int line[256];
    recv(client_socket, line, sizeof(line), 0);
       for (int i = 0; i < 6; i++){
        printf("%d ",line[i]);
    }
    printf("\n");
    return 0;
}
