#include "server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

void launch(struct Server *server){
    printf("=======WAITING=========");
    char buffer[30000];
    socklen_t address_length = sizeof(server->address);
    int new_socket = accept(server->socket, (struct sockaddr *)&server->address, &address_length);
    read(new_socket, buffer, sizeof(buffer));
    printf("%s\n", buffer);
    char *hello = "HTTP/1.1 200 OK\nDate: Fri, 5 Jan 2024 1:30:22 GMT\nServer: Apache/2.2.14 (Win32)\nLast-modified 2024, 1:30:22 GMT\nContent-Length: 88\nContent-Type: text/html\nConnection: Closed\n<html>Bhai_so_ja<body><h1><h1><body><html>";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

int main(){
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 80, INADDR_ANY, 10, launch);
    server.launch(&server);
    return 0;
}
