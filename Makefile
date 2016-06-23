##
## Makefile for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
## 
## Made by guillaume wilmot
## Login   <wilmot_g@epitech.net>
## 
## Started on  Thu Jun 16 12:12:58 2016 guillaume wilmot
## Last update Thu Jun 23 15:40:12 2016 guillaume wilmot
##

SRC	= Charset.cpp		\
	  CharacterManager.cpp	\
	  Displayer.cpp		\
	  FpsManager.cpp	\
	  Main.cpp		\
	  Map.cpp		\
	  Renderer.cpp		\
	  ShapedWindow.cpp	\
	  TextureManager.cpp	\
	  ThreadManager.cpp	\
	  ZBuffer.cpp		\
	  ZClient.cpp

OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

RM	= rm -f

CXX	= g++ -O3 -Wl,-rpath,./lib -std=c++11 -g

NAME	= zappy-gfx

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I inc/ -I ./inc/SDL

MAKEOBJ	= obj

LDFLAGS 	+= -lSDL2 -lSDL2_gfx -lSDL2_image -lpng16 -ljpeg -L ./lib
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
