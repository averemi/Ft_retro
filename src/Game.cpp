

#include "Game.hpp"
#include "EnemyBulletArr.hpp"
#include "BulletArr.hpp"
#include <ctime>

Game::Game() {
	_enemy_count = 6;
	_aster_count = 25;
	_count = 0;
	srand(clock());
}

Game::~Game() {}

Game::Game(Game const &a) {
	*this = a;
}

Game& Game::operator=(Game const &a) {
	_enemy_count = a._enemy_count;
	_aster_count = a._aster_count;
	_count = a._count;
	return *this;
}


void	Game::printAll(Enemy *enemy, Ship &ship, Asteroids *aster) {
	this->printAster(ship, aster);
	for (int i = 0; i < _enemy_count; i++) {
		wattron(ship.getWin(), COLOR_PAIR(2));
		mvwprintw(ship.getWin(), enemy[i].getyLoc(), enemy[i].getxLoc(), enemy[i].getForm());
		wattroff(ship.getWin(), COLOR_PAIR(2));
	}
	hitEnemies(ship, enemy, this->_enemy_count);
	hitPlayer(ship);
}

void	Game::printAster(Ship &ship, Asteroids *aster) {
	for (int k = 0; k < _aster_count; k++) {
		wattron(ship.getWin(), COLOR_PAIR(3));
	 	mvwprintw(ship.getWin(), aster[k].getyLoc(), aster[k].getxLoc(), aster[k].getForm());
		wattroff(ship.getWin(), COLOR_PAIR(3));
	}
}

void	Game::play(Screen &screen, Ship &ship) {

	Asteroids 	aster[this->_aster_count];
	Enemy 		enemy[this->_enemy_count];
	int			count(0);

	while (ship.getLives() >= 0) {
		if (count % 3 == 0) {
			if (ship.getMv(screen) == 0)
				break ;
			for (int i = 0; i < _enemy_count; ++i)
				enemy[i].move(ship);
		}
		wclear(ship.getWin());
		wattron(ship.getWin(), COLOR_PAIR(1));
		mvwprintw(ship.getWin(), ship.getyLoc(), ship.getxLoc(), ship.getForm());
		wattroff(ship.getWin(), COLOR_PAIR(1));
		usleep(15000);
		printAll(enemy, ship, aster);
		screen.updateMenu(ship);
		wrefresh(ship.getWin());
		refresh();
		count++;
	}
}
