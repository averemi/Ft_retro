

#ifndef OBJECTS_HPP
# define OBJECTS_HPP

# include "ft_retro.h"

class Objects {
	protected:
		int _xLoc;
		int _yLoc;
		int _xMax;
		int _yMax;
		const char * _form;

	public:
		Objects();
		~Objects();
		Objects(Objects const & a);
		Objects& operator=(Objects const &a);

		int		getxLoc() const;
		int		getyLoc() const;
		int		getxMax() const;
		void	setxLoc(int x);
		void	setyLoc(int y);
		void	setxMax(int xMax);
		void	setyMax(int yMax);
		const char * getForm();
		void	setForm(const char* form);
		void	swap(Objects &obj);
};


#endif
