#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid = getpid();
	int ppid = 0;

	char cmd[50] = {};
	snprintf(cmd, sizeof(cmd), "cat /proc/%d/stat | awk '{print $4}'",pid );

	FILE *file = popen (cmd, "r");

	fscanf(file, "%d", &ppid);
	fclose(file);

	printf("%d\n", ppid);
	return 0;
}


