

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "FootCommander.hpp"

using namespace std;

Soldier* FootCommander::find_target(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    return find_closest_target(board,x,y);
}

/*
new implemtation to main_action for commander soldier to trigger all non-commander soldiers from the same type. 
*/
void FootCommander::main_action(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    basic_attack(board,x,y);
    
    //go over the board and trigger all foot soldiers from same team
    for(int i = 0; i<board.size(); i++)
    {
      for(int j=0; j<board[i].size(); j++)
      {
          if(board[i][j] != nullptr)
           if(board[i][j]->_team == _team && board[i][j]->_type == "Foot Soldier")
            board[i][j]->main_action(board,x,y);
          
      }
    }
}




