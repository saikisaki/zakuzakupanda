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
	_defSize = _size;
	_playerH = IMAGE_ID("image/player.png")[0];
	_animCnt = 0;
	_animKey = STATE::NORMAL;
}

bool Player::Explosion(void)
{
	_size = _animCnt / 3;

	if (_size >= 100)
	{
		_size = _defSize;
		return false;
	}

	_animCnt++;

	return true;
}

UNIT Player::GetUnit(void)
{
	return UNIT::PLAYER;
}

void Player::SetMove(void)
{
	if (_animKey == STATE::BOMB)
	{
		if (!Explosion())
		{
			State(STATE::DEATH);
		}
		else
		{
			return;
		}
	}
	// Ç±Ç±Ç≈stateÇ™DEATHÇÃéûÇÃèàóùÇèëÇ≠
	if (_animKey == STATE::DEATH)
	{
		_life--;
		if (_life <= 0)
		{
			return;
		}
		State(STATE::INVINCIBLE);
		_invincibleTime = 180;
	}
	// ñ≥ìGéûä‘
	if (_invincibleTime)
	{
		_invincibleTime--;
		if (_invincibleTime <= 0)
		{
			State(STATE::NORMAL);
			_invincibleTime = 0;
		}
	}

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
	if (_animKey == STATE::NORMAL
	 || _animKey == STATE::INVINCIBLE)
	{
		DrawRotaGraph(_pos.x, _pos.y, 0.3, 0, _playerH, true);
	}
	else if (_animKey == STATE::BOMB)
	{
		DrawCircle(_pos.x, _pos.y, _size,0xff0000,0);
	}
	else
	{
		// âΩÇ‡ÇµÇ»Ç¢
	}
	
}
