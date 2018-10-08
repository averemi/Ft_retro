

#ifndef BULLETARR_HPP
# define BULLETARR_HPP

# include "Ship.hpp"
# include "Shoot.hpp"
# include "Enemy.hpp"

class BulletArr {
	private:

		BulletArr();
		BulletArr(const BulletArr &obj);

		BulletArr			&operator=(const BulletArr &obj);

		Shoot				*_init();

		Shoot 				*_bullet_arr;
		int					_bullet_count;

		static	BulletArr	*_bullet_ptr;
		const static int	_max_bullets;

	public:
		~BulletArr();

		static BulletArr	*BulletARR();

		void				addBullet(int x, int y, int xmax);
		void				delBullet(int num);
		int					getBulletCount() const;

		void				hitEnemies(Ship &ship, Enemy *enemy, int enemy_count);

};

void		shoot(const Ship &ship);
void		hitEnemies(Ship &ship, Enemy *enemy, int enemy_count);

#endif

