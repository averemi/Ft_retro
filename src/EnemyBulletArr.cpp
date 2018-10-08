

#include "EnemyBulletArr.hpp"
#include "ft_retro.h"

const int		EnemyBulletArr::_max_bullets = 500;
EnemyBulletArr	*EnemyBulletArr::_bullet_ptr = NULL;

EnemyBulletArr::EnemyBulletArr() : _bullet_arr(this->_init()), _bullet_count(0) {}

Shoot	*EnemyBulletArr::_init() {
	Shoot 	*ptr = new Shoot[EnemyBulletArr::_max_bullets];
	return (ptr);
}

EnemyBulletArr::~EnemyBulletArr() {
	delete [] EnemyBulletArr::_bullet_ptr;
}


EnemyBulletArr	*EnemyBulletArr::EnemyBulletARR() {
	if (EnemyBulletArr::_bullet_ptr == NULL)
		EnemyBulletArr::_bullet_ptr = new EnemyBulletArr[EnemyBulletArr::_max_bullets];
	return (_bullet_ptr);
}

void		EnemyBulletArr::delBullet(int num) {
	if (this->_bullet_count > 0) {
		this->_bullet_count--;
		if (this->_bullet_count == 0 || this->_bullet_count == num) {
			return ;
		}
		this->_bullet_arr[num].swap(this->_bullet_arr[this->_bullet_count]);
	}
}

void		EnemyBulletArr::addBullet(int x, int y) {
	if (this->_bullet_count == EnemyBulletArr::_max_bullets)
		this->_bullet_count = 0;
	this->_bullet_arr[this->_bullet_count].setxLoc(x - 2);
	this->_bullet_arr[this->_bullet_count].setyLoc(y);
	this->_bullet_arr[this->_bullet_count].setxMax(0);
	++(this->_bullet_count);
}

int			EnemyBulletArr::getBulletCount() const {
	return (this->_bullet_count);
}

void		EnemyBulletArr::hitShip(Ship &ship) {
	for (int j = 0; j < this->_bullet_count; j++) {
		if (this->_bullet_arr[j].getxLoc() > 0) {
			mvwprintw(ship.getWin(), this->_bullet_arr[j].getyLoc(), this->_bullet_arr[j].getxLoc() - 1, " ");
			if (this->_bullet_arr[j].getyLoc() == ship.getyLoc() && (abs(this->_bullet_arr[j].getxLoc() - ship.getxLoc()) < 2)) {
				ship.takeDamage();
				this->delBullet(j);
			}
			else  {
				this->_bullet_arr[j].move(-1);
				mvwprintw(ship.getWin(), this->_bullet_arr[j].getyLoc(), this->_bullet_arr[j].getxLoc(), ENEMYSHOOTFORM);
			}
		}
	}
}

void		hitPlayer(Ship &ship) {
	EnemyBulletArr	*tmp = EnemyBulletArr::EnemyBulletARR();
	tmp->hitShip(ship);
}
