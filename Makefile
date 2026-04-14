##
## Makefile for make in /home/arthok/Rendu/C/PSU_2016_myftp
## 
## Made by Arthur XXXXXX
## Login   <arthur.XXXXXX@epitech.eu>
## 
## Started on  Mon May 15 13:30:27 2017 Arthur XXXXXX
## Last update Sat May 20 14:34:31 2017 Arthur XXXXXX
##

CC =		gcc

RM =		rm -f

NAME =		server

SRC =		./src/server.c \
		./src/ftp.c \
		./src/str_to_wordtab.c \
		./src/commands.c \
		./src/commands2.c

OBJ =		$(SRC:.c=.o)

CFLAGS +=	-Wall -Wextra -Werror -I./include

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		clean fclean all
