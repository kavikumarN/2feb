#include <emscripten.h>
#include <emscripten/fetch.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

static const int PORT = 8080;

int EMSCRIPTEN_KEEPALIVE main(int argc, char const *argv[])
{
	int sock0;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	int len;
	int sock;

	
	sock0 = socket(AF_INET, SOCK_STREAM, 0); 

	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = INADDR_ANY;
	bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

	
	listen(sock0, 5); 
	while(true) {
		printf("Waiting... \n");

		sock = accept(sock0, (struct sockaddr *)&client, (socklen_t *)sizeof(client)); 
		write(sock, "HELLO", 5);

		printf("Accepted \n");
	}



	close(sock);

	close(sock0);

	return 0;
}
