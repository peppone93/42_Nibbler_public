#SFML

NAME = ../sfml.so

# COLOR------------------------
CLRR = \033[0;31m
CLRG = \033[0;32m
CLRC = \033[0;36m
CLRW = \033[0m
LBSFML = $(CLRC)[LBSFML]$(CLRW)
#------------------------------

FLAG = -Wall -Wextra -Werror
FPIC = -fPIC
SHARE = -shared
CLNG = clang++ $(FLAG)

SRC_D = ./
OBJ_D = ./compiled/
SRC_F = Sfml.cpp
OTH_F = ../CoreCode/srcs/IntVec.cpp
OTH_I = -I ../CoreCode/includes/ -I ../CoreCode/interfaces

OBJ = $(addprefix $(OBJ_D), $(SRC_F:.cpp=.o))
MUTE = >/dev/null 2>/dev/null
TEMP = ./.make.temp

all : install $(NAME)

# INSTALL----------------------
install: $(TEMP)

$(TEMP):
	@printf	"$(LBSFML)%-50s [$(CLRR)%s$(CLRW)]" "Lib SFML installed" "✘"
	@sudo apt-get -q -qq install -y libsfml-dev $(MUTE)
	@printf	"\r$(LBSFML)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Lib SFML installed" "✔"	
	@touch $(TEMP)
#------------------------------

$(NAME) : $(OBJ_D) $(OBJ)
	@printf	"$(LBSFML)%-50s [$(CLRR)%s$(CLRW)]" "Lib SFML compiled" "✘"
	@$(CLNG) $(OBJ) $(OTH_F) $(SHARE) $(FPIC) -lsfml-graphics -lsfml-window -lsfml-system -o $(NAME) $(OTH_I)
	@printf	"\r$(LBSFML)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Lib SFML compiled" "✔"	
#1
$(OBJ_D) :
	@mkdir -p $(OBJ_D)
	@printf	"$(LBSFML)%-50s [$(CLRG)%s$(CLRW)]\n" "Repository: $@ created" "✔"
#2
$(OBJ_D)%.o : $(SRC_D)%.cpp
	@printf	"$(LBSFML)%-50s [$(CLRR)%s$(CLRW)]" "Object: $@ created" "✘"
	@$(CLNG) $(FPIC) -o $@ -c $< $(OTH_I)
	@printf	"\r$(LBSFML)%-50s [$(CLRG)%s$(CLRW)]\n" "Object: $@ created" "✔"

.PHONY : clean fclean re dir install
.NOTPARALLEL : $(OBJ)

clean :
	@rm -rf $(OBJ_D)
	@printf	"$(LBSFML)%-50s [$(CLRG)%s$(CLRW)]\n" "Objects removed" "∙"

fclean : clean
	@rm -f $(NAME)
	@printf	"$(LBSFML)%-50s [$(CLRG)%s$(CLRW)]\n" "File: $(NAME) removed" "∙"

hclean: fclean
	@sudo apt-get -q -qq remove -y libsfml-dev $(MUTE)
	@printf	"$(LBSFML)%-50s [$(CLRG)%s$(CLRW)]\n" "SFML uninstalled" "∙"
	@sudo rm $(TEMP)

re : fclean all
