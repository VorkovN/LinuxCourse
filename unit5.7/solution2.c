#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
	int sock = socket(AF_INET, SOCK_DGRAM,0);
	struct sockaddr_in addr;
	inet_aton("127.0.0.1", &addr.sin_addr);
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_family = AF_INET;
	bind(sock, (struct sockaddr*) &addr, sizeof(addr));


	while (1)
	{
		char buf[BUFSIZ]={0};
		int bytesRecieved = recv(sock, buf, BUFSIZ, 0);
		if (!strcmp(buf, "OFF\n"))
			break;
		printf("%s\n", buf);
	}


	return 0;
}
