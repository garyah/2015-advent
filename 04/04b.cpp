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
		generator.generate(line, "000000");
		(void)printf("%u\n", generator.getHashInputDecimal());
		(void)fprintf(stderr, "%s\n", generator.getHashOutputString());
	}
	return 0;
}
