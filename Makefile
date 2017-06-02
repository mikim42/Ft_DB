# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 19:14:03 by mikim             #+#    #+#              #
#    Updated: 2017/05/05 17:22:32 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c main_tool.c init.c check.c add.c add_tool.c search.c update.c\
	  delete.c save.c update_tool.c delete_tool.c search_tool.c renew.c
OBJ = $(SRC:.c=.o)

SRCDIR = srcs
OBJDIR = objs
LFTDIR = libft

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LFT = -L $(LFTDIR) -lft
HEADER = -I includes -I $(LFTDIR)/includes

CC = gcc
WFLAGS = -Wall -Werror -Wextra

NAME = ft_db

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(WFLAGS) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@make -C $(LFTDIR)
	@$(CC) $(WFLAGS) $(OBJS) $(HEADER) $(LFT) -o $@
	@echo "[Ft_DB - 모래반지 빵야빵야!]"

clean:
	@make -C $(LFTDIR) clean
	@/bin/rm -rf $(OBJDIR)
	@echo "[Ft_DB - clean]"

fclean:
	@make -C $(LFTDIR) fclean
	@/bin/rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@echo "[Ft_DB - fclean]"

re: fclean all
