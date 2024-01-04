#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, u_long interface, int port, int backlog, void (*launch)(struct Server *server)) {
    struct Server server;
    
    server.domain = domain;
    server.service = service;
    server.protocol = 0; // Set a default value or whatever is appropriate
    server.backlog = backlog;
    server.interface = interface;
    server.port = port;

    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);

    server.socket = socket(domain, service, server.protocol);
    if (server.socket == 0) {
        printf("failed to connect ....\n");
        exit(1);
    }

    if (bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address)) < 0) {
        printf("failed to bind the socket ..../n");
        exit(1);
    }

    if (listen(server.socket, server.backlog) < 0) {
        printf("listening error ..../n");
        exit(0);
    }

    server.launch = launch;
    return server;
}
