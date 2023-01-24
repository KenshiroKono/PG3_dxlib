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
	&Enemy::Approach,	//óvëfî‘çÜ0
	&Enemy::Shot,		//óvëfî‘çÜ1
	&Enemy::Leave		//óvëfî‘çÜ2
};

void Enemy::Update() {
	(this->*pPhase[phase])();
	bulletY += bSpeed;
}

void Enemy::Approach() {
	posY += eSpeed;
	timer--; 
	if (timer <= 0 && isShot == false) {
		//î≠éÀÇ÷à⁄çs
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

	//ó£íEÇ÷à⁄çs
	phase = leave;
}

void Enemy::Leave() {
	posY -= eSpeed;
}

void Enemy::Draw() {
	//ìG
	DrawCircle(posX, posY, eRadius, GetColor(255, 0, 0), 1);
	//íe
	DrawCircle(bulletX, bulletY, bRadius, GetColor(255, 0, 0), 1);

}