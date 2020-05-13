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
	static ImageMng &GetInstance(void)			// ���̸׽���߲�����擾����A�����żݸ���݂̏�Ԃɂ��Ă���
	{
		static ImageMng s_Instance;
		return s_Instance;
	}

	const VEC_INT& GetID(std::string f_name);										// �摜������ق��Q�Ƃ��邽�߂̊֐� ( LoadGraph�p )
	const VEC_INT& GetID(std::string f_name, VECTOR2 divSize, VECTOR2 divCut);		// �摜������ق��Q�Ƃ��邽�߂̊֐� ( LoadDivGraph�p )

private:
	ImageMng();
	~ImageMng();

	std::map<std::string, VEC_INT> imgMap;			//�摜������ق��i�[���邽�߂�map
};
