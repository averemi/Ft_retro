


#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "ft_retro.h"

class Player {
	protected:
		int _score;
		time_t _time;
		int	   _lives;
		int	   _level;
	public:
		Player();
		~Player();
		Player(Player const & a);
		Player& operator=(Player const &a);

		int 	getScore();
		time_t 	getTime();
		int		getLives();
		int 	getLevel();
		void 	setScore(int score);
		void 	setTime(time_t time);
		void 	setLevel(int level);
		void 	setLives(int lives);

		void	addLevel();
		void	addScore();
		void	takeDamage();



};


#endif
