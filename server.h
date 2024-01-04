#ifndef server.h
#define server.h

# include <sys/socket.h>
#include <netinet/in.h>
struct Server
{
    int domain ;
    int service;
    int port;
    int protocol
    u_long interface;
    int backlog;
    
    struct sockaddr_in address;
    int socket;
    void (*launch)(void);
};

struct Server server_constructor (int domain m int service , u_long interface m int port, int backlog, void(*launch)(void)); 

#endif