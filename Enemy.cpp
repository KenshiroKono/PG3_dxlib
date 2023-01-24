#include "Enemy.h"

Enemy::Enemy() {
	Initialize();

}

void Enemy::Initialize() {
	phase= approach;
	posX = 300;
	posY = 30;
	eRadius = 25;
	eSpeed = 2;
	timer = 80;
}

void (Enemy::* Enemy::pPhase[])() =
{
	&Enemy::Approach,	//�v�f�ԍ�0
	&Enemy::Shot,		//�v�f�ԍ�1
	&Enemy::Leave		//�v�f�ԍ�2
};

void Enemy::Update() {
	(this->*pPhase[phase])();
	bulletY += bSpeed;
}

void Enemy::Approach() {
	posY += eSpeed;
	timer--; 
	if (timer <= 0 && isShot == false) {
		//���˂ֈڍs
		phase = shot;
		//(this->*phase[1])();
		isShot = true;
	}
}

void Enemy::Shot() {
	bulletX = posX;
	bulletY = posY;
	bRadius = 15;
	bSpeed = 4;

	//���E�ֈڍs
	phase = leave;
}

void Enemy::Leave() {
	posY -= eSpeed;
}

void Enemy::Draw() {
	//�G
	DrawCircle(posX, posY, eRadius, GetColor(255, 0, 0), 1);
	//�e
	DrawCircle(bulletX, bulletY, bRadius, GetColor(255, 0, 0), 1);

}