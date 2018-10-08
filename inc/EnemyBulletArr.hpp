

#ifndef ENEMYBULLETARR_HPP
# define ENEMYBULLETARR_HPP

# include "Ship.hpp"
# include "Shoot.hpp"

class EnemyBulletArr {
	private:

		EnemyBulletArr();
		EnemyBulletArr(const EnemyBulletArr &obj);

		EnemyBulletArr			&operator=(const EnemyBulletArr &obj);

		Shoot					*_init();

		Shoot 					*_bullet_arr;
		int						_bullet_count;

		static	EnemyBulletArr	*_bullet_ptr;
		const static int		_max_bullets;

	public:
		~EnemyBulletArr();

		static EnemyBulletArr	*EnemyBulletARR();

		void					addBullet(int x, int y);
		void					delBullet(int num);
		int						getBulletCount() const;

		void					hitShip(Ship &ship);

};

void		hitPlayer(Ship &ship);

#endif
