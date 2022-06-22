NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRC = ft_utils.c args.c  philo.c time.c death.c

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