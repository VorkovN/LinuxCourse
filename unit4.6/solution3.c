#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>


static int usr1 = 0;
static int usr2 = 0;

void sigusr1_handler(int sig)
{
	++usr1;
}

void sigusr2_handler(int sig)
{
	++usr2;
}

void sigterm_handler(int sig)
{
	printf("%d %d\n", usr1, usr2);
	exit(0);
}

int main(int argc, char* argv[])
{
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	signal(SIGTERM, sigterm_handler);

	while (true)
	{
		sleep(1000);
	}

	return 0;
}
