#include <stdio.h>
#include <getopt.h>

int main(int argc, char* argv[])
{
	extern int opterr;
	opterr = 0;
	int opindex = 0;
	const char* optstring = "q:iv";
	struct option long_opts[] = {
		{"query", required_argument, 0, 'q'},
		{"longinformationrequest",  no_argument, 0, 'i'},
		{"version", no_argument, 0, 'v'},
		{0, 0, 0, 0}
	};

	int c = 0;
	while (-1 != (c = getopt_long(argc, argv, optstring, long_opts, &opindex)))
	{
		switch (c)
		{
			case 'q':

				break;
			case 'i':

				break;
			case 'v':

				break;
			default:
				printf("-\n");
				return 0;
		}

	}
	printf("+\n");
	return 0;
}
