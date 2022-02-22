#include <stdio.h>
#include <sys/select.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>


static int counter = 0;

bool read_and_count(int fd)
{
	char buf[100];
	int bytes = read(fd, buf, 100);
//	printf("bytes: %d\n", bytes);
	if (bytes == 0)
		return false;

	counter += atoi(buf);
//	printf("counter: %d\n", counter);
	buf[bytes] = 0;

	return true;
}

int main(int argc, char* argv[])
{
	int f1 = open("./in1", O_RDONLY | O_NONBLOCK);
	int f2 = open("./in2", O_RDONLY | O_NONBLOCK);

	fd_set read_set;


	while (true) {
		bool res1 = false, res2 = false;
		FD_ZERO(&read_set);
		FD_SET(f1, &read_set);
		FD_SET(f2, &read_set);

		struct timeval timeout;
		timeout.tv_usec = 1;

		int result = select(f2 + 1, &read_set, NULL, NULL, NULL);

		if (result) {
			if (FD_ISSET(f1, &read_set))
				res1 = read_and_count(f1);

			if (FD_ISSET(f2, &read_set))
				res2 = read_and_count(f2);
		}

		FD_CLR(f1, &read_set);
		FD_CLR(f2, &read_set);

		if (!res1 && !res2)
			break;
	}

	printf("%d\n", counter);

	return 0;
}
