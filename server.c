#include <server.h>

struct Server server_contructor(int domain , int protocol , int port , u_long interface, int backlog , int service void(*launch)(void))
{
    struct Server server ;
    server.domain = domain ;
    server.service = service;
    server.protocol = protocol;
    server.backlog = backlog;
    server.interface = interface;
    server.port = port;

    server.address.sin_family = domain;
    server.address.sin_port =htons(port);
    server.address.sin_addr.sin_addr= htonl(interface);

    server.socket = socket(domain, service, protocol);
    
    return server;


}