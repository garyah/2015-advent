#include <stdio.h>

#include "../common/InputReader.hpp"
#include "HashInputGenerator.hpp"

using namespace Common;
using namespace Advent2015;

int main()
{
	char *line = NULL;
	while ((line = InputReader::ReadLine()) != NULL)
	{
		HashInputGenerator generator;
		generator.generate(line);
		(void)printf("%u\n", generator.getHashInputDecimal());
	}
	return 0;
}
