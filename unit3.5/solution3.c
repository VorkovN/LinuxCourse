#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{

	int pid = atoi(argv[1]);
	int ppid = 0;

	printf("%d\n", pid);

	while (ppid != 1)
	{
		char cmd[50] = {};
		snprintf(cmd, sizeof(cmd), "cat /proc/%d/stat | awk '{print $4}'", pid);

		FILE *file = popen (cmd, "r");


		fscanf(file, "%d", &ppid);
		fclose(file);

		printf("%d\n", ppid);

		pid = ppid;
	}

	return 0;
}


