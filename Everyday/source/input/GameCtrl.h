#pragma once
#include <array>

enum BUTTON_TYPE
{
	// �ړ�����
	UP,			// ��
	DOWN,		// ��
	RIGHT,		// �E
	LEFT,		// ��

	// ����
	BOMB,

	// ����{�^��
	ENTER,

	BUTTON_TYPE_MAX
};

using KEY_ARRAY = std::array<char, 256>;
using INPUT_ARRAY = std::array<bool, BUTTON_TYPE_MAX>;

enum KEY_TYPE
{
	KEY_TYPE_NOW,
	KEY_TYPE_OLD,
	KEY_TYPE_MAX
};

class GameCtrl
{
public:
	GameCtrl();
	~GameCtrl();

	bool GetPadData(BUTTON_TYPE button) const;
	bool GetPadDataTrg(BUTTON_TYPE button) const;

	bool UpDate(void);		// ���̓��͏��̍X�V������

private:
	KEY_ARRAY _keyData;			// ���݂��ڰт̷����͏����i�[����
	KEY_ARRAY _keyDataOld;		// 1�ڰёO���ڰт̷����͏����i�[����
	
	std::array<INPUT_ARRAY, KEY_TYPE_MAX> _inputData;	// ���݂̃t���[����1�t���[���O�̃{�^�����͏����i�[
};
