#pragma once
#include <array>

enum BUTTON_TYPE
{
	// 移動操作
	UP,			// 上
	DOWN,		// 下
	RIGHT,		// 右
	LEFT,		// 左

	// 自爆
	BOMB,

	// 決定ボタン
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

	bool UpDate(void);		// ｷｰの入力情報の更新をする

private:
	KEY_ARRAY _keyData;			// 現在のﾌﾚｰﾑのｷｰ入力情報を格納する
	KEY_ARRAY _keyDataOld;		// 1ﾌﾚｰﾑ前のﾌﾚｰﾑのｷｰ入力情報を格納する
	
	std::array<INPUT_ARRAY, KEY_TYPE_MAX> _inputData;	// 現在のフレームと1フレーム前のボタン入力情報を格納
};
