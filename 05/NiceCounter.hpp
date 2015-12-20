#include <stdio.h>

#include <string>

namespace Advent2015
{
	class NiceCounter
	{
	public:
		NiceCounter() :
			m_niceCount(0)
		{
		}

		void addString(char *cString)
		{
			std::string string(cString);

			char vowels[] = "aeiou";
			unsigned vowelScore = 0;
			for (int i = 0; i < sizeof(vowels); ++i)
			{
				for (int j = 0; j < string.length(); ++j)
				{
					if (string[j] == vowels[i])
					{
						vowelScore++;
					}
				}
			}

			if (vowelScore >= 3)
			{
				m_niceCount++;
			}
		}

		unsigned getNiceCount()
		{
			return m_niceCount;
		}

	private:
		unsigned m_niceCount;
	};
}
