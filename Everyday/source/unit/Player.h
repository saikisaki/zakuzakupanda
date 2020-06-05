#pragma once
#include "Obj.h"
#include "../input/GameCtrl.h"

class Player :
	public Obj
{
public:
	Player();
	Player(const VECTOR2& pos, const int size);
	~Player();

	UNIT GetUnit(void) override;
	void SetMove(Shared_Obj &player) override;
	void Draw(void) override;

private:
	void Init(void);
	bool Explosion(void);

	int _playerH;		// �v���C���[�p�̉摜
	int _invincibleTime;	// ���G����
	std::unique_ptr<GameCtrl> gameCtrl;		// �L��������p�̉摜
};

