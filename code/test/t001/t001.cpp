#include <json.h>
#include <yam.h>

#include <crtdbg.h>

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	using namespace yam;
	using namespace yam::base;
	using namespace yam::storage;
	using namespace yam::util;

	{
		YCFileReader file;
		file.Open("test.yui");
		YCBuffer buffer;
		file >> buffer;
		file.Close();
		YCTree treedata;
		treedata << buffer;
		YITree* pFind = treedata.Find("0");
		treedata.GetId();
	}

	{
		yvvec2d vSizeList;
		vSizeList.push_back(YVec2D(7, 2));
		vSizeList.push_back(YVec2D(5, 15));
		vSizeList.push_back(YVec2D(8, 3));
		vSizeList.push_back(YVec2D(11, 6));
		YRect2D stFinal;
		yvrect rvDetail;
		YCMerge::Instance().Do(vSizeList, stFinal, rvDetail);
		rvDetail.clear();
	}

	// read buff
	{
		YCFileReader file;
		file.Open("test.yui");
		YCBuffer buffer;
		file >> buffer;
		file.Close();
		//YCFormat format0;
		//format0 << buffer;
		//format0.GetId();
		YCTree treedata;
		treedata << buffer;
		treedata.GetId();
	}

	{
		ybuff iColorElem = 0xAB;
		ycolor iColorData = 0x12345678;
		yint32 iOffset = 0x10 / (sizeof(ybuff) * YBITCOUNT_INT8);
		*((ybuff*)&iColorData + iOffset) = iColorElem;
		iColorData = 0;
	}

	{
		ystringhash ss;
		std::string key = YTOSTRING(yam);
		yint32 rsa = ss(key);
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
	{
		YCTree treedata;
		YCFormat * pFormat0 = treedata.NewChild<YCFormat>();

		pFormat0->GetId() = "pFormat0";
		YRect2D stBound;
		stBound.Pos.X = 100;
		stBound.Pos.Y = 101;
		stBound.Size.X = 0;
		stBound.Size.Y = 0;
		ysize iSize = stBound.Size.X * stBound.Size.Y;
		ycolorptr pColorData = YNULL;
		if (0 < iSize)
		{
			pColorData = new ycolor[iSize];
			ycolor defaultcolor = 0x01020304;
			MemSet((const ybuffptr)pColorData, sizeof(ycolor) * iSize, (const ybuffptr)&defaultcolor, sizeof(ycolor));
		}
		pFormat0->SetBoundAndColorData(stBound, pColorData);
		if (YNULL != pColorData)
		{
			delete[] pColorData;
		}

		YCFormat* pFormat0Next0 = pFormat0->NewNext<YCFormat>();
		pFormat0Next0->GetId() = "format0next0";
		stBound.Size.X = 0;
		stBound.Size.Y = 0;
		pFormat0Next0->SetBoundAndColorData(stBound, YNULL);

		YCFormat* pFormat0Next1 = pFormat0->NewNext<YCFormat>();
		pFormat0Next1->GetId() = "format0next1";
		stBound.Pos.X = 10;
		pFormat0Next1->SetBoundAndColorData(stBound, YNULL);

		YCFormat* pFormat0Child0 = pFormat0->NewChild<YCFormat>();
		pFormat0Child0->GetId() = "format0child0";
		stBound.Pos.X = 11;
		pFormat0Child0->SetBoundAndColorData(stBound, YNULL);

		YCFormat* pFormat0Child1 = pFormat0->NewChild<YCFormat>();
		pFormat0Child1->GetId() = "format0child1";
		stBound.Pos.X = 11;
		pFormat0Child1->SetBoundAndColorData(stBound, YNULL);

		YCWidget* pWidget0 = treedata.NewChild<YCWidget>();
		pWidget0->GetId() = "pWidget0";
		pWidget0->GetBound().Pos.Y = 1025;


		YCBuffer buffer;
		buffer.GetId() = "buffer0";
		buffer.Begin();
		//*pFormat0 >> buffer;
		treedata >> buffer;
		buffer.End();

		//
		YCFileWriter file;
		file.Save("test.aa");
		file << buffer;
		file.Close();
	}

	// read buff
	{
		YCFileReader file;
		file.Open("test.aa");
		YCBuffer buffer;
		file >> buffer;
		file.Close();
		//YCFormat format0;
		//format0 << buffer;
		//format0.GetId();
		YCTree treedata;
		treedata << buffer;
		treedata.GetId();
	}

	return 0;
}
