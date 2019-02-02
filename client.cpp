#include <emscripten.h>
#include <emscripten/fetch.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


static const int PORT = 8080;
static const char* IP = "127.0.0.1";

int EMSCRIPTEN_KEEPALIVE main(int argc, char const *argv[])
{
	struct sockaddr_in server;
	int sock;
	char buf[32];
	int n;

	
	sock = socket(AF_INET, SOCK_STREAM, 0);

	
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	inet_pton(AF_INET, IP, &server.sin_addr.s_addr);

	connect(sock, (struct sockaddr *)&server, sizeof(server));


	memset(buf, 0, sizeof(buf)); 
	n = read(sock, buf, sizeof(buf));


	printf("%d, %s\n", n, buf);


	close(sock);

	return 0;
}
