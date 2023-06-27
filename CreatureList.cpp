#include <string>
#include "CreatureList.h"
using namespace std;
bool CreatureList::isEmptyList() const{
  return (head==nullptr);
}

void CreatureList::clear(){
  CreatureNode* nodePtr = head;

  while(head != nullptr) {
    head = nodePtr->next;
    delete nodePtr;
    nodePtr = head;
  }
}

CreatureList::~CreatureList(){
  clear();
}

void CreatureList::appendNode(string name, int val, int pos){
  CreatureNode* newNode = new CreatureNode;
  newNode->creatureID = 0;
  newNode->creatureName = name;
  newNode->attackVal = val;
  newNode->creaturePosition = pos;
  newNode->next = nullptr;

  if(isEmptyList()){
    newNode->creatureID = 1;
    head = newNode;
    return;
  }

  CreatureNode* nodePtr = head;
  int count = 1;

  while(nodePtr->next != nullptr){
    nodePtr = nodePtr->next;
    count++;
  }
  newNode->creatureID = count+1;
  nodePtr->next = newNode;
}

void CreatureList::deleteNode(int id){
  if(isEmptyList()) return;

  CreatureNode *nodePtr = head;
  CreatureNode *prevNode = nullptr;

  if(head->creatureID == id){
    head = nodePtr->next;
    delete nodePtr;

  } else {
    while(nodePtr != nullptr && nodePtr->creatureID != id){
      prevNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if(nodePtr){
      prevNode->next = nodePtr->next;
      delete nodePtr;
    }
  }

    //reassign id
    int count = 1;
    nodePtr = head;
    while(nodePtr != nullptr){
      nodePtr->creatureID = count;
      count++;
      nodePtr = nodePtr->next;
    }
}

string CreatureList::getCreatureName(int id){
  if(isEmptyList()){
    return "ERROR_404_NOT_FOUND_EMPTY";
  }

  CreatureNode *nodePtr = head;
  CreatureNode *prevNode = nullptr;

  if(head->creatureID == id){
    return nodePtr->creatureName;
  }

  while(nodePtr != nullptr && nodePtr->creatureID != id){
    prevNode = nodePtr;
    nodePtr = nodePtr-> next;
  }

  if(nodePtr){
    return nodePtr->creatureName;
  }

  return "ERROR_404_NOT_FOUND";
}

int CreatureList::getAttackVal(int id){
  if(isEmptyList()){
    return 0;
  }

  CreatureNode *nodePtr = head;
  CreatureNode *prevNode = nullptr;

  if(head->creatureID == id){
    return nodePtr->attackVal;
  }

  while(nodePtr != nullptr && nodePtr->creatureID != id){
    prevNode = nodePtr;
    nodePtr = nodePtr-> next;
  }

  if(nodePtr){
    return nodePtr->attackVal;
  }

  return 0;
}

int CreatureList::getCreaturePosition(int id){
  if(isEmptyList()){
    return 0;
  }

  CreatureNode *nodePtr = head;
  CreatureNode *prevNode = nullptr;

  if(head->creatureID == id){
    return nodePtr->creaturePosition;
  }

  while(nodePtr != nullptr && nodePtr->creatureID != id){
    prevNode = nodePtr;
    nodePtr = nodePtr-> next;
  }

  if(nodePtr){
    return nodePtr->creaturePosition;
  }

  return 0;
}

void CreatureList::changeCreaturePosition(int id, int pos){
  if(isEmptyList()) return;

  CreatureNode *nodePtr = head;
  while (nodePtr != nullptr && nodePtr->creatureID != id){
    nodePtr = nodePtr->next;
  }

  nodePtr->creaturePosition = pos;
}

bool CreatureList::isNotInRoom(int room) {
  if(isEmptyList()) return true;

  CreatureNode *nodePtr;

  nodePtr = head;
  while (nodePtr != nullptr && nodePtr-> creaturePosition != room){
    nodePtr = nodePtr->next;
  }

  if (nodePtr == nullptr)
  return true;

  return false;
}

int CreatureList::getCreatureID(int pos){
  if(isEmptyList()){ return 0;}

  CreatureNode *nodePtr = head;

  while(nodePtr != nullptr && nodePtr->creaturePosition != pos){
    nodePtr = nodePtr->next;
  }

  if(nodePtr)
    return nodePtr->creatureID;

  return 0;
}

void CreatureList::copyList(CreatureList& other){
  if(isEmptyList()) return;

  other.clear();

  CreatureNode* nodePtr = head;
  CreatureNode* copyNode = nullptr;
  CreatureNode* otherPtr = nullptr;

  while(nodePtr!=nullptr){
    copyNode = new CreatureNode;
    copyNode->creatureID = nodePtr->creatureID;
    copyNode->creatureName = nodePtr->creatureName;
    copyNode->attackVal = nodePtr->attackVal;
    copyNode->creaturePosition = nodePtr->creaturePosition;
    copyNode->next = nullptr;
    if(other.head == nullptr){
      other.head = copyNode;
      otherPtr = other.head;
    } else {
      otherPtr->next = copyNode;
      otherPtr = otherPtr->next;
    }

    nodePtr = nodePtr->next;
  }
}

int CreatureList::getCreatureListCount(){
  int count = 0;
  CreatureNode* nodePtr = head;

  while (nodePtr != nullptr){
    count++;
    nodePtr = nodePtr->next;
  }

  return count;
}
