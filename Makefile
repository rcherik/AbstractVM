# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcherik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/14 16:49:57 by rcherik           #+#    #+#              #
#    Updated: 2016/10/14 16:49:58 by rcherik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AbstractVM
CLASS = Parse.cpp Factory.cpp Emulator.cpp
SRC = main.cpp
SRC += $(CLASS)
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++11 -Ofast
OBJ = $(SRC:%.cpp=$(ODIR)/%.o)
HEADERS =
HEADERSPATH = $(HEADERS:%.hpp=$(IDIR)/%.hpp)
HEADERSPATH += $(CLASS:%.cpp=$(IDIR)/%.hpp)
SRCDIR = srcs
IDIR = includes
ODIR = objs

all: $(ODIR) $(NAME)

$(ODIR):
	@mkdir -p $(ODIR)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $(OBJ) -I$(IDIR)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(HEADERSPATH)
	@$(CC) $(FLAGS) -o $@ -c $< -I $(IDIR)

clean:
	@rm -f $(OBJ)

fclean: clear clean
	@rm -rf $(ODIR)
	@rm -f $(NAME)

re: fclean all

clear:
	@rm -f *~
	@rm -f **/*~
