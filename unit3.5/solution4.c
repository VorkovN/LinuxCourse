#include <stdio.h>
#include <stdlib.h>

static int counter = -1;

void findChild(int ppid)
{
	++counter;
	char cmd[50] = {};
	snprintf(cmd, sizeof(cmd), "cat /proc/%d/task/%d/children", ppid, ppid);
	FILE *file = popen (cmd, "r");

	int pid;
	while (fscanf(file, "%d", &pid) != EOF && pid!= 0)
		findChild(pid);

}

int main(int argc, char* argv[])
{
	int ppid = atoi(argv[1]);

	findChild(ppid);

	printf("%d\n", counter+1);

	return 0;
}

//int main(int argc, char* argv[])
//{
//	int pid = atoi(argv[1]);
//	int count = 0;
//	char cmd[50];
//	snprintf(cmd, sizeof(cmd), "ps -ao pid= --ppid %d | wc -w", pid);
//
//	FILE *file = popen (cmd, "r");
//
//	fscanf(file, "%d", &count);
//	fclose(file);
//
//	printf("%d\n", count);
//
//	return 0;
//}


