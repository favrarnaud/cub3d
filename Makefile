# Color Name
GREEN			=	\033[1;32m
YELLOW			= 	\033[33m
BLUE			=	\033[0;34m
BG_GREEN		=	\033[42m
BG_CYAN			=	\033[46m
ENDCOLOR		=	\033[0m

NAME			:=	cub3d

LIBS			:=	ft mlx
LIBS_TARGET		:=	libs/libft/libft.a libs/miniLibX/libmlx.a

INCS			:=	include \
					libs/libft/gnl/include \
					libs/libft/libft/include


SRC_DIR			:=	src

SRCS			:=	main.c \
					debug.c \
					raycast/main_raycast.c \
					raycast/raycast_utils.c \
					raycast/raycast_utils2.c \
					raycast/init_textures.c \
					mlx/init_mlx.c \
					mlx/handler.c \
					mlx/key_movement.c \
					mlx/key_rotation.c \
					mlx/draw.c \
					data/init_data.c\
					utils/block_utils.c \
					utils/draw_utils.c \
					utils/malloc.c \
					utils/color_utils.c \
					utils/read_utils.c \
					utils/error.c \
					check_data/read_input.c \
					check_data/read_input2.c \
					check_data/fill_data.c \
					check_data/data_utils.c \
					check_data/check_texture.c \
					check_data/check_map.c \
					check_data/check_map2.c \
					check_data/map_utils.c \
					check_data/map_utils2.c \
					check_data/free_data.c \
					draw_test.c \

SRCS			:=	$(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR		:=	.build
OBJS			:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS			:=	$(OBJS:.o=.d)

CC				:=	gcc
CFLAGS			:=
CPPFLAGS		:=	$(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS			:=	$(addprefix -L,$(dir $(LIBS_TARGET))) 
LDLIBS			:=	$(addprefix -l,$(LIBS))

RM				:=	rm -f
DIR_DUP			=	mkdir -p $(@D)

all: $(NAME)
	@echo "$(GREEN)Your cub3d is ready to go !$(ENDCOLOR)"

$(NAME): $(LIBS_TARGET) $(OBJS)
	@tput setaf 2; cat ascii_art/cub3d_ascii; tput setaf 7
	@echo "$(BLUE)Compilation des objets lier a cub3d en cours"
	@$(CC) -Llibs/miniLibX -Llibs/libft -framework OpenGL -framework AppKit $(LDLIBS) $(OBJS) -o $(NAME) -g3

$(LIBS_TARGET):
	@$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@$(MAKE) -C libs/libft fclean
	@$(RM) $(NAME)
	@$(RM) -rf .build

re:
	@$(MAKE) fclean
	@$(MAKE) all

leaks: all
	leaks --atExit -- ./cub3d maps/map_test.cub

run: all
	./cub3d maps/map_test.cub

debug: fclean $(LIBS_TARGET) $(OBJS)
	@tput setaf 2; cat ascii_art/cub3d_ascii; tput setaf 7
	@echo "$(BLUE)Compilation des objets lier a cube3d en cours"
	@$(CC) -Llibs/miniLibX -Llibs/libft -framework OpenGL -framework AppKit $(LDLIBS) $(OBJS) -o $(NAME) -g3 -fsanitize=address

.PHONY: all clean fclean re leaks debug