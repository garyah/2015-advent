#include <stdio.h>

#define MIN(a, b) ((a) <= (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

namespace Advent2015
{
	class DimensionsParser
	{
	public:
		DimensionsParser() :
			m_totalAreaPaper(0),
			m_totalLengthRibbon(0)
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
				m_totalAreaPaper += area + slack;

				int loDimension = MIN(MIN(l, w), h);
				int hiDimension = MAX(MAX(l, w), h);
				int sumDimensions = l + w + h;
				int midDimension = sumDimensions - (loDimension + hiDimension);
				int presentLength = 2 * loDimension + 2 * midDimension;
				int bowLength = l * w * h;
				m_totalLengthRibbon += presentLength + bowLength;
			}
		}

		int getTotalAreaPaper()
		{
			return m_totalAreaPaper;
		}

		int getTotalLengthRibbon()
		{
			return m_totalLengthRibbon;
		}

	private:
		int m_totalAreaPaper;
		int m_totalLengthRibbon;
	};
}
