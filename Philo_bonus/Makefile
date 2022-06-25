NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRC = ft_utils.c args_bonus.c  philo_bonus.c time.c death_bonus.c routine.c ft_free_bonus.c

OBJS = $(SRC:.c=.o)

%.o:%.c
	@$(CC) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJS) philo.h
	@$(CC) $(OBJS) 	-o philo


clean :
	@rm -f $(OBJS) 

fclean : clean
	@rm -f $(NAME) 

re : fclean all