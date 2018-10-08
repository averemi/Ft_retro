

#include "Screen.hpp"

Screen::Screen() {
	initscr();
	cbreak();
	curs_set(0);
	noecho(); 
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	getmaxyx(stdscr, _yMax, _xMax);
	if (_yMax < 50 || _xMax < 50) {
		clear();
		endwin();
		std::cout << "Window height or width cannot be lesser then 50 rows/chars" << std::endl;
		if (this->getXmax() < 50) {
			std::cout << "Current width: " << this->getXmax() << " chars" << std::endl;
		} else if (this->getYmax() < 50) {
			std::cout << "Current height: " << this->getYmax() << " rows" << std::endl;
		}
		exit(1);
	}
	_menuwin = newwin(6, _xMax-1, _yMax-6, 1);
	box(_menuwin, 0, 0);
	_gamemenu = newwin(_yMax - _yMax / 4, _xMax - _xMax / 4, _yMax / 8, _xMax / 8);
	box(_gamemenu, 0, 0);
	wrefresh(_gamemenu);
	nodelay(_gamemenu, true);
}

Screen::~Screen() {
	delwin(_menuwin);
	delwin(_gamemenu);
	endwin();
}

Screen::Screen(Screen const & a) {
	*this = a;
	initscr();
	cbreak();
	getmaxyx(stdscr, _yMax, _xMax);
	if (_yMax < a._yMax && _xMax < a._xMax)
		_menuwin = newwin(6, _xMax-1, _yMax-6, 1);
	else {
		_yMax = a._yMax;
		_xMax = a._xMax;
		_menuwin = newwin(6, a._xMax-1, a._yMax-6, 1);
	}
	box(_menuwin, 0, 0);
}

Screen& Screen::operator=(Screen const & a) {
	if (this != &a) {
		initscr();
		cbreak();
		getmaxyx(stdscr, _yMax, _xMax);
		if (_yMax < a._yMax && _xMax < a._xMax)
			_menuwin = newwin(6, _xMax-1, _yMax-6, 1);
		else {
			_yMax = a._yMax;
			_xMax = a._xMax;
			_menuwin = newwin(6, a._xMax-1, a._yMax-6, 1);
		}
		box(_menuwin, 0, 0);
	}
	return *this;
}

WINDOW	*Screen::getMenuwin() {
	return _menuwin;
}

void	Screen::updateMenu(Ship & ship) {
	double time_from_start = difftime(time(0), ship.getTime());
	wattron(_menuwin, COLOR_PAIR(4));
	mvwprintw(_menuwin, 1, 1, "SCORE : %i", ship.getScore());
	mvwprintw(_menuwin, 2, 1, "LEVEL : %i", ship.getLevel());
	mvwprintw(_menuwin, 1, _xMax / 2, "LIVES : %i", ship.getLives());
	mvwprintw(_menuwin, 2, _xMax / 2, "TIME  : %i sec", (int)time_from_start);
	wattroff(_menuwin, COLOR_PAIR(4));
	wrefresh(_menuwin);
}

int 	Screen::getXmax() {
	return _xMax;
}

int 	Screen::getYmax() {
	return _yMax;
}

int		Screen::enterstartmenu(Ship &ship) {
	std::string	menu[2] = {"Start", "Exit"};
	int 	active = 0;
	int		field = 0;
	int		x = 0;
	int		y = 0;

	getmaxyx(_gamemenu, y, x);
	y /= 2;
	x /= 2;
	keypad(ship.getWin(), FALSE);
	keypad(_gamemenu, TRUE);
	redrawwin(_gamemenu);
	box(_gamemenu, 0, 0);
	while (1) {
		for (int j = 0; j < 2; ++j) {
			if (j == active)
				wattron(_gamemenu, A_REVERSE);
			mvwprintw(_gamemenu, y + j, x, menu[j].c_str());
			if (j == active)
				wattroff(_gamemenu, A_REVERSE);
		}
		wrefresh(_gamemenu);
		field = wgetch(_gamemenu);
		if (field == KEY_UP)
			active--;
		else if (field == KEY_DOWN)
			active++;
		else if (field == ESC || field == 'q')
		{
			wclear(_gamemenu);
			return (0);
		}
		active %= 2;
		active = active < 0 ? 1 : active;
		if (field == 10)
			break ;
	}
	wclear(_gamemenu);
	keypad(ship.getWin(), TRUE);
	keypad(_gamemenu, FALSE);
	if (active == 0)
		return (1);
	else
		return (0);
}

int		Screen::entermenu(Ship &ship) {
	std::string	menu[2] = {"Resume", "Exit"};
	int 	active = 0;
	int		field = 0;
	int		x = 0;
	int		y = 0;

	getmaxyx(_gamemenu, y, x);
	y /= 2;
	x /= 2;
	keypad(ship.getWin(), FALSE);
	keypad(_gamemenu, TRUE);
	redrawwin(_gamemenu);
	box(_gamemenu, 0, 0);
	while (1) {
		for (int j = 0; j < 2; ++j) {
			if (j == active)
				wattron(_gamemenu, A_REVERSE);
			mvwprintw(_gamemenu, y + j, x, menu[j].c_str());
			if (j == active)
				wattroff(_gamemenu, A_REVERSE);
		}
		wrefresh(_gamemenu);
		field = wgetch(_gamemenu);
		if (field == KEY_UP)
			active--;
		else if (field == KEY_DOWN)
			active++;
		else if (field == 'q')
		{
			wclear(_gamemenu);
			return (0);
		}
		else if (field == ESC)
		{
			active = 0;
			field = 10;
		}
		active %= 2;
		active = active < 0 ? 1 : active;
		if (field == 10)
			break ;
	}
	wclear(_gamemenu);
	keypad(ship.getWin(), TRUE);
	keypad(_gamemenu, FALSE);
	redrawwin(ship.getWin());
	wrefresh(ship.getWin());
	if (active == 0)
		return (1);
	else
		return (0);
}



