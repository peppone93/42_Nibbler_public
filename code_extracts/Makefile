#NIBBLER

NAME = nibbler

# COLOR------------------------
CLRR =\033[0;31m#red
CLRG =\033[0;32m#green
CLRB =\033[0;34m#blue
CLRC =\033[0;36m#cyan
CLRW =\033[0m#white
NIBBLER = $(CLRB)[NIBBLER]$(CLRW)
#------------------------------

FLAG = -Wall -Wextra -Werror
CLNG = clang++ $(FLAG)

SRC_D = ./CoreCode/srcs/
OBJ_D = ./CoreCode/compiled/
SRC_F = Fruit.cpp IntVec.cpp Snake.cpp SnakePart.cpp Window.cpp main.cpp grid.cpp\
	singlePlayer.cpp multiPlayer.cpp Obstacle.cpp

OBJ = $(addprefix $(OBJ_D), $(SRC_F:.cpp=.o))

SDL_D = ./SDL
SFML_D = ./SFML
GLFW_D = ./GLFW
SOUND_D = ./Mixer

all: libs $(NAME)
	@printf	"$(NIBBLER)Everything done\n"

# INCL-------------------------
INC =	-I ./CoreCode/includes/ -I ./CoreCode/interfaces
#------------------------------

# LIBS-------------------------
libs: lib_sdl lib_sfml lib_glfw lib_sound
lib_sdl:
	@make -s -C $(SDL_D)
lib_sfml:
	@make -s -C $(SFML_D)
lib_glfw:
	@make -s -C $(GLFW_D)
lib_sound:
	@make -s -C $(SOUND_D)
#------------------------------

# EXE--------------------------
$(NAME): $(OBJ_D) $(OBJ)
	@printf	"$(NIBBLER)%-49s [$(CLRR)%s$(CLRW)]" "$(NAME) compiled" "✘"
	@$(CLNG) -o nibbler $(OBJ) -ldl
	@printf	"\r$(NIBBLER)$(CLRG)%-49s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "$(NAME) compiled" "✔"
#------------------------------
# OBJ DIR----------------------
$(OBJ_D) :
	@mkdir -p $(OBJ_D)
	@printf	"$(NIBBLER)%-49s [$(CLRG)%s$(CLRW)]\n" "Repository: $@ created" "✔"
#------------------------------
# OBJECTS----------------------
$(OBJ_D)%.o : $(SRC_D)%.cpp
	@printf "$(NIBBLER)%-49s [$(CLRR)%s$(CLRW)]" "Object $@ created" "✘"
	@$(CLNG) $(INC) -c $< -o $@
	@printf "\r$(NIBBLER)%-49s [$(CLRG)%s$(CLRW)]\n" "Object $@ created" "✔"
#------------------------------

clean:
	@make -s -C $(SDL_D) clean
	@make -s -C $(SFML_D) clean
	@make -s -C $(GLFW_D) clean
	@make -s -C $(SOUND_D) clean
	@rm -rf $(OBJ_D)
	@printf	"$(NIBBLER)%-49s [$(CLRG)%s$(CLRW)]\n" "Objects removed" "∙"

fclean: clean
	@make -s -C $(SDL_D) fclean
	@make -s -C $(SFML_D) fclean
	@make -s -C $(GLFW_D) fclean
	@make -s -C $(SOUND_D) fclean
	@rm -rf $(NAME)
	@printf	"$(NIBBLER)%-49s [$(CLRG)%s$(CLRW)]\n" "File: $(NAME) removed" "∙"

hclean: fclean
	@make -s -C $(SDL_D) hclean
	@make -s -C $(SFML_D) hclean
	@make -s -C $(GLFW_D) hclean
	@make -s -C $(SOUND_D) hclean

re: fclean all

.PHONY: all re clean fclean libs
