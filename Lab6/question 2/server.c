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
    serverAddr.sin_port = ntohs(6001);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr))

    struct sockaddr_in tempSend;

    char buf[100];
    int len = sizeof(struct sockaddr);

    recvfrom(serverSocket, buf, 100, 0, (struct sockaddr *)&tempSend, &len);

    printf("Recieved  - %s\n", buf);
    
    len = strlen(buf);
    int count = 0;
    for(int i = 0; i < len; i++){
    	if (buf[i] == ' '){
    		count++;
    	}
    }
    printf("words - %d\n",count+1);

    return 0;
}
