CC = gcc
SRC = $(wildcard *.c) 
NAME = btree
CFLAGS = -Wall -Werror -Wextra -pedantic

all : $(NAME) oclean

$(NAME) : binary_trees.h $(SRC)
	$(CC) $^ -g -o $@ -lm

.PHONY : clean oclean fclean re

clean :
	$(RM) *.swap $(NAME)
		
oclean :
	$(RM) $(OBJ)

fclean : clean oclean

re : fclean all
