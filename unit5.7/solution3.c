#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int cmpstringp(const void *p1, const void *p2)
{
	return *(const char*)p2 > *(const char*)p1;
}


int main(int argc, char* argv[])
{
	struct sockaddr_in selfAddr;
	int listenSock = socket(AF_INET, SOCK_STREAM,0);
	inet_aton("127.0.0.1", &selfAddr.sin_addr);
	selfAddr.sin_port = htons(atoi(argv[1]));
	selfAddr.sin_family = AF_INET;

	bind(listenSock, (struct sockaddr*) &selfAddr, sizeof(selfAddr));
	listen(listenSock, 5);

	struct sockaddr peerAddr;
	socklen_t addrLength;
	int talkSock = accept(listenSock, &peerAddr, &addrLength);

	while (1)
	{
		char buf[BUFSIZ]={0};
		int bytesRecieved = recv(talkSock, buf, BUFSIZ, 0);
		if (!strcmp(buf, "OFF"))
			break;
		qsort(buf, strlen(buf), sizeof(char), cmpstringp);
		send(talkSock, buf, strlen(buf), 0);
	}

	close(listenSock);
	close(talkSock);


	return 0;
}
