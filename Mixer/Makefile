#Mixer

NAME = ../sound.so

# COLOR------------------------
CLRR = \033[0;31m
CLRG = \033[0;32m
CLRC = \033[0;36m
CLRW = \033[0m
LIBSDL = $(CLRC)[LIBSND]$(CLRW)
#------------------------------

FLAG = -Wall -Wextra -Werror
FPIC = -fPIC
SHARE = -shared
CLNG = clang++ $(FLAG)

SRC_D = ./
OBJ_D = ./compiled/
SRC_F = Mixer.cpp
OTH_I = -I ../CoreCode/includes/ -I ../CoreCode/interfaces

OBJ = $(addprefix $(OBJ_D), $(SRC_F:.cpp=.o))
MUTE = >/dev/null 2>/dev/null
TEMP = ./.make.temp

all : install $(NAME)

# INSTALL----------------------
install: $(TEMP)

$(TEMP):
	@printf	"$(LIBSDL)%-50s [$(CLRR)%s$(CLRW)]" "Lib SDLMixer installed" "✘"
	@sudo apt-get -q -qq install -y libsdl2-mixer-dev $(MUTE)
	@printf	"\r$(LIBSDL)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Lib SDLMixer installed" "✔"
	@touch $(TEMP)
#------------------------------

$(NAME) : $(OBJ_D) $(OBJ)
	@printf	"$(LIBSDL)%-50s [$(CLRR)%s$(CLRW)]" "Lib SDLMixer compiled" "✘"
	@$(CLNG) $(OBJ) $(SHARE) $(FPIC) -lSDL2_mixer `sdl2-config --libs` -o $(NAME) $(OTH_I)
	@printf	"\r$(LIBSDL)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Lib SDLMixer compiled" "✔"	
#1
$(OBJ_D) :
	@mkdir -p $(OBJ_D)
	@printf	"$(LIBSDL)%-50s [$(CLRG)%s$(CLRW)]\n" "Repository: $@ created" "✔"
#2
$(OBJ_D)%.o : $(SRC_D)%.cpp
	@printf	"$(LIBSDL)%-50s [$(CLRR)%s$(CLRW)]" "Object: $@ created" "✘"
	@$(CLNG) $(FPIC) -o $@ -c $< $(OTH_I)
	@printf	"\r$(LIBSDL)%-50s [$(CLRG)%s$(CLRW)]\n" "Object: $@ created" "✔"

.PHONY : clean fclean re dir install
.NOTPARALLEL : $(OBJ)

clean :
	@rm -rf $(OBJ_D)
	@printf	"$(LIBSDL)%-50s [$(CLRG)%s$(CLRW)]\n" "Objects removed" "∙"

fclean : clean
	@rm -f $(NAME)
	@printf	"$(LIBSDL)%-50s [$(CLRG)%s$(CLRW)]\n" "File: $(NAME) removed" "∙"

hclean: fclean
	@sudo apt-get -q -qq remove -y libsdl2-mixer-dev $(MUTE)
	@printf	"$(LIBSDL)%-50s [$(CLRG)%s$(CLRW)]\n" "Lib SDLMixer uninstalled" "∙"
	@sudo rm $(TEMP)

re : fclean all
