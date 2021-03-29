#SDL

NAME = ../glfw.so

# COLOR------------------------
CLRR = \033[0;31m
CLRG = \033[0;32m
CLRC = \033[0;36m
CLRW = \033[0m
LBGLFW = $(CLRC)[LBGLFW]$(CLRW)
#------------------------------

FLAG = -Wall -Wextra -Werror
FPIC = -fPIC
SHARE = -shared
CLNG = clang++ $(FLAG)

SRC_D = ./
OBJ_D = ./compiled/
SRC_F = Glfw.cpp
OTH_F = ../CoreCode/srcs/IntVec.cpp
OTH_I = -I ../CoreCode/includes/ -I ../CoreCode/interfaces

OBJ = $(addprefix $(OBJ_D), $(SRC_F:.cpp=.o))
MUTE = >/dev/null 2>/dev/null
TEMP = ./.make.temp

MMT = -lGL -lGLU `pkg-config --libs glfw3`

all : install $(NAME)

# INSTALL----------------------
install: $(TEMP)

$(TEMP):
	@printf	"$(LBGLFW)%-50s [$(CLRR)%s$(CLRW)]" "Lib GLFW installed" "✘"
	@sudo apt-get -q -qq install -y libglfw3-dev $(MUTE)
	@printf	"\r$(LBGLFW)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Lib GLFW installed" "✔"
	@touch $(TEMP)
#------------------------------

$(NAME) : $(OBJ_D) $(OBJ)
	@printf	"$(LBGLFW)%-50s [$(CLRR)%s$(CLRW)]" "Lib GLFW compiled" "✘"
	@$(CLNG) $(MMT) $(OBJ) $(OTH_F) $(SHARE) $(FPIC) -o $(NAME) $(OTH_I)
	@printf	"\r$(LBGLFW)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Lib GLFW compiled" "✔"	
#1
$(OBJ_D) :
	@mkdir -p $(OBJ_D)
	@printf	"$(LBGLFW)%-50s [$(CLRG)%s$(CLRW)]\n" "Repository: $@ created" "✔"
#2
$(OBJ_D)%.o : $(SRC_D)%.cpp
	@printf	"$(LBGLFW)%-50s [$(CLRR)%s$(CLRW)]" "Object: $@ created" "✘"
	@$(CLNG) $(FPIC) -o $@ -c $< $(OTH_I)
	@printf	"\r$(LBGLFW)%-50s [$(CLRG)%s$(CLRW)]\n" "Object: $@ created" "✔"

.PHONY : clean fclean re dir install
.NOTPARALLEL : $(OBJ)

clean :
	@rm -rf $(OBJ_D)
	@printf	"$(LBGLFW)%-50s [$(CLRG)%s$(CLRW)]\n" "Objects removed" "∙"

fclean : clean
	@rm -f $(NAME)
	@printf	"$(LBGLFW)%-50s [$(CLRG)%s$(CLRW)]\n" "File: $(NAME) removed" "∙"

hclean: fclean
	@sudo apt-get -q -qq remove -y libglfw3-dev $(MUTE)
	@printf	"$(LBGLFW)%-50s [$(CLRG)%s$(CLRW)]\n" "Lib GLFW uninstalled" "∙"
	@sudo rm $(TEMP)

re : fclean all
