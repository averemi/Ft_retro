

#include "Enemy.hpp"
#include "EnemyBulletArr.hpp"

Enemy::Enemy() {	
	_collide = 0;
	_yLoc = rand () % (_yMax - 1);
	if (rand() % 2) {
		_xLoc = _xMax - 1;
		_form = ENEMYFORM1;
	}
	else {
		_form = ENEMYFORM2;
		_xLoc = _xMax - 3;
	}
//	_oldx = _xLoc;
//	_oldy = _yLoc;
}

Enemy::~Enemy() {}
		

Enemy::Enemy(Enemy const & a) {
	*this = a;
}

Enemy& Enemy::operator=(Enemy const &a) {
	if (this != &a) {
		Objects::operator=(a);
		_form = a._form;
		_collide = a._collide;
	}
	return *this;
}

void	Enemy::recreate() {

	_yLoc = rand () % (_yMax - 1);
	if (rand() % 2) {
		_xLoc = _xMax - 1;
		_form = ENEMYFORM1;
	}
	else {
		_form = ENEMYFORM2;
		_xLoc = _xMax - 3;
	}
}

int		Enemy::checkCollision(Ship & ship, int x, int y) {
	if (y == getyLoc() && abs(x - getxLoc()) < 2) {
		ship.takeDamage();
		return (1);
	}
	return (0);
}

void	Enemy::shoot() {
	EnemyBulletArr	*tmp = EnemyBulletArr::EnemyBulletARR();

	tmp->addBullet(this->_xLoc, this->_yLoc);
}

void	Enemy::changey(Ship &ship) {
	int		random = rand() % 50;

	if (random < 20 && ship.getyLoc() == this->getyLoc()) {
		int		s = (random % 2 == 0) ? 1 : -1;
		this->shoot();
		this->setyLoc(this->getyLoc() + s);
	}
	if (random > 5)
		return ;
	if (ship.getyLoc() > this->getyLoc())
		this->setyLoc(getyLoc() + 1);
	if (ship.getyLoc() < this->getyLoc())
		this->setyLoc(getyLoc() - 1);
}

void	Enemy::move(Ship & ship) {
	WINDOW	*_win = ship.getWin();
	int		random = rand() % 100;

	int x = getxLoc();
	int y = getyLoc();
	if (checkCollision(ship, ship.getxLoc(), ship.getyLoc())) {
		recreate();
		return ;
	}
	else if (random == 0)
		this->shoot();
	changey(ship);
	if (x < 0)
		recreate();
	else if (x >= 0) {
		if (_form == ENEMYFORM1)
			mvwprintw(_win, y, x, " ");
		else {
			mvwprintw(_win, y, x, "    ");
			if (_collide == 1) {
				x = x - 10;
				_collide = 0;
			}
		}
		x--;
		setxLoc(x);
	}
}
