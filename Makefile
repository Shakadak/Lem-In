# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/31 16:16:53 by jibanez           #+#    #+#              #
#    Updated: 2014/02/11 16:06:08 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCDIR = sources
OBJDIR = objects
INCDIR = includes
LIBDIR = libft
LIB = libft.a

OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
INFO_COLOR = \x1b[33;01m
STOP_COLOR = \x1b[0m
OK = $(OK_COLOR)--> [OK]$(STOP_COLOR)

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

SRC = main.c
OBJ = $(SRC:.c=.o)
PSRC = $(addprefix $(SRCDIR)/, $(SRC))
POBJ = $(addprefix $(OBJDIR)/, $(OBJ))

RM = rm -rf


all: $(LIBDIR)/$(LIB) $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "$(INFO_COLOR)Created objs directory$(STOP_COLOR)"

$(LIBDIR)/$(LIB):
	@$(MAKE) -C $(LIBDIR)

$(NAME): $(POBJ)
	$(CC) -o $@ $^ -L$(LIBDIR) -lft
	@echo "$(OK_COLOR)raytracer_v1 --> [Done!]$(STOP_COLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<
	@echo "Compile $< to $@ $(OK)"

clean:
	$(MAKE) -C $(LIBDIR) $@
	@$(RM) $(OBJDIR)
	@echo "$(INFO_COLOR)Removed $(OBJ)$(STOP_COLOR)"

fclean: clean
	$(MAKE) -C $(LIBDIR) $@
	$(RM) $(NAME)
	@echo "$(INFO_COLOR)Removed $(NAME)$(STOP_COLOR)"
	@echo "$(OK_COLOR)--> [Clean!]$(STOP_COLOR)"

re: fclean all

.PHONY: all clean re fclean
