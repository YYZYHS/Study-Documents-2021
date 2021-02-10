
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("USER=%s\n",getenv("USER"));
	printf("GONGSI=%s\n",getenv("GONGSI"));
	return 0;
}












