

#ifndef ASTEROIDS_HPP
# define ASTEROIDS_HPP

#include "ft_retro.h"
#include "Objects.hpp"

class Asteroids : public Objects {
	public:
		Asteroids();
		~Asteroids();
		Asteroids(Asteroids const & a);
		Asteroids& operator=(Asteroids const & a);
};

#endif
