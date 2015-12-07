#define MAX_LINE_SIZE 80000 + 1

#include <stdio.h>

#include "ParensParser.hpp"

using namespace Advent2015;

int main()
{
	char line[MAX_LINE_SIZE] = {0};
	while (fgets(line, MAX_LINE_SIZE, stdin) != NULL
		   && line[0] != '\r'
		   && line[0] != '\n')
	{
		// TODO
		ParensParser parser;
		int result = parser.parse(line);
		(void)printf("%d\n", result);
	}
	return 0;
}
