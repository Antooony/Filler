# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:01:35 by adenis            #+#    #+#              #
#    Updated: 2017/04/21 14:49:27 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	adenis.filler
FLAGS			=	-Wall -Wextra -Werror

SRC				=	main.c ./srcs/parsing.c ./srcs/place.c ./srcs/various.c \
					./srcs/fill_st.c ./srcs/target_search.c

LIB				=	./libft/libft.a

HEADER 			=	filler.h
LIB_PATH		=	./libft

OBJS			=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIB)
	@$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $<

clean :
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re : fclean all
