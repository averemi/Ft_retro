

#include "Shoot.hpp"
#include "Ship.hpp"

Shoot::Shoot() : _shootwin(NULL), _parent(0) {
	_xLoc = 0;
	_yLoc = 0;
	_form = SHOOTFORM;
	_xMax = 0;
	_yMax = 0;
}

Shoot::Shoot(int parent) : _shootwin(NULL), _parent(parent) {
	_xLoc = 0;
	_yLoc = 0;
	_form = SHOOTFORM;
	_xMax = 0;
	_yMax = 0;
}

Shoot::~Shoot() {}

Shoot::Shoot(Shoot const &a) {
	*this = a;
}

Shoot&	Shoot::operator=(Shoot const &a) {
	if (this != &a) {
		Objects::operator=(a);
		_form = a._form;
		_shootwin = a._shootwin;
	}
	return *this;
}

int		Shoot::shootEnemy(Enemy *enemy, int enemy_count) {
	for (int i = enemy_count - 1; i >= 0; --i) {
		if (enemy[i].getyLoc() == getyLoc() && abs(enemy[i].getxLoc() - getxLoc()) < 2) {
			std::cout << getxLoc() << " " << enemy[i].getxLoc() << std::endl;
			enemy[i].recreate();
			return (1);
		}
	}
	return (0);
}

void	Shoot::move(int direction) {
	if (direction > 0)
		++(this->_xLoc);
	else if (direction < 0)
		--(this->_xLoc);
}

int		Shoot::getParent() const {
	return (this->_parent);
}
