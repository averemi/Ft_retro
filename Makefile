NAME = ft_retro

SRC = Asteroids.cpp Enemy.cpp Game.cpp Objects.cpp \
		Player.cpp Screen.cpp Shoot.cpp Ship.cpp \
		main.cpp BulletArr.cpp EnemyBulletArr.cpp \
		detectResize.cpp

SRCDIR=src
OBJDIR=obj
INCDIR=inc

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98 -I$(INCDIR)

CC = clang++

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $@

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	$(CC) $(CFLAGS) $^ -o $(NAME) -lncurses

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.cpp)
	$(CC) $(CFLAGS) -c  -o $@ $< 

clean:
	rm -rf $(OBJDIR)

fclean:
	rm -rf $(OBJDIR)
	rm -f $(NAME)

re: fclean all


