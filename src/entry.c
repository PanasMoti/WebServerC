#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "args.h"
#include "http_server.h"
#include "file_utils.h"
#include <errno.h>



#define BUF_SIZE 1024


int main(int argc, char** argv) {
    char root[BUF_SIZE];
    log_args(argc, argv);
    // getting the root directory
    get_root_directory(argv[0], root);
    
    // open a file to serve
    char index_html[BUF_SIZE];
    strcpy(index_html, root); // <- important that this is strcpy and NOT strcat because zero terminated string bullshit
    strcat(index_html, "/pages/index.html\0");

    FILE* html_data = fopen(index_html, "r");
    char response_data[BUF_SIZE];
    fgets(response_data, BUF_SIZE, html_data);
    printf("%s\n",response_data);
    
    char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
    strcat(http_header, response_data);

    HTTP_Server http_server;
    init_server(&http_server, 8001);

    int client_socket;
    while (1) {
        client_socket = accept(http_server.socket, NULL, NULL);
        send(client_socket, http_header, sizeof(http_header), 0);
        close(client_socket);
    }

    return 0;
}