#include <cmath>
#include <time.h>
#include "GameScene.h"
#include "../unit/Player.h"
#include "../unit/Enemy.h"
#include "../unit/Item.h"
#include "../Mng/SceneMng.h"

#define PI 3.141592

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
}

void GameScene::Init(void)
{
	_frameCnt = 0;
	srand((unsigned int)time(NULL));

	_objList.emplace_back(std::make_shared<Player>(VECTOR2(lpSceneMng.GetScreenSize().x / 2 - 15, 350), 20));
		
}

Unique_Base GameScene::UpDate(Unique_Base own)
{

	if (_frameCnt % 60 == 0)
	{
		VECTOR2 pos(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 2);

		int angle = rand();
		pos.x += cos((angle % 360 + 1) * PI / 180) * 1000;
		pos.y += sin((angle % 360 + 1) * PI / 180) * 1000;

		_objList.emplace_back(std::make_shared<Enemy>(pos, 20, _objList[0]->Pos()));

		if (pos.x > 0 && pos.x < lpSceneMng.GetScreenSize().x && pos.y > 0 && pos.y < lpSceneMng.GetScreenSize().y)
		{
			auto test = 0;
		}

	}

//\\\\\\\\\\\\\\

//--------------------


	for (auto &obj : _objList)
	{
		obj->SetMove(_objList[0]);
		obj->Draw();
	}
	
	for (auto &obj : _itemList)
	{
		obj->SetMove(_objList[0]);
		obj->Draw();
	}

	IsHit();

	// €–S‚µ‚½“G‚Ì—v‘f‚ğíœ
	auto death_itr = std::remove_if(_objList.begin(), _objList.end(), [](std::shared_ptr<Obj> obj)
		{
			if (obj->State() == STATE::DEATH
				&& obj->GetUnit() != UNIT::PLAYER)
			{
				return true;
			}
			return false;
		});
	_objList.erase(death_itr, _objList.end());

	// €–S‚µ‚½“G‚Ì—v‘f‚ğíœ
	auto erase_itr = std::remove_if(_itemList.begin(), _itemList.end(), [](std::shared_ptr<Obj> obj) 
		{
			if (obj->State() == STATE::DEATH)
			{
				return true;
			}
			return false;
		});
	_itemList.erase(erase_itr, _itemList.end());

	_frameCnt++;

	return std::move(own);
}

bool GameScene::CheckHit(const VECTOR2& posA, float radA, const VECTOR2& posB, float radB)
{
	return hypot(posA.x - posB.x, posA.y - posB.y) < radA + radB;
}

bool GameScene::IsHit()
{

	int a = 0;
	for (auto &obj1 : _objList)
	{
		a++;
		for (auto &obj2 : _objList)
		{
			if (obj1 == obj2
			 || obj2->State() != STATE::NORMAL
			 || obj2->GetUnit() != UNIT::ENEMY
			 /*|| obj1->GetUnit() == UNIT::ITEM*/)
			{
				continue;
			}

			if (CheckHit(obj1->Pos(), obj1->Size(), obj2->Pos(), obj2->Size()))
			{
				if (obj1->GetUnit() == UNIT::PLAYER
				 && obj1->State()   == STATE::NORMAL)
				{
					obj1->State(STATE::BOMB);
				}
				else if (obj1->State() == STATE::BOMB)
				{
					obj2->State(STATE::BOMB);
					_itemList.emplace_back(std::make_shared<Item>(obj1->Pos(), obj2->Pos()));
				}
				else
				{
					// ‰½‚àˆ—‚µ‚È‚¢
				}
			}
		}
	}

	return true;
}

bool GameScene::EnemyKillingMistake()
{
	/*for (auto &enemyA : _objList)
	{
		if (enemyA->GetUnit() == UNIT::ENEMY
			&& enemyA->State() == STATE::BOMB)
		{
			for (auto &enemyB : _objList)
			{
				if (enemyA == enemyB
					|| enemyB->State() != STATE::NORMAL)
				{
					continue;
				}

				if (CheckHit(enemyA->Pos(), enemyA->Size(), enemyB->Pos(), enemyB->Size()))
				{
					enemyB->State(STATE::BOMB);
				}
			}
		}
	}*/

	return false;
}
