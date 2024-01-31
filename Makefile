CC = gcc
SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
NAME = btree
CFLAGS = -Wall -Werror -Wextra -pedantic

all : $(NAME) oclean

$(NAME) : binary_trees.h $(OBJ)
	$(CC) $^ -g -o $@

.PHONY : clean oclean fclean re

clean :
	$(RM) *.swap $(NAME)
		
oclean :
	$(RM) $(OBJ)

fclean : clean oclean

re : fclean all
