#include <cmath>
#include <time.h>
#include "GameScene.h"
#include "../unit/Player.h"
#include "../unit/Enemy.h"
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

	// Ž€–S‚µ‚½“G‚Ì—v‘f‚ðíœ
	auto death_itr = std::remove_if(_objList.begin(), _objList.end(), [](std::shared_ptr<Obj> enem)
		{
			if (enem->State() == STATE::DEATH 
			 && enem->GetUnit() == UNIT::ENEMY)
			{
				return true;
			}
			return false;
		});
	_objList.erase(death_itr, _objList.end());


	for (auto &obj : _objList)
	{
		obj->SetMove();
		obj->Draw();
	}

	HitPlayer();
	EnemyKillingMistake();

	_frameCnt++;

	return std::move(own);
}

bool GameScene::CheckHit(const VECTOR2& posA, float radA, const VECTOR2& posB, float radB)
{
	return hypot(posA.x - posB.x, posA.y - posB.y) < radA + radB;
}

bool GameScene::HitPlayer()
{
	for (auto &player : _objList)
	{
		if (player->GetUnit() == UNIT::PLAYER)
		{
			for (auto &enemy : _objList)
			{
				if (player == enemy 
				 || enemy->State() != STATE::NORMAL)
				{
					continue;
				}

				if (CheckHit(player->Pos(), player->Size(), enemy->Pos(), enemy->Size()))
				{
					if (player->State() == STATE::NORMAL)
					{
						player->State(STATE::BOMB);
					}
					else if (player->State() == STATE::BOMB)
					{
						enemy->State(STATE::BOMB);
					}
				}
			}
		}
	}
	return false;
}

bool GameScene::EnemyKillingMistake()
{
	for (auto &enemyA : _objList)
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
	}

	return false;
}
