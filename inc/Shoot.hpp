

#ifndef SHOOT_HPP
# define SHOOT_HPP

# include "ft_retro.h"
# include "Objects.hpp"
# include "Enemy.hpp"

class Shoot : public Objects {
	private:
		WINDOW *_shootwin;
		int		_parent;
	public:
		Shoot();
		Shoot(int parent);
		~Shoot();
		Shoot(Shoot const &a);
		Shoot& operator=(Shoot const &a);

		int		getParent() const;

		int		shootEnemy(Enemy *enemy, int enemy_count);
		void	move(int dir);
};

#endif

