

#ifndef GAME_HPP
# define GAME_HPP

# include "ft_retro.h"
# include "Screen.hpp"
# include "Ship.hpp"
# include "Asteroids.hpp"
# include "Enemy.hpp"

class Game {
	private:
		int	_enemy_count;
		int _aster_count;
		int _count;

		void	printAster(Ship &ship, Asteroids * aster);

	public:
		Game();
		~Game();
		Game(Game const &a);
		Game& operator=(Game const &a);

		void	play(Screen &screen, Ship &ship);
		void	printAll(Enemy *enemy, Ship &ship, Asteroids *aster);
		int		getEnemyCount();

};

#endif

