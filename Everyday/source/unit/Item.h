#pragma once
#include <array>
#include "Obj.h"


enum ITEM
{
	POWER_UP,
	HEAL,
	POINT_GET,
	MAX
};

class Item :
	public Obj
{
public:
	Item();
	Item(const VECTOR2 &playerPos, const VECTOR2 &enemyPos);
	~Item();

	UNIT GetUnit(void) override;
	void SetMove(Shared_Obj &player) override;
	void Draw(void) override;

private:
	void Init(void);
	void RecoveryUnit(Shared_Obj &player);
	void BigBlast(Shared_Obj &player);
	void MorePoint(Shared_Obj &player);
	bool OffScreen();
	int ItemRand();
	bool HitPlayer(Shared_Obj &player);
	
	std::array<int, ITEM::MAX> _weightArray;
	VECTOR2 _vel;
	int _itemH;
	int _item;


};

