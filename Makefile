# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:01:35 by adenis            #+#    #+#              #
#    Updated: 2017/03/03 17:05:39 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	adenis.filler
FLAGS			=	-Wall -Wextra -Werror

SRC				=	main.c ./srcs/parsing.c ./srcs/place.c ./srcs/various.c ./srcs/fill_st.c

LIB				=	./libft/libft.a

HEADER 			=	filler.h
LIB_PATH		=	./libft

OBJS			=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIB)
	@$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)
	@$(CC) $(FLAGS) ./srcs/graph.c $(LIB) -o Graph

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $<

clean :
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME)
	@rm -f Graph
	@make fclean -C ./libft

re : fclean all
