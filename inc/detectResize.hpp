#ifndef FT_DETECTRESIZE_H
# define FT_DETECTRESIZE_H

# include <csignal>
# include <iostream>
# include <ncurses.h>

void    handle_winch(void);
void    winch_callback(int signo);

#endif