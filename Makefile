# Cub3D - 3D Game like Wolfenstein

# Compile informations
NAME	=	cub3D
FLAGS	=	-Wall -Wextra -Werror -g
MLX_INCLUDE =	-Lmlx/ -lmlx -L/usr/lib/ -lXext -lX11 -lm -I ./ -I ./mlx/

#All sources files to compile
SRC = src/
SRC_FILES	=	$(wildcard $(SRC)/*.c)
OBJS		=	$(addprefix $(SRC_FOLDER), $(SRC_FILES:.c=.o))

#Minilibx files

#Some colors
GREEN	=	\033[0;32m
RED		=	\033[0;31m
DEFAULT	=	\033[0m
ORANGE =   \033[0;33m

# Rules
%.o: %.c
	@echo "$(ORANGE) Compiling...$<$(DEFAULT)"
	@gcc $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	@clear
	@printf "$(GREEN)  _____         _      ____   _____\n"
	@printf " / ____|       | |    |___ \ |  __ \\n"
	@printf "| |      _   _ | |__    __) || |  | |\n"
	@printf "| |     | | | || '_ \  |__ < | |  | |\n"
	@printf "| |____ | |_| || |_) | ___) || |__| |\n"
	@printf "| |____ | |_| || |_) | ___) || |__| |\n"
	@printf "                                                  \n"
	@echo "$(ORANGE) Compiling minishell$(RED)...$(DEFAULT)"
	@gcc $(FLAGS) $(OBJS) $(MLX_INCLUDE) -o $(NAME)
	@echo "$(GREEN) $(NAME) is ready$(DEFAULT)"

all:	$(NAME)

clean:
	@echo "$(RED) Cleaning..$(NAME)$(DEFAULT)"
	@rm -rf $(OBJS)

fclean:		clean
	@rm -f $(NAME)
	@echo " $(RED)$(NAME) is cleaned$(DEFAULT)"

re:		fclean all
		@echo "$(ORANGE) $(NAME) recompiled successfully$(DEFAULT)"

norm:
	@echo "$(GREEN)Checking norm$(DEFAULT)"
	@norminette $(SRC_FOLDER) | grep -B 1 "Error" || echo "$(GREEN)Norme OK$(DEFAULT)"

.PHONY: all clean fclean re norm
	@echo "$(RED)Cleaning $(NAME)$(DEFAULT)"
	@rm -rf $(NAME)
