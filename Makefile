# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/15 19:01:32 by npineau           #+#    #+#              #
#    Updated: 2014/02/15 19:01:39 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCDIR = sources
TOKDIR = lem_token
OBJDIR = objects
INCDIR = includes
LIBDIR = libft
LIB = libft.a

OK_COLOR = \033[32;01m
ERROR_COLOR = \033[31;01m
INFO_COLOR = \033[33;01m
STOP_COLOR = \033[0m
OK = $(OK_COLOR)--> [OK]$(STOP_COLOR)

LINUX = no
CFLAGS = -Wall -Wextra -Werror
ifeq ($(DEBUG), yes)
	CC = clang
	CFLAGS += -ggdb3 -fstack-protector-all -Wshadow -Wunreachable-code \
		-Wstack-protector -pedantic-errors -O0 -W -Wundef -fno-common \
		-Wfatal-errors -Wstrict-prototypes -Wmissing-prototypes -pedantic \
		-Wwrite-strings -Wunknown-pragmas -Wdeclaration-after-statement \
		-Wold-style-definition -Wmissing-field-initializers -Wfloat-equal \
		-Wpointer-arith -Wnested-externs -Wstrict-overflow=5 -fno-common \
		-Wno-missing-field-initializers -Wswitch-default -Wswitch-enum \
		-Wbad-function-cast -Wredundant-decls -fno-omit-frame-pointer
else
	CC = gcc
	CFLAGS += -O3
endif

TOK = lem_ant.c \
	  lem_comment.c \
	  lem_end.c \
	  lem_error.c \
	  lem_link.c \
	  lem_room.c \
	  lem_start.c
SRC = check_line.c get.c get_map.c get_room.c get_token.c \
	  main.c display_map.c
OBJ = $(SRC:.c=.o) \
	  $(TOK:.c=.o)
PSRC = $(addprefix $(SRCDIR)/, $(SRC)) \
	  $(addprefix $(SRCDIR)/, $(addprefix $(TOKDIR)/, $(TOK)))
POBJ = $(addprefix $(OBJDIR)/, $(OBJ))

RM = rm -rf


all: $(LIBDIR)/$(LIB) $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "$(INFO_COLOR)Created $(OBJDIR) directory$(STOP_COLOR)"

$(LIBDIR)/$(LIB):
	@$(MAKE) -C $(LIBDIR)

$(NAME): $(POBJ)
	@$(CC) -o $@ $^ -L$(LIBDIR) -lft
	@echo "$(OK_COLOR)$(NAME) --> [Done!]$(STOP_COLOR)"

$(POBJ): |$(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<
	@echo "Compile $< to $@ $(OK)"

$(OBJDIR)/%.o: $(SRCDIR)/$(TOKDIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<
	@echo "Compile $< to $@ $(OK)"

clean:
	@$(MAKE) -C $(LIBDIR) $@
	@$(RM) $(OBJDIR)
	@echo "$(INFO_COLOR)Removed $(OBJ)$(STOP_COLOR)"

fclean: clean
	@$(MAKE) -C $(LIBDIR) $@
	@$(RM) $(NAME)
	@echo "$(INFO_COLOR)Removed $(NAME)$(STOP_COLOR)"
	@echo "$(OK_COLOR)--> [Clean!]$(STOP_COLOR)"

re: fclean all

.PHONY: all clean re fclean
