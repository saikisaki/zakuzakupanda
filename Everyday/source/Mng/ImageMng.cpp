#include <string>
#include "DxLib.h"
#include "../common/VECTOR2.h"
#include "ImageMng.h"

ImageMng::ImageMng()
{
}

ImageMng::~ImageMng()
{
}

const VEC_INT& ImageMng::GetID(std::string f_name)
{
	if (imgMap.find(f_name) == imgMap.end())			// imgMap[f_name]が存在するかの判断	true:存在しない　false:存在する
	{
		imgMap[f_name].resize(1);						// imgMap[f_name]配列をﾘｻｲｽﾞする
		imgMap[f_name][0] = LoadGraph(f_name.c_str());	// imgMap[f_name][0]にﾌｧｲﾙ名f_nameの画像のﾊﾝﾄﾞﾙを代入
		if (imgMap[f_name][0] == -1)
		{
			throw;
		}
	}
	return imgMap[f_name];								// imgMap[f_name]を返す
}

const VEC_INT & ImageMng::GetID(std::string f_name, VECTOR2 divSize, VECTOR2 divCut)
{
	if (imgMap.find(f_name) == imgMap.end())
	{
		imgMap[f_name].resize(divCut.x*divCut.y);
		if (LoadDivGraph(f_name.c_str(),
			divCut.x*divCut.y,
			divCut.x, divCut.y,
			divSize.x, divSize.y,
			&imgMap[f_name][0]) == -1)
		{
			throw;
		}
	}
	return imgMap[f_name];
}