# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:15:41 by npineau           #+#    #+#              #
#    Updated: 2014/03/18 13:05:06 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	lem-in

### DIRECTORIES ###

DIRSRC		:=	sources
DIROBJ		:=	objects
DIRTOK		:=	$(DIRSRC)/lem_token
DIRBASE		:=	$(DIRSRC)/base
DIRLIB		:=	libft
DIRINC		:=	includes

### FILES ###

### FILES: SOURCES ###

TOK		:=	lem_start.c \
			lem_room.c \
			lem_link.c \
			lem_error.c \
			lem_end.c \
			lem_comment.c \
			lem_ant.c



BASE	:=	put_weight.c \
			main.c \
			get_token.c \
			get_room.c \
			get_map.c \
			get.c \
			display_map.c \
			display_ants.c \
			check_line.c

### FILES: OBJECTS ###

OBJ			:=	$(BASE:.c=.o) \
				$(TOK:.c=.o)

### FILES: PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))
INC			:=	$(DIRLIB)/$(DIRINC)/libft.h \
				$(DIRINC)/parse.h \
				$(DIRINC)/lem-in.h
PLIB		:=	$(DIRLIB)/libft.a

### COMPILATION ###

CC			:=	gcc
C_FLAG		:=	-Wall -Wextra -Werror
O_FLAG		:=	-O3
C_OPT		=	-o $@ -c $< -I $(DIRINC) -I $(DIRLIB)/$(DIRINC)
L_FLAG		=	-L $(DIRLIB) -lft

COMPIL		=	$(CC) $(C_FLAG) $(O_FLAG) $(C_OPT)
LINK		=	$(CC) -o $(NAME) $^ $(L_FLAG)

### RULES ###

all: $(NAME)

$(NAME): $(PLIB) $(POBJ)
	$(LINK)

$(PLIB):
	make -C $(DIRLIB)

### RULES: COMPILATION ###

$(DIROBJ)/%.o: $(DIRBASE)/%.c $(INC)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRTOK)/%.c $(INC)
	$(COMPIL)

### RULES: MISC ###

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

clean:
	@(rm -f $(POBJ))

fclean: clean
	@(rm -f $(NAME))

re: fclean $(NAME)

.PHONY: all clean re fclean
