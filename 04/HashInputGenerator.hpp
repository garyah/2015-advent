#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

namespace Advent2015
{
	class HashInputGenerator
	{
	public:
		HashInputGenerator() :
			m_hashInputDecimal(1),
			m_md(),
			m_mdString()
		{
		}

		void generate(char *input)
		{
			(void)MD5((const unsigned char *)input, strlen(input), m_md);
		}

		unsigned getHashInputDecimal()
		{
			return m_hashInputDecimal;
		}

		char *getHashOutputString()
		{
			// string version of hash computed here, rather than with hash itself
			char *outPtr = m_mdString;
			for (int i = 0; i < 16; ++i)
			{
				(void)sprintf(outPtr, "%02x", m_md[i]);
				outPtr += 2;
			}
			return m_mdString;
		}

	private:
		unsigned m_hashInputDecimal;
		unsigned char m_md[16];
		char m_mdString[16 * 2 + 1];
	};
}
