#include "detectResize.hpp"

void    winch_callback(int signo) {
    if (signo == SIGWINCH) {
        clear();
        endwin();

        std::cout << "Window resize is not allowed" << std::endl;
        std::cout << std::endl;
        exit(0);
    }
}

void    handle_winch(void) {
    signal(SIGWINCH, winch_callback);
}
