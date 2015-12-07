namespace Advent2015
{
	class ParensParser
	{
	public:
		int parse(char *input)
		{
			int result = 0;
			for (char *p = input; *p; ++p)
			{
				if (*p == '(')
				{
					result++;
				}
				else if (*p == ')')
				{
					result--;
				}
			}
			return result;
		}
	};
}
