#include <stdio.h>

#include "../common/InputReader.hpp"
#include "MovesParser.hpp"

using namespace Common;
using namespace Advent2015;

int main()
{
	char *line = NULL;
	while ((line = InputReader::ReadLine()) != NULL)
	{
		MovesParser parser;
		parser.parse(line);
		(void)printf("%d\n", parser.getNumHousesGifted());
	}
	return 0;
}
