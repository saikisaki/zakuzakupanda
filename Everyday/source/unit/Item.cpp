#include <cmath>
#include <time.h>
#include "DxLib.h"
#include "Item.h"
#include "../Mng/ImageMng.h"
#include "../Mng/SceneMng.h"

Item::Item()
{
	Init();
}

Item::Item(const VECTOR2 & playerPos, const VECTOR2 & enemyPos)
{
	_pos = enemyPos;
	
	auto angle = atan2f(enemyPos.y - playerPos.y, enemyPos.x - playerPos.x);
	_vel.x = cos(angle);
	_vel.y = sin(angle);
	Init();
}

Item::~Item()
{
}

void Item::Init(void)
{
	_speed = 1;
	_size = 10;
	_itemH = IMAGE_ID("image/item.png")[0];
	_weightArray = { 1,5,7 };
	srand((unsigned int)time(NULL));
	_item = ItemRand();
}

UNIT Item::GetUnit(void)
{
	return UNIT::ITEM;
}

void Item::SetMove(Shared_Obj &player)
{
	_pos += _vel * _speed;

	if (HitPlayer(player))
	{
		switch (_item)
		{
		case ITEM::POWER_UP:
			BigBlast(player);
			break;
		case ITEM::HEAL:
			RecoveryUnit(player);
			break;
		case ITEM::POINT_GET:
			MorePoint(player);
			break;
		default:
			break;
		}
		State(STATE::DEATH);
	}

	if (OffScreen())
	{
		State(STATE::DEATH);
	}

}

bool Item::HitPlayer(Shared_Obj &player)
{
	if (hypot(_pos.x - player->Pos().x, _pos.y - player->Pos().y) < _size + player->Size())
	{
		return true;
	}
	return false;
}

void Item::RecoveryUnit(Shared_Obj &player)
{
	player->Life(player->Life() + 1);
}

void Item::BigBlast(Shared_Obj &player)
{
	player->BlastRange(player->BlastRange() + 50);
}

void Item::MorePoint(Shared_Obj &player)
{
}

bool Item::OffScreen()
{
	if (_pos.x + _size / 2 <= 0
	 || _pos.x - _size / 2 >= lpSceneMng.GetScreenSize().x
	 || _pos.y - _size / 2 <= 0
	 || _pos.y + _size / 2 >= lpSceneMng.GetScreenSize().y)
	{
		return true;
	}

	return false;
}

int Item::ItemRand()
{
	int totalWeight = 0;

	for (auto &weight : _weightArray)
	{
		totalWeight += weight;
	}

	int random = rand() % totalWeight;

	for (auto &weight : _weightArray)
	{
		if (random < weight)
		{
			return random;
		}

		random -= weight;
	}

	return 9999;
}

void Item::Draw(void)
{
	DrawRotaGraph(_pos.x, _pos.y, 0.1, 0, _itemH, true);
}
