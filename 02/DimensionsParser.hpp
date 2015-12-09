#include <stdio.h>

#define MIN(a, b) ((a) <= (b) ? (a) : (b))

namespace Advent2015
{
	class DimensionsParser
	{
	public:
		DimensionsParser() :
			m_totalArea(0)
		{
		}

		void addDimensions(char *input)
		{
			int l = 0, w = 0, h = 0;
			if (sscanf(input, "%d x %d x %d", &l, &w, &h) == 3)
			{
				int lw = l * w;
				int wh = w * h;
				int hl = h * l;
				int area = 2 * lw + 2 * wh + 2 * hl;
				int slack = MIN(MIN(lw, wh), hl);
				m_totalArea += area + slack;
			}
		}

		int getTotalArea()
		{
			return m_totalArea;
		}

	private:
		int m_totalArea;
	};
}
