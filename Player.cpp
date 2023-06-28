#include <string>
#include "CreatureList.h"
#include "Player.h"
using namespace std;
void Player::setPlayerID(int id){
  playerID = id;
}

void Player::setPlayerName(string name){
  playerName = name;
}

void Player::setWinCond(int num){
  winCond = num;
}

int Player::getPlayerID() const{
  return playerID;
}

string Player::getPlayerName() const{
  return playerName;
}

void Player::getCreatures(CreatureList& other){
  creatures.copyList(other);
}

void Player::appendCreature(string name, int val, int pos){
  creatures.appendNode(name,val,pos);
}

void Player::deleteCreature(int id){
  creatures.deleteNode(id);
}

int Player::getCreaturePosition(int id){
  return creatures.getCreaturePosition(id);
}

string Player::getCreatureName(int id){
  return creatures.getCreatureName(id);
}

int Player::getCreatureID(int pos){
  return creatures.getCreatureID(pos);
}

int Player::getCreatureAttack(int id){
  return creatures.getAttackVal(id);
}

bool Player::isNotInRoom(int room){
  return creatures.isNotInRoom(room);
}

void Player::changeCreaturePosition(int id, int pos){
  creatures.changeCreaturePosition(id, pos);
}

void Player::incrementWinCond(){
  winCond = winCond + 1;
}

int Player::getWinCond() const{
  return winCond;
}

void Player::resetWinCond(){
  winCond = 0;
}

int Player::getCreatureListCount(){
  return creatures.getCreatureListCount();
}

void Player::clear(){
  playerID = 0;
  playerName = "NULL";
  winCond = 0;

  creatures.clear();
}
