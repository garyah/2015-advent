#include <stdio.h>

#include "../common/InputReader.hpp"

using namespace Common;

int main()
{
	char *line = NULL;
	while ((line = InputReader::ReadLine()) != NULL)
	{
		// TODO: invoke class code here
		(void)printf("%s\n", line);
	}
	return 0;
}
