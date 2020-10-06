#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

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

    char line[256];
    recv(client_socket, &line, sizeof(line), 0);
    printf("Client : %s\n", line);

    int vowel = 0;
    int len = strlen(line);
    char rev[256];

    int end = len - 1;

    for (int begin = 0; begin < len; begin++) {
      rev[begin] = line[end];
      end--;
    }

    printf("Reverse : %s\n", rev);
    int count = 0;
    for (int i = 0 ; i < len -1; i++){
        if(line[i] == rev[i]){
            count++;
        }
    }
    if (count == len - 1){
        printf("PALINDROME\n");
    } else {
        printf("NOT PALINDROME\n");
    }

    return 0;
}