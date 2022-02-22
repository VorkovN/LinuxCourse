#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("%d\n", getpid());
	daemon(0,0);
	sleep(100);
	return 0;
}
