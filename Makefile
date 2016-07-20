# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:15:41 by npineau           #+#    #+#              #
#    Updated: 2014/08/04 13:06:45 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	lem-in

### DIRECTORIES ###

DIRSRC		:=	src
DIROBJ		:=	obj
DIRTOK		:=	$(DIRSRC)/lem_token
DIRBASE		:=	$(DIRSRC)/base
DIRLIB		:=	libft
DIRINC		:=	inc

### FILES ###

### FILES: SOURCES ###

include $(DIRTOK)/src.mk
include $(DIRBASE)/src.mk

### FILES: PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))
INC			:=	$(DIRLIB)/$(DIRINC)/libft.h \
				$(DIRINC)/parse.h \
				$(DIRINC)/lem-in.h
PLIB		:=	$(DIRLIB)/libft.a

### COMPILATION ###

CC			:=	clang
C_FLAG		:=	-Wall -Wextra -Werror
O_FLAG		:=	-O3
C_OPT		=	-o $@ -c $< -I $(DIRINC) -I $(DIRLIB)/$(DIRINC) -I .
L_FLAG		=	-L $(DIRLIB) -lft

COMPIL		=	$(CC) $(C_FLAG) $(O_FLAG) $(C_OPT)
LINK		=	$(CC) -o $(NAME) $^ $(L_FLAG)

### RULES ###

all: $(NAME)

$(NAME): $(PLIB) $(POBJ)
	$(LINK)

$(PLIB):
	make -C $(DIRLIB)

### RULES: MISC ###

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

clean:
	rm -f $(POBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

run: all
	./lem-in < base.map

.PHONY: all clean re fclean
