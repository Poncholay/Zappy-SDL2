//
// rand.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sat Jun 25 23:47:03 2016 guillaume wilmot
// Last update Sat Jun 25 23:55:09 2016 guillaume wilmot
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "NameGenerator.hpp"

std::string				NameGenerator::generate()
{
  static int				i = 0;
  static std::vector<std::string>	logins;

  if (!i)
    {
      logins.push_back("milcen");
      logins.push_back("octeau");
      logins.push_back("cavail");
      logins.push_back("noboud");
      logins.push_back("saurs");
      logins.push_back("combaud");
      logins.push_back("barriere");
      logins.push_back("empoci");
      logins.push_back("arino");
      logins.push_back("wilmot");
      logins.push_back("sauzeau");
      logins.push_back("darrac");
      logins.push_back("armagnac");
      logins.push_back("moreel");
      logins.push_back("dazy");
      logins.push_back("sbrissa");
      logins.push_back("voisin");
    }

  static std::vector<std::string>	names;

  if (!i)
    {
      names.push_back("de Brisail");
      names.push_back("de Befône");
      names.push_back("de Candont");
      names.push_back("de Auser");
      names.push_back("de Atosque");
      names.push_back("de Tremalmont");
      names.push_back("de Ochamnord");
      names.push_back("de Fône");
      names.push_back("de Basapône");
      names.push_back("de Badois");
      names.push_back("de Cavralle");
      names.push_back("de Lubagan");
      names.push_back("de Ounimosque");
      names.push_back("de Cabont");
      names.push_back("de Carour");
      names.push_back("de Puse");
      names.push_back("de Odour");
      names.push_back("de Ipône");
      names.push_back("de Réober");
      names.push_back("de Ogy");
      names.push_back("de Vauralle");
      names.push_back("de Nalm");
      names.push_back("de Oullois");
      names.push_back("de Ton");
      names.push_back("de Adopargues");
      names.push_back("de Avail");
      names.push_back("de Rail");
      names.push_back("de Lonsosse");
      names.push_back("de Lan");
      names.push_back("de Itargues");
      names.push_back("de Cagrur");
      names.push_back("de Ouvauvône");
    }

  i++;
  return (logins[rand() % (logins.size() - 1)] + " " + names[rand() % (names.size() - 1)]);
}
