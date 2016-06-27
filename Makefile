##
## Makefile for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
## 
## Made by guillaume wilmot
## Login   <wilmot_g@epitech.net>
## 
## Started on  Thu Jun 16 12:12:58 2016 guillaume wilmot
## Last update Mon Jun 27 11:24:56 2016 guillaume wilmot
##

SRC	= Charset.cpp		\
	  CharacterManager.cpp	\
	  Client.cpp		\
	  Displayer.cpp		\
	  FpsManager.cpp	\
	  Inventory.cpp		\
	  Main.cpp		\
	  Map.cpp		\
	  NameGenerator.cpp	\
	  Renderer.cpp		\
	  ShapedWindow.cpp	\
	  Sounds.cpp		\
	  TextureManager.cpp	\
	  ThreadManager.cpp	\
	  ZBuffer.cpp		\
	  ZClient.cpp

OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

RM	= rm -f

CXX	= g++ -O3 -Wl,-rpath,./lib -std=c++11

NAME	= zappy-gfx

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I inc/ -I ./inc/SDL

MAKEOBJ	= obj

LDFLAGS 	+= -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lpng16 -ljpeg -llash -lfluidsynth -L ./lib
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
