#ifndef WARGAME_A_SOLDIER_HPP
#define WARGAME_A_SOLDIER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <math.h>
using namespace std;


class Soldier
{
    public:
    int _team, _health, _impact, _ohp; // ohp = original health points
    string _type;
   
   //Constructor
    Soldier(int team,int health, int impact, string type, int ohp): _team(team), _health(health), _impact(impact), _type(type), _ohp(ohp){};
    
    
    Soldier* find_closest_target(std::vector<std::vector<Soldier*>> board,int x, int y)
    {
    double min_distance = 0;
    Soldier* s = nullptr;
    
    
    for(int i = 0; i<board.size(); i++)
    {
     
         
      for(int j=0; j<board[i].size(); j++)
      {
          
        if(board[i][j] != nullptr && board[i][j]->_team != _team)
        {
            double distance = sqrt(pow(x-i , 2) + pow(y-j , 2));
            if(distance<min_distance || min_distance==0)
            {
             min_distance = distance;
             s = board[i][j];
            }
             
        }
      }
    }
     
     return s;
    };
    
    
    Soldier* find_healthy_target(std::vector<std::vector<Soldier*>> board,int x, int y)
    {
        int max_health = 0;
        Soldier* s = nullptr;
    
    for(int i = 0; i<board.size(); i++)
    {
     
      for(int j=0; j<board[i].size(); j++)
      {
          if(board[i][j] != nullptr && board[i][j]->_team != _team)
        {
            int health = board[i][j]->_health;
            if(health > max_health)
            {
                max_health = health;
                s = board[i][j];
            }
        }
    
      }
      
    }
    
      return s;  
        
    };
    
     Soldier* find_close_ally(std::vector<std::vector<Soldier*>> board,int x, int y)
    {
         //Soldier* s = nullptr;
         
         for(int i=0; i<board.size(); i++)
          {
     
           for(int j=0; j<board[i].size(); j++)
           {
               if(board[i][j] != nullptr && board[i][j]->_team == _team && board[i][j]->_health != board[i][j]->_ohp)
               {
                   if(abs(x-i)==1 && abs(y-j)==1)
                    return board[i][j];
               }
           }
           
          }
          return nullptr;
    };
    
    virtual void basic_action(std::vector<std::vector<Soldier*>> board,int x, int y)
    {
    Soldier* s = find_target(board,x,y);
    s->_health = _health - _impact; //general formula for offensive soldiers
    };
    
    virtual void main_action(std::vector<std::vector<Soldier*>> board,int x, int y)
    {
    basic_action(board,x,y);
    };
    
    
    virtual Soldier* find_target(std::vector<std::vector<Soldier*>> board,int x, int y) =0;
    
    
};


#endif