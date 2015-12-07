#define MAX_LINE_SIZE 80000 + 1

#include <stdio.h>

int main()
{
	char line[MAX_LINE_SIZE] = {0};
	while (fgets(line, MAX_LINE_SIZE, stdin) != NULL
		   && line[0] != '\r'
		   && line[0] != '\n')
	{
		// TODO
		;
	}
	return 0;
}
