
#ifndef SCREEN_HPP
# define SCREEN_HPP

# include <iostream>
# include <ncurses.h>
# include "ft_retro.h"
# include "Ship.hpp"

class Screen {
	private:
		int _yMax;
		int _xMax;
		WINDOW * _menuwin;
		WINDOW	*_gamemenu;
	public:
		Screen();
		~Screen();
		Screen(Screen const &a);
		Screen& operator=(Screen const & a);

		WINDOW * getMenuwin();
		void	updateMenu(Ship & ship);
		int		getXmax();
		int		getYmax();
		int		enterstartmenu(Ship &ship);
		int		entermenu(Ship &ship);

};

#endif