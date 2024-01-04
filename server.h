#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

struct Server {
    int domain;
    int service;
    int port;
    int protocol;
    u_long interface;
    int backlog;

    struct sockaddr_in address;
    int socket;
    void (*launch)(struct Server *server);
};

struct Server server_constructor(int domain, int service, u_long interface, int port, int backlog, void (*launch)(struct Server *server));

void server_cleanup(struct Server *server);

#endif
