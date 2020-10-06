#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main(){

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_socket < 0 ? printf("Error Opening Socket\n") : printf("Socket Working\n");

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(6001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(server_socket, 5);
    int client_socket = accept(server_socket, NULL, NULL);

    int line[256];
    recv(client_socket, &line, sizeof(line), 0);
    for (int i = 0; i < 5; i++){
        printf("%d ",line[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++)         
       for (int j = 0; j < 4; j++)  
           if (line[j] > line[j+1]) 
              swap(&line[j], &line[j+1]); 

    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += line[i];
        printf("%d ",line[i]);
    }
    
    send(client_socket, &sum, sizeof(int), 0);

    return 0;
}