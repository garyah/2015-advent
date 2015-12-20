#include <stdio.h>

#include "../common/InputReader.hpp"
#include "NiceCounter.hpp"

using namespace Common;
using namespace Advent2015;

int main()
{
	NiceCounter counter;

	char *line = NULL;
	while ((line = InputReader::ReadLine()) != NULL)
	{
		counter.addStringWithNewRules(line);
	}

	(void)printf("%u\n", counter.getNiceCount());
	return 0;
}
