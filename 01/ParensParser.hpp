namespace Advent2015
{
	class ParensParser
	{
	public:
		ParensParser() :
			m_floor(0),
			m_positionFirstBasement(0)
		{
		}

		void parse(char *input)
		{
			m_floor = 0;
			for (char *p = input; *p; ++p)
			{
				if (*p == '(')
				{
					m_floor++;
				}
				else if (*p == ')')
				{
					m_floor--;
					if (-1 == m_floor && 0 == m_positionFirstBasement)
					{
						m_positionFirstBasement = p - input + 1;
					}
				}
			}
		}

		int getFloor()
		{
			return m_floor;
		}

		int getPositionFirstBasement()
		{
			return m_positionFirstBasement;
		}

	private:
		int m_floor;
		int m_positionFirstBasement;
	};
}
