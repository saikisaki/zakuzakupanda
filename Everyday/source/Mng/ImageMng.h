#pragma once
#include<map>
#include<vector>

class VECTOR2;

using VEC_INT = std::vector<int>;

#define lpImageMng ImageMng::GetInstance()
#define IMAGE_ID(X) (ImageMng::GetInstance().GetID(X))
#define IMAGE_DIV_ID(X,Y,Z) (ImageMng::GetInstance().GetID(X,Y,Z))

class ImageMng
{
public:
	static ImageMng &GetInstance(void)			// このｸﾗｽのﾎﾟｲﾝﾀを取得する、ここでｼﾝｸﾞﾙﾄﾝの状態にしている
	{
		static ImageMng s_Instance;
		return s_Instance;
	}

	const VEC_INT& GetID(const std::string& key);
	const VEC_INT& GetID(const std::string& key, const std::string& fileName);									// 画像のﾊﾝﾄﾞﾙを参照するための関数 ( LoadGraph用 )
	const VEC_INT& GetID(const std::string& key, const std::string& fileName,const VECTOR2& divSize,const VECTOR2& divCut);		// 画像のﾊﾝﾄﾞﾙを参照するための関数 ( LoadDivGraph用 )

private:
	ImageMng();
	~ImageMng();

	std::map<std::string, VEC_INT> imgMap;			//画像のﾊﾝﾄﾞﾙを格納するためのmap
};
