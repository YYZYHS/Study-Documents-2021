#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("in pause function\n");
	pause();
	return 0;
}

