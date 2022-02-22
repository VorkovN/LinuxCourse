#include <stdio.h>

int main()
{
	int ppid = 0;

	char cmd[] = "ps -aux | grep genenv -c";

	FILE *file = popen (cmd, "r");

	fscanf(file, "%d", &ppid);
	fclose(file);

	printf("%d\n", ppid-2);
	return 0;
}


