#ifndef CREATURELIST_H
#define CREATURELIST_H
#include <string>
using namespace std;
////////LINKED LIST TO HAVE A LIST OF CREATURE PER PLAYER//////////////
class CreatureList{
  private:
    struct CreatureNode{
      int creatureID;
      string creatureName;
      int attackVal;
      int creaturePosition;
      CreatureNode* next;
    };
    CreatureNode* head;

  public:
    CreatureList(){ head = nullptr; }
    ~CreatureList();
    void clear();
    bool isEmptyList() const;
    void appendNode(string,int,int);
    void deleteNode(int);

    string getCreatureName(int);
    int getAttackVal(int);
    int getCreaturePosition(int);
    void changeCreaturePosition(int, int);
    bool isNotInRoom(int);
    int getCreatureID(int);
    void copyList(CreatureList&);
    int getCreatureListCount();

};

#endif
