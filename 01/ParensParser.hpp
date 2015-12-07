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
				result++;
			}
			return result;
		}
	};
}
