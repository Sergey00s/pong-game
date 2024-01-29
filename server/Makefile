NAME=pong_server
CC=gcc
SRC= main.c \
		vector.c \
		game.c


OBJ= $(SRC:.c=.o)
FLAGS= #-Wall -Wextra -Werror
LIBLIST = ./linked_list/liblist.a

LIBS= -lm $(LIBLIST)
INC= -I./linked_list

all: $(LIBLIST) $(NAME)


$(LIBLIST):
	make -C ./linked_list

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)


%.o: %.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
ffclean: fclean
	make -C ./linked_list fclean

re: fclean all

run: all
	./$(NAME)

.PHONY: clean fclean re all



