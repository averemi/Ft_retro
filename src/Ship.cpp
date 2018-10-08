		

#include "Ship.hpp"
#include "Screen.hpp"
#include "BulletArr.hpp"

Ship::Ship() {
	_form = SHIPFORM1;

	curs_set(0);
	start_color();
	getmaxyx(stdscr, _yMax, _xMax);
	_playerwin = newwin(_yMax-6, _xMax, 0, 0);
	getmaxyx(_playerwin, _yMax, _xMax);
	keypad(_playerwin, true);
	noecho(); // no echo to the terminal;
	nodelay(_playerwin, TRUE); // getch not waiting
	cbreak(); // ctrl+c
	_xLoc = 1;
	_yLoc = _yMax / 2;
	refresh();
	wrefresh(_playerwin);
}

Ship::~Ship() {
	endwin();
}

Ship::Ship(Ship const & a) {
	*this = a;
	getmaxyx(stdscr, _yMax, _xMax);
	if (_yMax < a._yMax && _xMax < a._xMax) {
		_playerwin = newwin(_yMax-6, _xMax, 0, 0);
		getmaxyx(_playerwin, _yMax, _xMax);
		_xLoc = 0;
		_yLoc = _yMax / 2;
	}
	else {
		_playerwin = newwin(a._yMax-6, a._xMax, 0, 0);
		_yMax = a._yMax;
		_xMax = a._xMax;
		_xLoc = a._xLoc;
		_yLoc = a._yLoc;
	}
	keypad(_playerwin, true);
	refresh();
	wrefresh(_playerwin);
}

Ship&	Ship::operator=(Ship const & a) {
	if (this != &a) {
		Player::operator=(a);
		Objects::operator=(a);
		_form = a._form;
		getmaxyx(stdscr, _yMax, _xMax);
		if (_yMax < a._yMax && _xMax < a._xMax) {
			_playerwin = newwin(_yMax-6, _xMax, 0, 0);
			getmaxyx(_playerwin, _yMax, _xMax);
			_xLoc = 0;
			_yLoc = _yMax / 2;
		}
		else {
			Player::operator=(a);
			Objects::operator=(a);
			_playerwin = newwin(a._yMax-6, a._xMax, 0, 0);
			_yMax = a._yMax;
			_xMax = a._xMax;
			_xLoc = a._xLoc;
			_yLoc = a._yLoc;
		}
		keypad(_playerwin, true);
		refresh();
		wrefresh(_playerwin);
	}
	return *this;
}

void	Ship::mvUp() {
	_yLoc--;
	if (_yLoc < 0)
		_yLoc = 0;
	display();
}

void	Ship::mvDown() {
	_yLoc++;
	if (_yLoc >= _yMax - 1)
		_yLoc = _yMax - 2;
	display();
}

void	Ship::mvLeft() {
	_xLoc--;
	if (_xLoc < 0)
		_xLoc = 0;
	display();
}

void	Ship::mvRight() {
	_xLoc++;
	if (_xLoc >= _xMax)
		_xLoc = _xMax - 1;
	display();
}

int		Ship::getMv(Screen &screen) {
	int choice = wgetch(_playerwin);
	switch (choice) {
		case KEY_UP:
			mvUp();
			break;
		case KEY_DOWN:
			mvDown();
			break;
		case KEY_LEFT:
			mvLeft();
			break;
		case KEY_RIGHT:
			mvRight();
			break;
		case 32:
			shoot();
			break;
		case 'q':
			return 0;
		case ESC:
			if (screen.entermenu(*this) == 0)
				return (0);
		default:
			break;
	}
	return choice;
}

void	Ship::display() {
	wattron(_playerwin, COLOR_PAIR(1));
	mvwprintw(_playerwin, _yLoc, _xLoc, _form);
	wrefresh(_playerwin);
	wattroff(_playerwin, COLOR_PAIR(1));

}

WINDOW * Ship::getWin() {
	return _playerwin;
}

void		Ship::shoot() {
	system("afplay shoot.mp3 &");
	::shoot(*this);
}
