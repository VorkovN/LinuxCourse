#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


static int usr1 = 0;
static int usr2 = 0;

void sigurg_handler(int sig)
{
	printf("%d\n", getpid());
	exit(0);
}

int main(int argc, char* argv[])
{
	signal(SIGURG, sigurg_handler);
	daemon(0,0);
	sleep(100);
	return 0;
}
