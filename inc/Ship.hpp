

#ifndef SHIP_HPP
# define SHIP_HPP
# include <iostream>
# include <ncurses.h>
# include "ft_retro.h"
# include "Objects.hpp"
# include "Player.hpp"

class Screen;


class Ship : public Objects, public Player {
	private:
		WINDOW *			_playerwin;
	public:
		Ship();
		~Ship();
		Ship(Ship const & a);
		Ship& operator=(Ship const & a);

		void	mvUp();
		void	mvDown();
		void	mvLeft();
		void	mvRight();
		int		getMv(Screen &screen);
		void	display();
		void		shoot();
		WINDOW *		getWin();

};

#endif