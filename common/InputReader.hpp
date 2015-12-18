#define MAX_LINE_SIZE 80000 + 1

#include <stdio.h>
#include <string.h>

namespace Common
{
	class InputReader
	{
	public:
		// No thread-safety in use of this method
		static char *ReadLine()
		{
			while (!feof(stdin) && !ferror(stdin))
			{
				s_line[0] = NULL;

				if (fgets(s_line, MAX_LINE_SIZE, stdin) == NULL)
				{
					if (ferror(stdin))
					{
						(void)fprintf(stderr, "error in input stream\n");
						return NULL;
					}
					else if (!feof(stdin))
					{
						(void)fprintf(stderr, "fgets() returned unexpected NULL\n");
						return NULL;
					}
				}
				if (s_line[0] == '\r' || s_line[0] == '\n')
				{
					// skip all blank lines
					continue;
				}
				size_t length = strlen(s_line);
				if (0 == length)
				{
					// normal case of end of file with last line delimited and already returned
					return NULL;
				}
				char *pEnd = s_line + length - 1;
				if (*pEnd == '\r' || *pEnd == '\n')
				{
					// remove delimiter(s) at end of line, if any
					*pEnd = 0;
				}

				// normal return of a line
				return s_line;
			}

			// catch any immediate detections of EOF or error
			return NULL;
		}

	private:
		InputReader()
		{
		}

		static char s_line[MAX_LINE_SIZE];
	};

	char InputReader::s_line[MAX_LINE_SIZE] = {0};
}
