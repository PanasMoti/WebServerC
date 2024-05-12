#ifndef HTTP_SERVER_H_
#define HTTP_SERVER_H_

typedef struct HTTP_Server {
    int socket;
    int port;
} HTTP_Server;

void init_server(HTTP_Server* http_server, int port);



#endif // HTTP_SERVER_H_