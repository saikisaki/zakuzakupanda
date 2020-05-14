#include "Player.h"



Player::Player()
{
}

Player::Player(const VECTOR2& pos, const int& size)
{
	_pos = pos;
	_size = size;
}

Player::~Player()
{
}

void Player::Init(void)
{

}

UNIT Player::GetUnit(void)
{
	return UNIT::PLAYER;
}

void Player::SetMove(void)
{
}

void Player::Draw(void)
{
}
