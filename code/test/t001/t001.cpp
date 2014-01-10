#include <json.h>
#include <yam.h>

#include <crtdbg.h>

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	using namespace yam;
	using namespace yam::base;
	using namespace yam::file;

	ystringhash ss;
	std::string key = YTOSTRING(yam);
	int rsa = ss(key);
	int rsb = ss("tt");
	int rsc = ss(key);

	// ready the data
	YCBuffer ybuffer;
	{
		YCBuffer* pBuffer0 = ybuffer.NewNext<YCBuffer>();
		ybuffer.GetId() = "buffertest";
		pBuffer0->GetId() = "buffertest0";

		YCFormat dformat;
		dformat.GetId() = "formattest";
		YRect2D stBound;
		stBound.Pos.X = 100;
		stBound.Pos.Y = 101;
		dformat.SetBoundAndColorData(stBound, YNULL);

		ybuffer.Begin();
		ybuffer << (const YIFormat*)&dformat;
		ybuffer.End();
	}

	// write buff
	{
		//
		YCUIFileWriter file;
		file.Save("test.aa");
		const YIBuffer* pBufferc = &ybuffer;
		file << pBufferc;
		file.Close();
	}

	// read buff
	{
		YCUIFileReader file;
		file.Open("test.aa");
		YIBuffer* pBuffer = YNULL;
		file >> pBuffer;
		file.Close();
		YIFormat* pFormat = YNULL;
		*pBuffer >> pFormat;
		if (YNULL != pFormat)
		{
			delete pFormat; pFormat = NULL;
		}
		delete pBuffer;
	}

	return 0;
}
