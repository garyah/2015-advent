namespace Advent2015
{
	class MovesParser
	{
	public:
		MovesParser() :
			m_numHousesGifted(0)
		{
		}

		void parse(char *input)
		{
			m_numHousesGifted = 0;
			for (char *p = input; *p; ++p)
			{
				if (*p == '^')
				{
				}
				else if (*p == 'v')
				{
				}
				else if (*p == '>')
				{
				}
				else if (*p == '<')
				{
				}
			}
		}

		int getNumHousesGifted()
		{
			return m_numHousesGifted;
		}

	private:
		int m_numHousesGifted;
	};
}
