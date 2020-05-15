#include <cmath>
#include "GameScene.h"
#include "../unit/Player.h"
#include "../unit/Enemy.h"
#include "../Mng/SceneMng.h"

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
}

void GameScene::Init(void)
{
	_objList.emplace_back(std::make_shared<Player>(VECTOR2(lpSceneMng.GetScreenSize().x / 2 - 15, 350), 20));
	_objList.emplace_back(std::make_shared<Enemy>(VECTOR2(lpSceneMng.GetScreenSize().x / 2 - 15, -20), 20));
	
}

Unique_Base GameScene::UpDate(Unique_Base own)
{
	for (auto &obj : _objList)
	{
		obj->SetMove();
		obj->Draw();
	}

	HitPlayer();
	EnemyKillingMistake();

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
		if (player->GetUnit() == UNIT::PLAYER 
		 && player->State()   == STATE::NORMAL)
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
					player->State(STATE::BOMB);
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
