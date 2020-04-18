# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/12 07:07:02 by mavileo           #+#    #+#              #
#    Updated: 2020/04/17 20:57:04 by mavileo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c		\
					utils.c		\
					struct.c		\
					start.c		\
					ft_atoi.c	\
					print_states.c	\
					
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
LIBS			= -lpthread -lrt

NAME			= philo_three

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re