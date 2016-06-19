##
## Makefile for Makefile in /Users/noboud_n/rendu/cpp_plazza
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Tue Apr 12 14:58:00 2016 Nyrandone Noboud-Inpeng
## Last update Sat Jun 18 12:34:22 2016 guillaume wilmot
##

SRC	= Charset.cpp		\
	  Main.cpp		\
	  Map.cpp		\
	  ShapedWindow.cpp	\
	  TextureManager.cpp	\
	  ZBuffer.cpp		\
	  ZClient.cpp

OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

RM	= rm -f

CXX	= g++ -Wl,-rpath,./lib -std=c++11

NAME	= zappy-gfx
GUI	= gui

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I inc/ -I ./inc/SDL

MAKEOBJ	= obj

LDFLAGS 	+= -lSDL2 -lSDL2_gfx -lSDL2_image -L ./lib
CXXFLAGS	+= -W -Wall -Wextra -Werror

all:
	@make --no-print-directory $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(MAKEOBJ)
	$(CXX) $(CXXFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R $(OBJDIR)

re: fclean all
