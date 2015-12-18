#include <map>

typedef std::pair<int, int> location;
typedef std::pair<location, bool> locationEntry;
//typedef std::pair<std::iterator<std::input_iterator_tag, locationEntry>, bool> locationInsertResult;
typedef std::map<location, bool> locationMap;

namespace Advent2015
{
	class MovesParser
	{
	public:
		MovesParser() :
			m_currentLocation1(0, 0),
			m_currentLocation2(0, 0),
			m_locationMap()
		{
			locationEntry entry(m_currentLocation1, true);
			(void)m_locationMap.insert(entry);
		}

		void parse(char *input)
		{
			location *currentLocation = &m_currentLocation1;
			for (char *p = input; *p; ++p)
			{
				location oldLocation = *currentLocation;
				if (*p == '^')
				{	// up
					(*currentLocation).second++;
				}
				else if (*p == 'v')
				{	// down
					(*currentLocation).second--;
				}
				else if (*p == '>')
				{	// right
					(*currentLocation).first++;
				}
				else if (*p == '<')
				{	// left
					(*currentLocation).first--;
				}
				if (oldLocation != *currentLocation)
				{
					locationEntry entry((*currentLocation), true);
					(void)/* locationInsertResult result = */ m_locationMap.insert(entry);
				}

				if (currentLocation == &m_currentLocation1)
				{
					currentLocation = &m_currentLocation2;
				}
				else
				{
					currentLocation = &m_currentLocation1;
				}
			}
		}

		std::size_t getNumHousesGifted()
		{
			return m_locationMap.size();
		}

	private:
		location m_currentLocation1;
		location m_currentLocation2;
		locationMap m_locationMap;
	};
}
