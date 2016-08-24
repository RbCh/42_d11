# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoy <rchoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/18 19:12:48 by rchoy             #+#    #+#              #
#    Updated: 2016/08/23 19:22:49 by rchoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = correction
EXDIR = ../../d11_v4/
CDIR = srcs/
HDIR = includes/
CSOURCES = print_list.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_strcmp.c
EXSOURCES = ex00/ft_create_elem.c ex01/ft_list_push_back.c \
			ex02/ft_list_push_front.c ex03/ft_list_size.c ex04/ft_list_last.c \
			ex05/ft_list_push_params.c ex06/ft_list_clear.c ex07/ft_list_at.c \
			ex08/ft_list_reverse.c ex09/ft_list_foreach.c \
			ex10/ft_list_foreach_if.c ex11/ft_list_find.c ex12/ft_list_remove_if.c\
			ex13/ft_list_merge.c ex14/ft_list_sort.c ex15/ft_list_reverse_fun.c \
			ex16/ft_sorted_list_insert.c ex17/ft_sorted_list_merge.c

OSOURCES = $(CSOURCES:.c=.o)
HSOURCES = ft_list.h
CSOURCESINDIR = $(addprefix $(CDIR), $(CSOURCES))
EXSOURCESINDIR = $(addprefix $(EXDIR), $(EXSOURCES))
HSOURCESINDIR = $(addprefix $(HDIR), $(HSOURCES))
GCHSOURCESINDIR= $(HSOURCESINDIR:.h=.h.gch)

all: $(NAME)

$(NAME): $(CSOURCESINDIR) $(HSOURCESINDIR) $(EXSOURCESINDIR)
	gcc -c -Wall -Wextra -Werror $(CSOURCESINDIR) $(HSOURCESINDIR) $(EXSOURCESINDIR)
	gcc -Wall -Wextra -Werror $(OSOURCES) $(notdir $(EXSOURCESINDIR:.c=.o)) -o $(NAME)
	rm -f $(OSOURCES) $(GCHSOURCESINDIR) $(notdir $(EXSOURCESINDIR:.c=.o))
clean:
	rm -f $(OSOURCES) $(GCHSOURCESINDIR) $(notdir $(EXSOURCESINDIR:.c=.o))
fclean: clean
	rm -f $(NAME)

re: fclean all
