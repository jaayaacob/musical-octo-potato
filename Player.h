#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "CreatureList.h"
using namespace std;
//////////// PLAYER CLASSS /////////////////////////////
class Player{
  private:
    int playerID;
    string playerName;
    CreatureList creatures;
    int winCond;

  public:
    Player() : creatures(), playerID(0), playerName("NULL"), winCond(0) {}
    void setPlayerID(int);
    void setPlayerName(string);
    void setWinCond(int);
    int getPlayerID() const;
    string getPlayerName() const;
    void incrementWinCond();
    int getWinCond() const;
    void resetWinCond();

    void appendCreature(string, int, int);   //// Append Creature to the Creature List through Player Class
    void deleteCreature(int);                //// Delete Creature from the Creature List through Player Class
    void getCreatures(CreatureList&);        //// Get Creature List
    int getCreaturePosition(int);
    string getCreatureName(int);
    int getCreatureAttack(int);
    int getCreatureID(int);
    bool isNotInRoom(int);                  ////checking if any ally creature in a certain room
    void changeCreaturePosition(int, int);
    void clear();                           ////clears Player data after game finishes
    int getCreatureListCount();             ////get the number of creature in the list
};
#endif
