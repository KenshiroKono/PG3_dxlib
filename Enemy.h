#pragma once

#include "DxLib.h"
class Enemy {

public:

	Enemy();
	~Enemy();

	void Initialize();
	void Update();

	void Approach();
	void Shot();
	void Leave();

	void Draw();

public:

private:

private:
	enum Phase {
		approach,
		shot,
		leave,
	};
	static void (Enemy::* pPhase[])();
	//en
	int posX = 0;
	int posY = 0;
	int eRadius = 0;
	int eSpeed = 0;
	//bl
	int bulletX = 0;
	int bulletY = 0;
	int bRadius = 0;
	int bSpeed = 0;


	int timer = 0;
	int phase = 0;

	bool isShot = false;
};

