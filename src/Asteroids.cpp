
#include "Asteroids.hpp"

Asteroids::Asteroids() {	
	int r;
	r = rand() % 4;
	_yLoc = rand () % (_yMax - 1);
	_xLoc = rand() % (_xMax - 1);
	if (r == 1)
		_form = ASTERFORM1;
	else if (r == 2)
		_form = ASTERFORM2;
	else
		_form = ASTERFORM3;
}

Asteroids::~Asteroids() {}
		

Asteroids::Asteroids(Asteroids const & a) {
	*this = a;
}

Asteroids& Asteroids::operator=(Asteroids const &a) {
	if (this != &a) {
		Objects::operator=(a);
		_form = a._form;
	}
	return *this;
}
