##
## Makefile for Makefile in /home/thirie_a/rendu/Piscine_C_J10
##
## Made by jeremy thiriez
## Login   <thirie_a@epitech.net>
##
## Started on  Fri Mar 11 15:30:08 2016 jeremy thiriez
## Last update Sun May 22 14:24:51 2016 jeremy thiriez
##

CC	= gcc

O	= -o

RM	= rm -rf

NAME	= bsq

SRCS	= src/my_split.c \
	  tools/my_putstr.c \
	  tools/my_putchar.c \
	  tools/my_strlen.c \
	  tools/my_strcpy.c \
	  tools/my_getnbr.c \
	  tools/my_show_wordtab.c \
	  tools/my_put_nbr.c \
	  tools/my_show_int_tab.c \
	  src/my_bsq_algo.c \
	  tools/my_strcmp.c \
	  src/main.c

CFLAGS	+= -W -Wall -Wextra -Werror -I./include

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(O) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all re
