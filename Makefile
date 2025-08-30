
# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC		= pipex.c utils.c \
		  libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strdup.c \
		  libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncmp.c \
		  libft/ft_substr.c
OBJ		= $(SRC:.c=.o)

INCLUDE = pipex.h

# --------------------------------- RULES --------------------------------- #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔗 Linking objects into $(NAME)..."
	@$(CC) $(OBJ) -o $(NAME)
	@echo "✅ Build complete!"

%.o: %.c $(INCLUDE)
	@echo "⚙️  Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	@$(RM) $(OBJ)

fclean: clean
	@echo "🗑️  Removing executable..."
	@$(RM) $(NAME)
	@echo "💨 Full clean done!"

re: fclean all
	@echo "🔄 Rebuilt everything!"

.PHONY: all clean fclean re
