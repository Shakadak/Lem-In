# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2017/10/27 10:39:27 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	lem-in

### DIRECTORIES ###

DIRSRC	:=	src
DIROBJ	:=	obj
DIRINC	:=	inc
DIRLIB	:=	libft

### FILES ###

include $(DIRSRC)/src.mk

LIB		:=	libft.a

### PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))
PHEAD		:=	$(DIRINC)/lem-in.h
PLIB		:=	$(DIRLIB)/$(LIB)

### COMPILATION VARIABLES ###


CC		:=	clang
C_FLAG	:=	-Wall -Wextra -Werror -pedantic
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC) -I .

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

.PHONY: all clean fclean re

all: $(PLIB) $(NAME)

run: all
	./lem-in < base_ants_letter.map
	./lem-in < base_ants_nl.map
	./lem-in < base_ants_noline.map
	./lem-in < base_ants_num+letters.map
	./lem-in < base.map
	./lem-in < base_rooms_command+comment.map

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJ): |$(DIROBJ)

### EXECUTABLE ###

$(NAME): $(PLIB) $(POBJ)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
