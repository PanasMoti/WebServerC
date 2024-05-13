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
#include "route.h"
#include <errno.h>



#define BUF_SIZE 1024


int main(int argc, char** argv) {



    char root[BUF_SIZE];
    log_args(argc, argv);
    // getting the root directory
    get_root_directory(argv[0], root);
    

    HTTP_Server http_server;
    init_server(&http_server, 8001);


    struct route *route = route_create("/", "index.html");
    route_insert(route, "/about", "about.html");
    route_insert(route, "/info", "about.html");
    route_insert(route, "/wheretogetme", "about.html");

    
    int client_socket;
    while (1) {
        char client_msg[4096];
        client_socket = accept(http_server.socket, NULL, NULL);
        read(client_socket, client_msg, 4095);
        
        // parsing client socket header to get HTTP method, route
		char *method = "";
		char *urlRoute = "";

		char *client_http_header = strtok(client_msg, "\n");
			
		printf("\n\n%s\n\n", client_http_header);

		char *header_token = strtok(client_http_header, " ");
		
		int header_parse_counter = 0;

		while (header_token != NULL) {

			switch (header_parse_counter) {
				case 0:
					method = header_token;
				case 1:
					urlRoute = header_token;
			}
			header_token = strtok(NULL, " ");
			header_parse_counter++;
		}

		printf("The method is %s\n", method);
		printf("The route is %s\n", urlRoute);

        char template[100];
        strcpy(template, root);

        if(strstr(urlRoute, "/static/") != NULL) {
            printf("template is %s\n", template);
            strcat(template, urlRoute);
        } else {
            strcat(template, "/pages/");
            struct route* dest = route_search(route, urlRoute);
            
            if(dest == NULL) {
                strcat(template, "404.html");
            } else {
                strcat(template, dest->value);
            }    
        }

        

        char* response_data = read_file(template);
        char http_request[32384] = "HTTP/1.1 200 OK\r\n\r\n";
		strcat(http_request, response_data);
		strcat(http_request, "\r\n\r\n\0");


        send(client_socket, http_request, sizeof(http_request), 0);
        close(client_socket);
        free(response_data);
    }

    return 0;
}