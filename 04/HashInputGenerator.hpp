//#include <map>

namespace Advent2015
{
	class HashInputGenerator
	{
	public:
		HashInputGenerator() :
			m_hashInputDecimal(1)
		{
		}

		void generate(char *input)
		{
			for (char *p = input; *p; ++p)
			{
			}
		}

		unsigned getHashInputDecimal()
		{
			return m_hashInputDecimal;
		}

	private:
		unsigned m_hashInputDecimal;
	};
}
