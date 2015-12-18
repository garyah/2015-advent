#include <string.h>
#include <openssl/md5.h>

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
			unsigned char md[16 + 1] = {0};
			(void)MD5((const unsigned char *)input, strlen(input), md);
		}

		unsigned getHashInputDecimal()
		{
			return m_hashInputDecimal;
		}

	private:
		unsigned m_hashInputDecimal;
	};
}
