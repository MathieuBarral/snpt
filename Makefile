CC		=	gcc
CPPFLAGS 	= 	-I include
CFLAGS		=	-Wall -Wextra
LDFLAGS		= 	-luuid
SRC		=	$(wildcard src/*.c)
NAME		= 	libsnpt.so

all:	$(NAME)

$(NAME):
	@ echo "\033[1;37mSnpt Library Compilation...\033[0m"
	@ $(CC) -c $(SRC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
	@ $(CC) -o $(NAME) *.o $(CFLAGS) -fPIC -shared 
	@ echo "\033[1;34m[OK] \033[1;32mCompiled Snpt Library\033[0m\033[1;31m [$(NAME)]\033[0m"

clean:
	@ $(RM) *.o
	@ echo "\033[1;34m[OK] \033[1;32mSnpt Library Object Cleaned\033[0m\033[1;31m [$(NAME)]\033[0m"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "\033[1;34m[OK] \033[1;32mSnpt Library cleaned\033[0m"

re:	fclean all