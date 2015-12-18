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
			m_currentLocation(0, 0),
			m_locationMap()
		{
			locationEntry entry(m_currentLocation, true);
			(void)m_locationMap.insert(entry);
		}

		void parse(char *input)
		{
			for (char *p = input; *p; ++p)
			{
				location oldLocation = m_currentLocation;
				if (*p == '^')
				{	// up
					m_currentLocation.second++;
				}
				else if (*p == 'v')
				{	// down
					m_currentLocation.second--;
				}
				else if (*p == '>')
				{	// right
					m_currentLocation.first++;
				}
				else if (*p == '<')
				{	// left
					m_currentLocation.first--;
				}
				if (oldLocation != m_currentLocation)
				{
					locationEntry entry(m_currentLocation, true);
					(void)/* locationInsertResult result = */ m_locationMap.insert(entry);
				}
			}
		}

		std::size_t getNumHousesGifted()
		{
			return m_locationMap.size();
		}

	private:
		location m_currentLocation;
		locationMap m_locationMap;
	};
}
