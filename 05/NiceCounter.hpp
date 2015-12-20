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

			// string with at least 3 of any vowel can be nice
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

			// string with a doubled letter can be nice
			bool hasDoubles = false;
			for (int i = 0; i < string.length() - 1; ++i)
			{
				if (string[i] == string[i + 1])
				{
					hasDoubles = true;
				}
			}

			// string without certain letter combinations can be nice
			bool hasNoBadSubstrings = false;
			if (string.find("ab") == std::string::npos
				&& string.find("cd") == std::string::npos
				&& string.find("pq") == std::string::npos
				&& string.find("xy") == std::string::npos)
			{
				hasNoBadSubstrings = true;
			}

			if (vowelScore >= 3 && hasDoubles && hasNoBadSubstrings)
			{
				// all criteria met
				m_niceCount++;
			}
		}

		void addStringWithNewRules(char *cString)
		{
			std::string string(cString);

			// string with a doubled pair of letters can be nice
			bool hasDoubledPairs = false;
			for (int i = 0; i < string.length() - 3; ++i)
			{
				for (int j = i + 2; j < string.length() - 1; ++j)
				{
					if (string[i] == string[j]
						&& string[i + 1] == string[j + 1])
					{
						hasDoubledPairs = true;
					}
				}
			}

			// string with a doubled letter interleaved by another can be nice
			bool hasInterleavedDoubles = false;
			for (int i = 0; i < string.length() - 2; ++i)
			{
				if (string[i] == string[i + 2])
				{
					hasInterleavedDoubles = true;
				}
			}

			if (hasDoubledPairs && hasInterleavedDoubles)
			{
				// all criteria met
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
