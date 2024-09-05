// Fadli Shidqi Firdaus
// 21120122140166

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, n = 0;
    char recvline[1000 + 1];
    struct sockaddr_in servaddr;
    int port = atoi(argv[2]);

    printf("Nama: Fadli Shidqi Firdaus - 21120122140166\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    while ((n = read(sockfd, recvline, 1000)) > 0) {
        recvline[n] = 0;
        fputs(recvline, stdout);
    }

    close(sockfd);
    return 0;
}
