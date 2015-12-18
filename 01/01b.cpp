#include <stdio.h>

#include "../common/InputReader.hpp"
#include "ParensParser.hpp"

using namespace Common;
using namespace Advent2015;

int main()
{
	char *line = NULL;
	while ((line = InputReader::ReadLine()) != NULL)
	{
		ParensParser parser;
		parser.parse(line);
		(void)printf("%d\n", parser.getPositionFirstBasement());
	}
	return 0;
}
