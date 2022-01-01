#SDL

NAME = ../sdl.so

# COLOR------------------------
CLRR = \033[0;31m
CLRG = \033[0;32m
CLRC = \033[0;36m
CLRW = \033[0m
LIBSDL = $(CLRC)[LIBSDL]$(CLRW)
#------------------------------

FLAG = -Wall -Wextra -Werror
FPIC = -fPIC
SHARE = -shared
CLNG = clang++ $(FLAG)

SRC_D = ./
OBJ_D = ./compiled/
SRC_F = Sdl.cpp
OTH_F = ../CoreCode/srcs/IntVec.cpp
OTH_I = -I ../CoreCode/includes/ -I ../CoreCode/interfaces

OBJ = $(addprefix $(OBJ_D), $(SRC_F:.cpp=.o))
MUTE = >/dev/null 2>/dev/null
TEMP = ./.make.temp

all : install $(NAME)

# INSTALL----------------------
install: $(TEMP)

$(TEMP):
	@printf	"$(LIBSDL)%-50s [$(CLRR)%s$(CLRW)]" "Lib SDL installed" "✘"
	@sudo apt-get -q -qq install -y libsdl2-dev $(MUTE)
	@printf	"\r$(LIBSDL)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Lib SDL installed" "✔"	
	@touch $(TEMP)
#------------------------------

$(NAME) : $(OBJ_D) $(OBJ)
	@printf	"$(LIBSDL)%-50s [$(CLRR)%s$(CLRW)]" "Lib SDL compiled" "✘"
	@$(CLNG) $(OBJ) $(OTH_F) $(SHARE) $(FPIC) -lSDL2 `sdl2-config --libs` -o $(NAME) $(OTH_I)
	@printf	"\r$(LIBSDL)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Lib SDL compiled" "✔"	
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
	@sudo apt-get -q -qq remove -y libsdl2-dev $(MUTE)
	@printf	"$(LIBSDL)%-50s [$(CLRG)%s$(CLRW)]\n" "SDL uninstalled" "∙"
	@sudo rm $(TEMP)

re : fclean all
