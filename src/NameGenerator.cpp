//
// rand.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sat Jun 25 23:47:03 2016 guillaume wilmot
// Last update Sun Jun 26 20:39:45 2016 guillaume wilmot
//

#include <iostream>
#include <vector>
#include <random>
#include "NameGenerator.hpp"

std::string				NameGenerator::generate()
{
  static int				i = 0;
  static std::vector<std::string>	logins;
  static std::default_random_engine	rander(time(NULL));

  if (!i)
    {
      logins.push_back("Milcen");
      logins.push_back("Octeau");
      logins.push_back("Cavail");
      logins.push_back("Noboud");
      logins.push_back("Saurs");
      logins.push_back("Combaud");
      logins.push_back("Barriere");
      logins.push_back("Empoci");
      logins.push_back("Arino");
      logins.push_back("Wilmot");
      logins.push_back("Sauzeau");
      logins.push_back("Darrac");
      logins.push_back("Armagnac");
      logins.push_back("Moreel");
      logins.push_back("Dazy");
      logins.push_back("Sbrissa");
      logins.push_back("Voisin");
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
  return (logins[rander() % (logins.size() - 1)] + " " + names[rander() % (names.size() - 1)]);
}
