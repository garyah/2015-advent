#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

#include <string>

namespace Advent2015
{
	class HashInputGenerator
	{
	public:
		HashInputGenerator() :
			m_hashInputDecimal(1),
			m_mdString()
		{
		}

		void generate(char *secretKey)
		{
			for (unsigned hashInputDecimal = 1; ; ++hashInputDecimal)
			{
				char hashInput[1000 + 1] = {0};
				unsigned char md[MD5_DIGEST_LENGTH] = {0};
				char mdCString[MD5_DIGEST_LENGTH * 2 + 1] = {0};

				(void)snprintf(hashInput, sizeof(hashInput), "%s%u", secretKey, hashInputDecimal);
				(void)MD5((const unsigned char *)hashInput, strlen(hashInput), md);
				hashOutputToString(md, mdCString);

				std::string mdString(mdCString);
				std::string prefix("00000");
				if (mdString.compare(0, prefix.length(), prefix) == 0)
				{
					// the hash output has the required prefix, squirrel away values and return
					m_hashInputDecimal = hashInputDecimal;
					m_mdString = mdString;
					return;
				}
			}
		}

		unsigned getHashInputDecimal() const
		{
			return m_hashInputDecimal;
		}

		const char *getHashOutputString() const
		{
			return m_mdString.c_str();
		}

	private:
		void hashOutputToString(unsigned char *md, char *mdString)
		{
			char *outPtr = mdString;
			for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
			{
				(void)sprintf(outPtr, "%02x", md[i]);
				outPtr += 2;
			}
		}

	private:
		unsigned m_hashInputDecimal;
		std::string m_mdString;
	};
}
