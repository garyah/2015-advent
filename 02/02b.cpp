#define MAX_LINE_SIZE 80000 + 1

#include <stdio.h>
#include <string.h>

#include "../common/InputReader.hpp"
#include "DimensionsParser.hpp"

using namespace Common;
using namespace Advent2015;

int main()
{
	DimensionsParser parser;

	char *line = NULL;
	while ((line = InputReader::ReadLine()) != NULL)
	{
		parser.addDimensions(line);
	}

	(void)printf("%d\n", parser.getTotalLengthRibbon());
	return 0;
}
