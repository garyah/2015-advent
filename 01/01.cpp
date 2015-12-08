#define MAX_LINE_SIZE 80000 + 1

#include <stdio.h>
#include <string.h>

#include "ParensParser.hpp"

using namespace Advent2015;

int main()
{
	while (!feof(stdin) && !ferror(stdin))
	{
		char line[MAX_LINE_SIZE] = {0};
		if (fgets(line, MAX_LINE_SIZE, stdin) == NULL)
		{
			if (ferror(stdin))
			{
				(void)fprintf(stderr, "error in input stream\n");
				break;
			}
			else if (!feof(stdin))
			{
				(void)fprintf(stderr, "fgets() returned unexpected NULL\n");
				break;
			}
		}
		if (line[0] == '\r' || line[0] == '\n')
		{
			// skip all blank lines
			continue;
		}
		size_t length = strlen(line);
		if (0 == length)
		{
			// normal case of end of file with last line delimited
			break;
		}
		char *pEnd = line + length - 1;
		if (*pEnd == '\r' || *pEnd == '\n')
		{
			// remove delimiter(s) at end of line, if any
			*pEnd = 0;
		}

		ParensParser parser;
		int result = parser.parse(line);
		(void)printf("%d\n", result);
	}
	return 0;
}
