

#include "Objects.hpp"

Objects::Objects() {
	getmaxyx(stdscr, _yMax, _xMax);
	_yMax = _yMax - 6;
	_xLoc = 0;
	_yLoc = 0;
	_form = "";
}

Objects::~Objects() {}

Objects::Objects(Objects const & a) {
	*this = a;
	getmaxyx(stdscr, _yMax, _xMax);
	if ((_yMax - 6) < a._yMax && _xMax < a._xMax) {
		_yMax = _yMax - 6;
	}
	else {
		_yMax = a._yMax;
		_xMax = a._xMax;
	}
}

Objects& Objects::operator=(Objects const & a) {
	if (this != &a) {
		getmaxyx(stdscr, _yMax, _xMax);
		_xLoc = a._xLoc;
		_yLoc = a._yLoc;
		_form = a._form;
		if ((_yMax - 6) < a._yMax && _xMax < a._xMax) {
			_yMax = _yMax - 6;
		}
		else {
			_yMax = a._yMax;
			_xMax = a._xMax;
		}
	}
	return *this;
}

int		Objects::getxLoc() const {
	return _xLoc;
}

int		Objects::getyLoc() const {
	return _yLoc;
}

int		Objects::getxMax() const {
	return _xMax;
}

void	Objects::setxLoc(int x) {
	_xLoc = x;
}

void	Objects::setyLoc(int y) {
	_yLoc = y;
}

void	Objects::setxMax(int xMax) {
	_xMax = xMax;
}

void	Objects::setyMax(int yMax) {
	_yMax = yMax;
}

const char*	Objects::getForm() {
	return _form;
}

void	Objects::setForm(const char* form) {
	_form = form;
}

void	Objects::swap(Objects &obj) {
	const char	*tmp = this->_form;

	this->_form = obj._form;
	obj._form = tmp;
	std::swap(this->_xLoc, obj._xLoc);
	std::swap(this->_yLoc, obj._yLoc);
	std::swap(this->_xMax, obj._xMax);
	std::swap(this->_yMax, obj._yMax);
}
