#include <Dxlib.h>
#include "GameCtrl.h"

GameCtrl::GameCtrl()
{
}

GameCtrl::~GameCtrl()
{
}

bool GameCtrl::GetPadData(BUTTON_TYPE button) const
{
	return _inputData[KEY_TYPE_NOW][button];
}

bool GameCtrl::GetPadDataTrg(BUTTON_TYPE button) const
{
	return _inputData[KEY_TYPE_NOW][button] && !_inputData[KEY_TYPE_OLD][button];
}

bool GameCtrl::UpDate(void)
{
	_keyDataOld = _keyData;
	GetHitKeyStateAll(&_keyData[0]);

	_inputData[KEY_TYPE_OLD] = _inputData[KEY_TYPE_NOW];

	_inputData[KEY_TYPE_NOW][UP] = _keyData[KEY_INPUT_UP];
	_inputData[KEY_TYPE_NOW][DOWN] = _keyData[KEY_INPUT_DOWN];
	_inputData[KEY_TYPE_NOW][RIGHT] = _keyData[KEY_INPUT_RIGHT];
	_inputData[KEY_TYPE_NOW][LEFT] = _keyData[KEY_INPUT_LEFT];
	_inputData[KEY_TYPE_NOW][BOMB] = _keyData[KEY_INPUT_SPACE];
	_inputData[KEY_TYPE_NOW][ENTER] = _keyData[KEY_INPUT_RETURN];

	return true;
}
