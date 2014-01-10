#include <json.h>
#include <yam.h>

#include <crtdbg.h>

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	using namespace yam;
	using namespace yam::base;
	using namespace yam::file;

	{
		ystringhash ss;
		std::string key = YTOSTRING(yam);
		int rsa = ss(key);
		int rsb = ss("tt");
		int rsc = ss(key);
	}

	{
		json::Object obj;
		obj["coin"] = 1.0f;
		obj["title"] = "hello world";
		std::string sRes = json::Serialize(obj);
	}

	// ready the data
	YCBuffer* pBuffer = new YCBuffer;
	{
		pBuffer->GetId() = "buffertest";
		pBuffer->Begin();

		{
			YIFormat* pFormat = new YCFormat;
			pFormat->GetId() = "formattest";
			YRect2D stBound;
			stBound.Pos.X = 100;
			stBound.Pos.Y = 101;
			pFormat->SetBoundAndColorData(stBound, YNULL);

			*pFormat >> *pBuffer;
			//*pBuffer << (const YIFormat*)pFormat;
			if (YNULL != pFormat)
			{
				delete pFormat; pFormat = NULL;
			}
		}

		pBuffer->End();

		YCBuffer* pBuffer0 = pBuffer->NewNext<YCBuffer>();
		pBuffer0->GetId() = "buffertest0";
	}

	// write buff
	{
		//
		YCUIFileWriter file;
		file.Save("test.aa");
		file << (const YIBuffer*)pBuffer;
		file.Close();
	}

	// read buff
	{
		YCUIFileReader file;
		file.Open("test.aa");
		YCBuffer* pBufferRead = YNULL;
		file >> (YIBuffer*&)pBufferRead;
		file.Close();
		YIFormat* pFormat = new YCFormat;
		*pFormat << *pBufferRead;
		//*pBufferRead >> pFormat;
		if (YNULL != pFormat)
		{
			delete pFormat; pFormat = NULL;
		}
		if (YNULL != pBufferRead)
		{
			delete pBufferRead; pBufferRead  = YNULL;
		}
	}
	delete pBuffer;

	return 0;
}
