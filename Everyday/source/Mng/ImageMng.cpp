#include <string>
#include <DxLib.h>
#include "../common/VECTOR2.h"
#include "ImageMng.h"

ImageMng::ImageMng()
{
}

ImageMng::~ImageMng()
{
}

const VEC_INT& ImageMng::GetID(const std::string & key)
{
	GetID(key, key);
	return imgMap[key];
}


const VEC_INT& ImageMng::GetID(const std::string& key, const std::string& f_name)
{
	if (imgMap.find(key) == imgMap.end())			// imgMap[f_name]‚ª‘¶İ‚·‚é‚©‚Ì”»’f	true:‘¶İ‚µ‚È‚¢@false:‘¶İ‚·‚é
	{
		imgMap[key].resize(1);						// imgMap[f_name]”z—ñ‚ğØ»²½Ş‚·‚é
		imgMap[key][0] = LoadGraph(f_name.c_str());	// imgMap[f_name][0]‚ÉÌ§²Ù–¼f_name‚Ì‰æ‘œ‚ÌÊİÄŞÙ‚ğ‘ã“ü
		if (imgMap[key][0] == -1)
		{
			throw;
		}
	}
	return imgMap[key];								// imgMap[f_name]‚ğ•Ô‚·
}

const VEC_INT& ImageMng::GetID(const std::string& key, const std::string& f_name, VECTOR2 divSize, VECTOR2 divCut)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(divCut.x*divCut.y);
		if (LoadDivGraph(f_name.c_str(),
			divCut.x*divCut.y,
			divCut.x, divCut.y,
			divSize.x, divSize.y,
			&imgMap[key][0]) == -1)
		{
			throw;
		}
	}
	return imgMap[key];
}