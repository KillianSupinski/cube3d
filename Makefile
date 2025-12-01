# Program name
NAME        = cub3D

# Directories
SRCDIR      = srcs
INCDIR      = includes
OBJDIR      = objs
LIBFT_PATH  = ./libft
MLX_PATH    = ./minilibx-linux

LIBFT       = $(LIBFT_PATH)/libft.a

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
DEPFLAGS    = -MMD -MP

# MiniLibX flags (Linux)
MLX_FLAGS   = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd

# Include paths
INCLUDES    = -I$(INCDIR) -I$(LIBFT_PATH) -I$(MLX_PATH)

# Source files
SOURCES     = $(SRCDIR)/main.c \
			  $(SRCDIR)/parsing.c \
			  $(SRCDIR)/parsing_file.c \
			  $(SRCDIR)/parsing_color.c \
			  $(SRCDIR)/parsing_tex.c \
			  $(SRCDIR)/parsing_utils.c \
			  $(SRCDIR)/parsing_map.c \
			  $(SRCDIR)/parsing_tex_utils.c \
			  $(SRCDIR)/init_all_mlx.c


# Object files and dependencies
OBJS        = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS        = $(OBJS:.o=.d)

# Colors for output
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
PURPLE      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m
RESET       = \033[0m

# ASCII Art (optionnel)
CUB3D_ART   = $(BLUE)""$(RESET)

# ------------ RULES ------------ #

# Main target : construit libft + mlx + cub3D
all: $(LIBFT) mlx $(NAME)

# Build libft (crée libft.a)
$(LIBFT):
	@printf "$(BLUE)Building $(CYAN)libft$(BLUE)...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory

# Build MiniLibX
mlx:
	@printf "$(BLUE)Building $(CYAN)MiniLibX$(BLUE)...$(RESET)\n"
	@$(MAKE) -C $(MLX_PATH) --no-print-directory

# Create object directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling $(CYAN)%-40s$(YELLOW) -> $(GREEN)%s$(RESET)\n" "$<" "$@"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

# Link program
$(NAME): $(OBJS)
	@printf "$(PURPLE)Linking $(CYAN)$(NAME)$(PURPLE)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(CUB3D_ART)"
	@printf "$(GREEN)✅ $(WHITE)$(NAME) $(GREEN)compiled successfully!$(RESET)\n\n"

# Clean object files
clean:
	@printf "$(RED)Cleaning object files...$(RESET)\n"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory
	@$(MAKE) -C $(MLX_PATH) clean --no-print-directory || true
	@printf "$(GREEN)✅ Object files cleaned!$(RESET)\n"

# Full clean
fclean: clean
	@printf "$(RED) Removing $(CYAN)$(NAME)$(RED)...$(RESET)\n"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory
	@printf "$(GREEN)✅ Full clean completed!$(RESET)\n"

# Rebuild (cible que tu veux)
re: fclean all
	@printf "$(CYAN)🔄 Rebuild completed!$(RESET)\n"

# Debug target
debug: CFLAGS += -DDEBUG -fsanitize=address
debug: re
	@printf "$(YELLOW) Debug version built with AddressSanitizer$(RESET)\n"

# Run target
run: all
	@printf "$(GREEN) Running $(CYAN)$(NAME)$(GREEN)...$(RESET)\n"
	@./$(NAME)

# Include dependencies
-include $(DEPS)

.PHONY: all clean fclean re libft mlx debug run
