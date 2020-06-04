#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Soldier.hpp"
#include "FootSoldier.hpp"
using namespace std;

class FootCommander : public Soldier
{
  public:
   FootCommander(int team): Soldier(team,150,20,"Foot Commander",150){};
   Soldier* find_target (std::vector<std::vector<Soldier*>> board,int x, int y);
   void main_action(std::vector<std::vector<Soldier*>>& board,int x, int y);
   
};

#endif
