

#include "BulletArr.hpp"

const int	BulletArr::_max_bullets = 500;
BulletArr	*BulletArr::_bullet_ptr = NULL;

BulletArr::BulletArr() : _bullet_arr(this->_init()), _bullet_count(0) {}

Shoot	*BulletArr::_init() {
	Shoot 	*ptr = new Shoot[BulletArr::_max_bullets];
	return (ptr);
}

BulletArr::~BulletArr() {
	delete [] BulletArr::_bullet_ptr;
}


BulletArr	*BulletArr::BulletARR() {
	if (BulletArr::_bullet_ptr == NULL)
		BulletArr::_bullet_ptr = new BulletArr[BulletArr::_max_bullets];
	return (_bullet_ptr);
}

void		BulletArr::delBullet(int num) {
	if (this->_bullet_count > 0) {
		this->_bullet_count--;
		if (this->_bullet_count == 0 || this->_bullet_count == num) {
			return ;
		}
		this->_bullet_arr[num].swap(this->_bullet_arr[this->_bullet_count]);
	}
}

void		BulletArr::addBullet(int x, int y, int xmax) {
	if (this->_bullet_count == BulletArr::_max_bullets)
		this->_bullet_count = 0;
	this->_bullet_arr[this->_bullet_count].setxLoc(x + 2);
	this->_bullet_arr[this->_bullet_count].setyLoc(y);
	this->_bullet_arr[this->_bullet_count].setxMax(xmax);
	++(this->_bullet_count);
}

int			BulletArr::getBulletCount() const {
	return (this->_bullet_count);
}

void		BulletArr::hitEnemies(Ship &ship, Enemy *enemy, int enemy_count) {
	for (int j = 0; j < this->_bullet_count; j++) {
		if (this->_bullet_arr[j].getxLoc() > 0) {
			mvwprintw(ship.getWin(), this->_bullet_arr[j].getyLoc(), this->_bullet_arr[j].getxLoc() - 1, " ");
			if (this->_bullet_arr[j].shootEnemy(enemy, enemy_count)) {
				ship.addScore();
				if ((ship.getScore() % 100) == 0)
					ship.addLevel();
				if (ship.getLevel() == 2)
					ship.setForm(SHIPFORM2);
				this->delBullet(j);
			}
			else  {
				this->_bullet_arr[j].move(1);
				if (ship.getLevel() < 1)
					mvwprintw(ship.getWin(), this->_bullet_arr[j].getyLoc(), this->_bullet_arr[j].getxLoc(), this->_bullet_arr[j].getForm());
				else
					mvwprintw(ship.getWin(), this->_bullet_arr[j].getyLoc(), this->_bullet_arr[j].getxLoc(), "*");
			}
		}
	}
}

void		shoot(const Ship &ship) {
	BulletArr	*tmp = BulletArr::BulletARR();

	tmp->addBullet(ship.getxLoc(), ship.getyLoc(), ship.getxMax());
}

void		hitEnemies(Ship &ship, Enemy *enemy, int enemy_count) {
	BulletArr	*tmp = BulletArr::BulletARR();

	tmp->hitEnemies(ship, enemy, enemy_count);
}