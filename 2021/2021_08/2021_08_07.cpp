#include <stdio.h>
#include <string.h>
#define PRAISE "You are an extraordinary being."

int main()
{
	char name[40];
	printf("What's your name?\n");
	gets_s(name);
	printf("Hello, %s.%s\n", name, PRAISE);
	return 0;
}
