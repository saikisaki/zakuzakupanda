#include <algorithm>
#include "DxLib.h"
#include "Player.h"
#include "../Mng/ImageMng.h"
#include "../Mng/SceneMng.h"

Player::Player()
{
	Init();
}

Player::Player(const VECTOR2& pos, const int& size)
{
	_pos = pos;
	_size = size;
	Init();
}

Player::~Player()
{
}

void Player::Init(void)
{
	gameCtrl = std::make_unique<GameCtrl>();

	_speed = 10;
	_life = 10;
	_playerH = IMAGE_ID("image/player.png")[0];
}

UNIT Player::GetUnit(void)
{
	return UNIT::PLAYER;
}

void Player::SetMove(void)
{
	gameCtrl->UpDate();

	
	if (gameCtrl->GetPadData(BUTTON_TYPE::LEFT))
	{
		_pos.x = max(0 + _size / 2, _pos.x - _speed);
	}
	if (gameCtrl->GetPadData(BUTTON_TYPE::RIGHT))
	{
		_pos.x = min(lpSceneMng.GetScreenSize().x - _size / 2, _pos.x + _speed);
	}
	if (gameCtrl->GetPadData(BUTTON_TYPE::UP))
	{
		_pos.y = max(0 + _size / 2, _pos.y - _speed);
	}
	if (gameCtrl->GetPadData(BUTTON_TYPE::DOWN))
	{
		_pos.y = min(lpSceneMng.GetScreenSize().y - _size / 2, _pos.y + _speed);
	}

}

void Player::Draw(void)
{
	DrawRotaGraph(_pos.x,_pos.y,0.3,0,_playerH,true);
}
