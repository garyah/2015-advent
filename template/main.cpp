#define MAX_LINE_SIZE 80000 + 1

#include <stdio.h>
#include <string.h>

//using namespace Advent2015;

int main()
{
	char line[MAX_LINE_SIZE] = {0};
	while (!feof(stdin)
		   && (fgets(line, MAX_LINE_SIZE, stdin) != NULL
		       || feof(stdin)))
	{
		if (line[0] == '\r' || line[0] == '\n')
		{
			continue;
		}
		char *pEnd = line + strlen(line) - 1;
		if (*pEnd == '\r' || *pEnd == '\n')
		{
			*pEnd = 0;
		}

		// TODO: invoke class code here
		(void)printf("%s\n", line);
	}
	return 0;
}
