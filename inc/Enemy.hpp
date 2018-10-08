


#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "ft_retro.h"
# include "Objects.hpp"
# include "Ship.hpp"

class Enemy : public Objects {
	private:
		int _collide;

	void	changey(Ship &ship);	

	public:
		Enemy();
		~Enemy();
		Enemy(Enemy const & a);
		Enemy& operator=(Enemy const &a);

		void	move(Ship & ship);
		void	recreate();
		void	shoot();
		int		checkCollision(Ship & ship, int x, int y);

};


#endif

