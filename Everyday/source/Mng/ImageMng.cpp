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
	if (imgMap.find(key) == imgMap.end())			// imgMap[f_name]が存在するかの判断	true:存在しない　false:存在する
	{
		imgMap[key].resize(1);						// imgMap[f_name]配列をﾘｻｲｽﾞする
		imgMap[key][0] = LoadGraph(f_name.c_str());	// imgMap[f_name][0]にﾌｧｲﾙ名f_nameの画像のﾊﾝﾄﾞﾙを代入
		if (imgMap[key][0] == -1)
		{
			throw;
		}
	}
	return imgMap[key];								// imgMap[f_name]を返す
}

const VEC_INT& ImageMng::GetID(const std::string& key, const std::string& f_name,const VECTOR2& divSize,const VECTOR2& divCut)
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