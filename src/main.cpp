


#include "ft_retro.h"
#include "Game.hpp"
#include "detectResize.hpp"



void	final_score_announce(Ship &ship) {
	std::cout << std::endl;
	std::cout << "####################" << std::endl;
	std::cout << "######  SCORE ######" << std::endl;
	std::cout << "####################" << std::endl;
	std::cout << "###    Time: " << "\e[34;1m";
	std::cout << difftime(time(0), ship.getTime()) << "\e[0m" << std::endl;
	std::cout << "###   Level: " << "\e[32;1m";
	std::cout << ship.getLevel() << "\e[0m" << std::endl;
	std::cout << "###  Points: " << "\e[31;1m";
	std::cout << ship.getScore() << "\e[0m" << std::endl;
	std::cout << "####################" << std::endl;
	std::cout << "####################" << std::endl;
}

int		main() {

	// + 1-2 bonuses
	// check if terminal is ok after the game ends

	Game 	game;

	handle_winch();

	Screen		screen;
	Ship 		ship;

	if (screen.enterstartmenu(ship))
	{
		ship.setTime(time(0));
		game.play(screen, ship);
		clear();
		endwin();
		final_score_announce(ship);
		system("pkill afplay");
	}
	else
	{
		clear();
		endwin();
	}
}
