// Bonus content - why system is bad!
// This code is not something you're expected to understand by any means -
// I yoinked it from the COMP6447 course myself and modified it for this demo.
// The only relevant stuff is from line 65 to 74.

#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>

#define ON_READY "Ready to echo! "

#define MAX_LEN 4091

int write_socket(int socket, char *buf, int len) {
  int byteswrote = 0;

  while (byteswrote < len) {
    int ret = send(socket, buf + byteswrote, len - byteswrote, 0);

    if (ret < 0) {
      return -1;
    }

    if (!ret) {
      break;
    }

    byteswrote += ret;
  }

  return byteswrote;
}

int read_socket(int socket, char *buf, int len) {
  int bytesread = 0;

  while (bytesread < len) {
    int ret = recv(socket, buf + bytesread, len - bytesread, 0);

    if (ret < 0) {
      return -1;
    }

    if (!ret) {
      break;
    }

    bytesread += ret;
  }

  return bytesread;
}

int handle_conn(int socket) {
    char string[MAX_LEN + 5];

    write_socket(socket, ON_READY, sizeof(ON_READY));
    
    // Essentially, all this does is take a string received by the server,
    // stick the word echo in front of it, and run the command

    strcpy(string, "echo ");
    memset(&string[5], 0, MAX_LEN);
    read_socket(socket, &string[5], MAX_LEN);


    printf("I was told %s. Here you go:", string);
    system(string); 
}

int setup_networking(unsigned short port) {
    int sock = 0;
    struct sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        return -1;

    int opt = 1;

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bind(sock, (struct sockaddr *)&sin, sizeof(sin));
    listen(sock, 10);

    return sock;
}

void run_server(int socket) {
    int fd = 0;
    struct sockaddr_in client;
    socklen_t len = 0;

    memset((char *)&client, 0, sizeof(client));

    while (1) {
        fd = accept(socket, (struct sockaddr *)&client, &len);
        handle_conn(fd);
        close(fd);
    }
}

int main() {
    int sock;

    sock = setup_networking(1337);

    run_server(sock);

    exit(0);
}

