#include <stdio.h>

int main(int argc, char* argv[])
{
	char cmd[50] = {};
	snprintf(cmd, sizeof(cmd), "./%s %s", argv[1], argv[2]);

	FILE *file = popen (cmd, "r");

	int counter = 0;
	char ch = 0;
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '0')
			++counter;
	}


	printf("%d\n", counter);

	fclose(file);
	return 0;
}
