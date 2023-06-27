#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "mainFunctions.h"
#include "Player.h"
#include "CreatureList.h"
using namespace std;

////////////// PRINT FUNCTIONS /////////////////
void printDoubleLine(){
  cout << setfill('=') << setw(30) << "" << setfill(' ') << endl;
}

void printSingleLine(){
  cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;
}

void printMainMenu(){
  printDoubleLine();
  cout << "Creature Warfare" << endl;
  printSingleLine();
  cout << "1. Create New Game" << endl
       << "2. Load Previous Game" << endl
       << "3. About Game" << endl
       << "4. Exit Program" << endl;
  printDoubleLine();
}

void printAboutGame(){
  cout << "About Game" << endl;
  printSingleLine();
  cout << "This game was created in collaboration of 3 students. Please enjoy!" << endl;
  printSingleLine();
}

void enterPrompt(){
  string input;
  cout << "Press Enter to Continue..." << endl;
  printDoubleLine();
  cout << "> ";
  getline(cin, input);
}

void printPlayerMenu(){
  cout << "Player Menu" << endl;
  printSingleLine();
  cout << "1. Display Creatures" << endl
       << "2. Move Creature" << endl
       << "3. Skip Turn" << endl
       << "4. Save and Exit Game" << endl << endl;
}

void printMap(){
  cout << "Map of the Rooms " << endl;
  printSingleLine();
  cout << "1 2 3" << endl
       << "4 5 6" << endl
       << "7 8 9" << endl;
  printSingleLine();
}

void printWinner(string winner){
  cout << endl << endl;
  printDoubleLine();
  cout << "We have a winner! Player " << winner << " is victorious!" << endl
       << "Congratulations!" << endl;
  printDoubleLine();
}

////////////RANDOM NUMBER GENERATOR//////////////

int getRandomNumber() {
    srand(time(0)); // Seed the random number generator with current time
    int randomNo = rand() % 100 + 1 ; // 1 to 100
    return randomNo;
}

////////////VALIDATION FUNCTIONS////////////////

bool isStringEmptyOrSpaces(const string& input){ // checking if inputted string is empty or just spaces
  for (char c : input) {
    if (!isspace(c)){
      return false;
    }
  }

  return true;
}

string getInputString(){ // name input trimming whitespaces purpose
  string input;
  getline(cin, input);

  size_t start= input.find_first_not_of(" \t");
  size_t end = input.find_last_not_of(" \t");
  if(start != string::npos && end!= string::npos){
    input = input.substr(start, end - start + 1);
  } else {
    input.clear();
  }

  return input;
}

////////////////////GAMEPLAY FUNCTIONS///////////////////////


bool miniGame(){ // minigame for every player during their turn to create their creature
  int choice;
  string input;
  bool test = false;
  int randomNo = getRandomNumber();
  cout << "A random number between 1 to 100 has been generated" << endl
       << "Guess Higher or Lower than 50 correctly to create creature:" << endl
       << endl << endl
       << "1. Higher than 50" << endl
       << "2. Lower than or equal to 50" << endl << endl;
  printDoubleLine();
  cout << "> ";

  while(true){ //input validation
    getline(cin, input);
    choice = atoi(input.c_str());
    if(choice == 1 || choice == 2) break;
    printSingleLine();
    cout << "Invalid guess" << endl;
    printSingleLine();
    cout << "> ";
  }
  printDoubleLine();
  if (choice == 1 && randomNo > 50)
    test = true;

  if (choice == 2 && randomNo <= 50)
    test = true;

  return test;
}

void makeCreature(Player players[], int currentPlayer, Player& current){ //function for player that is worthy to create a creature
  int spawnRoom;

  switch(currentPlayer){
    case 0: spawnRoom = 1;
            break;
    case 1: spawnRoom = 3;
            break;
    case 2: spawnRoom = 7;
            break;
    case 3: spawnRoom = 9;
            break;
  }

  string input;
  cout << "Correct! You get to make a creature!" << endl;
  printSingleLine();
  cout << "Give a name to your creature " << endl;
  printDoubleLine();
  cout << "> ";
  while(true){
    input = getInputString();
    if(!isStringEmptyOrSpaces(input)) break;
    printSingleLine();
    cout << "Invalid name" << endl;
    printSingleLine();
    cout << "> ";
  }
  printDoubleLine();
  int val;
  int randVal;

  cout << "Randomly generating attack value...(1-5)" << endl;
  randVal = getRandomNumber();

   if (randVal > 0 && randVal <= 20)
    val = 1;
  else if (randVal > 20 && randVal <= 40)
    val = 2;
  else if (randVal > 40 && randVal <= 60)
    val = 3;
  else if (randVal > 60 && randVal <= 80)
    val = 4;
  else if (randVal > 80 && randVal <= 100)
    val = 5;

  enterPrompt();
  printSingleLine();
  cout << "Creature added to the Player " << currentPlayer+1 << "'s base!" << endl
       << "\t" << input << endl
       << "\t" << val << " Attack" << endl;
  printSingleLine();

  current.appendCreature(input, val, spawnRoom);

  enterPrompt();
}

void displayCreature(Player& player){ //Display Each Creature for a player
  CreatureList Display;
  player.getCreatures(Display);
  int count = player.getCreatureListCount();

  cout << player.getPlayerName() << "'s Creatures: " << endl;
  if(count == 0)
    cout << "    NONE   " << endl;
  for(int i=0;i<count;i++){
    cout << "    Creature ID: " << i+1 << endl;
    cout << "\tCreature name: " << Display.getCreatureName(i+1) << endl;
    cout << "\tCreature attack: " << Display.getAttackVal(i+1) << endl;
    cout << "\tCreature position: Room " << Display.getCreaturePosition(i+1) << endl;
  }
  cout << endl;

}

///////////////////////SAVING FUNCTIONS/////////////////////////

void saveGame(Player players[],int numPlayers,int currentPlayer){
  ofstream outFile("saveFile.txt");
  int count;
  int lineNum = 0;
  for(int i = -1; i<numPlayers; i++){
    if(lineNum == 0){
      outFile << currentPlayer << endl;
      lineNum++;
      continue;
    }
    outFile << players[i].getPlayerName() << "," << players[i].getWinCond();
    count = players[i].getCreatureListCount();
    for(int j = 0; j<count; j++){
      outFile << players[i].getCreatureName(j+1) << "," << players[i].getCreatureAttack(j+1) << " "
              << players[i].getCreaturePosition(j+1) << ".";
    }
    outFile << endl;
  }

  outFile.close();
}


//////////////////////////GAME FUNCTIONS/////////////////////////

void PlayerFunctions(Player players[], int numPlayers, int currentPlayer){ //function for each player turn
  int choice;
  int count = players[currentPlayer].getCreatureListCount();
  int id;
  int pos;
  int option;
  string input;
  bool onTurn=true;
  cout << endl;

  while(onTurn){

    printPlayerMenu();
    printDoubleLine();
    cout << "> ";

    while(true){ //input validation
      getline(cin, input);
      choice = atoi(input.c_str());
      if (choice >= 1 && choice <=4) break;
      printSingleLine();
      cout << "Invalid choice" << endl;
      printSingleLine();
    }

    printDoubleLine();
    if(choice == 1){
      for(int i=0;i<numPlayers;i++){
        displayCreature(players[i]);
      }
      printSingleLine();
      enterPrompt();
      printDoubleLine();
    }
    if(choice == 2 && count == 0){
      cout << endl << "You dont have any creature to move!" << endl << endl;
      enterPrompt();
      printDoubleLine();
    }
    if(choice == 2 && count !=0){
      cout << "Which creature would you like to move? Enter its ID." << endl;
      printSingleLine();
      displayCreature(players[currentPlayer]);
      printDoubleLine();
      cout << "> ";

      while(true){ //input validation
        getline(cin, input);
        id = atoi(input.c_str());
        if(id >= 1 && id <= count) break;
        printSingleLine();
        cout << "Invalid ID" << endl;
        printSingleLine();
        cout << "> ";
      }
      printDoubleLine();

      pos = players[currentPlayer].getCreaturePosition(id);

      cout << players[currentPlayer].getCreatureName(id) << " is in Room " << pos << endl;
      printSingleLine();

      //int roomChoice;

      cout << endl << "Enter the room number to move" << endl << endl;
      switch(pos){
        case 1: if(players[currentPlayer].isNotInRoom(2))
                  cout << "<Room 2>" << endl;
                if(players[currentPlayer].isNotInRoom(4))
                  cout << "<Room 4>" << endl;
                if(!players[currentPlayer].isNotInRoom(2) && !players[currentPlayer].isNotInRoom(4)){
                  cout << "No rooms available." << endl;
                  onTurn = false;
                }
                break;
        case 2:
        case 4:
        case 6:
        case 8: if(players[currentPlayer].isNotInRoom(5))
                  cout << "<Room 5>" << endl;
                if(!players[currentPlayer].isNotInRoom(5)){
                  cout << "No rooms available." << endl;
                  onTurn = false;
                }


                break;
        case 3: if(players[currentPlayer].isNotInRoom(2))
                  cout << "<Room 2>" << endl;
                if(players[currentPlayer].isNotInRoom(6))
                  cout << "<Room 6>" << endl;
                if(!players[currentPlayer].isNotInRoom(2) && !players[currentPlayer].isNotInRoom(6)){
                  cout << "No rooms available." << endl;
                  onTurn = false;
                }


                break;
        case 5: if(players[currentPlayer].isNotInRoom(2))
                  cout << "<Room 2>" << endl;
                if(players[currentPlayer].isNotInRoom(4))
                  cout << "<Room 4>" << endl;
                if(players[currentPlayer].isNotInRoom(6))
                  cout << "<Room 6>" << endl;
                if(players[currentPlayer].isNotInRoom(8))
                  cout << "<Room 8>" << endl;
                if(!players[currentPlayer].isNotInRoom(2) && !players[currentPlayer].isNotInRoom(4) && !players[currentPlayer].isNotInRoom(6) && !players[currentPlayer].isNotInRoom(8)){
                  cout << "No rooms available." << endl;
                  onTurn = false;
                }

                break;
        case 7: if(players[currentPlayer].isNotInRoom(4))
                  cout << "<Room 4>" << endl;
                if(players[currentPlayer].isNotInRoom(8))
                  cout << "<Room 8>" << endl;
                if(!players[currentPlayer].isNotInRoom(4) && !players[currentPlayer].isNotInRoom(8)){
                  cout << "No rooms available." << endl;
                  onTurn = false;
                }


                break;
        case 9: if(players[currentPlayer].isNotInRoom(6))
                  cout << "<Room 6>" << endl;
                if(players[currentPlayer].isNotInRoom(8))
                  cout << "<Room 8>" << endl;
                if(!players[currentPlayer].isNotInRoom(4) && !players[currentPlayer].isNotInRoom(8)){
                  cout << "No rooms available." << endl;
                  onTurn = false;
                }


                break;
      }
      if(!onTurn){
        cout << "Your Creature cannot move! " << endl;
        enterPrompt();
        printDoubleLine();
        onTurn = true;
      } else {

      cout << endl;
      printDoubleLine();
      cout << "> ";

      switch (pos){
        case 1: while(true){ //input validation
                  getline(cin, input);
                  option = atoi(input.c_str());
                  if(option == 2 || option == 4) break;
                  printSingleLine();
                  cout << "Invalid option." << endl;
                  printSingleLine();
                }
                break;
        case 2:
        case 4:
        case 6:
        case 8: while(true){ //input validation
                  getline(cin, input);
                  option = atoi(input.c_str());
                  if(option == 5) break;
                  printSingleLine();
                  cout << "Invalid option." << endl;
                  printSingleLine();
                }
                break;
        case 3: while(true){ //input validation
                  getline(cin, input);
                  option = atoi(input.c_str());
                  if(option == 2 || option == 6) break;
                  printSingleLine();
                  cout << "Invalid option." << endl;
                  printSingleLine();
                }
                break;
        case 5: while(true){ //input validation
                  getline(cin, input);
                  option = atoi(input.c_str());
                  if(option == 2 || option == 4 || option == 6 || option == 8) break;
                  printSingleLine();
                  cout << "Invalid option." << endl;
                  printSingleLine();
                }
                break;
        case 7: while(true){ //input validation
                  getline(cin, input);
                  option = atoi(input.c_str());
                  if(option == 4 || option == 8) break;
                  printSingleLine();
                  cout << "Invalid option." << endl;
                  printSingleLine();
                }
                break;
        case 9: while(true){ //input validation
                  getline(cin, input);
                  option = atoi(input.c_str());
                  if(option == 6 || option == 8) break;
                  printSingleLine();
                  cout << "Invalid option." << endl;
                  printSingleLine();
                }
                break;
      }
      printDoubleLine();
      players[currentPlayer].changeCreaturePosition(id, option);
      if(players[currentPlayer].getCreaturePosition(id)==option) cout << "Success!" << endl;
      cout << "You have moved your " << players[currentPlayer].getCreatureName(id) << " to Room " << option << endl << endl;
      printSingleLine();
      displayCreature(players[currentPlayer]);
      printDoubleLine();

      //enemy check codes

      int enemy;
      bool occupancy = false;

      for(int i = 0; i<numPlayers; i++){
        if(i == currentPlayer)
          continue;

        if(!players[i].isNotInRoom(option)){
          occupancy = true;
          enemy = i;
          break;
        }
      }

      if(occupancy){
        //battle starts

        int enemyID = players[enemy].getCreatureID(option);
        int allyID = players[currentPlayer].getCreatureID(option);

        int combinedAttack = players[currentPlayer].getCreatureAttack(allyID) + players[enemy].getCreatureAttack(enemyID);
        int randomNo = getRandomNumber();
        int winChance = players[currentPlayer].getCreatureAttack(allyID) * 100/combinedAttack;
        int enemyWinChance = 100 - winChance;

        cout << endl
             << players[currentPlayer].getPlayerName() << "'s " << players[currentPlayer].getCreatureName(allyID) << " V.S " << players[enemy].getPlayerName() << "'s " << players[enemy].getCreatureName(enemyID) << endl
             << winChance << "% V.S " << enemyWinChance << "%" << endl << endl;

        enterPrompt();
        printDoubleLine();
        cout << endl;

        if (randomNo <= winChance){
          //Creature 1 wins
          cout << players[currentPlayer].getPlayerName() << "'s " << players[currentPlayer].getCreatureName(allyID) << " wins!" << endl << endl;
          enterPrompt();
          printDoubleLine();
          cout << players[enemy].getPlayerName() << "'s " << players[enemy].getCreatureName(enemyID) << " have been removed from the game.." << endl;
          players[enemy].deleteCreature(enemyID);
        } else {
          //Creature 2 wins
          cout << players[enemy].getPlayerName() << "'s " << players[enemy].getCreatureName(enemyID) << " wins!" << endl;
          enterPrompt();
          printDoubleLine();
          cout << players[currentPlayer].getPlayerName() << "'s " << players[currentPlayer].getCreatureName(allyID) << " have been removed from the game.." << endl;
          players[currentPlayer].deleteCreature(allyID);
        }

        cout << endl << endl;

        printDoubleLine();
      }

      onTurn = false;
    }
  }

    if(choice == 3){
      cout << endl << "Player " << currentPlayer+1 << " chooses to skip his turn!" << endl << endl;
      printDoubleLine();
      enterPrompt();
      printDoubleLine();
      onTurn = false;
    }

    if(choice == 4){
      cout << "Saving game..." << endl << endl;
      enterPrompt();
      printDoubleLine();
      cout << "Game is Saved!" << endl << "Till we meet again" << endl << "Quitting....";
      exit(0);
    }

  }

}

bool checkWin(Player players[], int currentPlayer, string &trueWinner){ // checks if there is a winner before every player turn
  if (players[currentPlayer].isNotInRoom(5)){
    if (players[currentPlayer].getWinCond() != 0)
      players[currentPlayer].resetWinCond();
  }

  else {
    players[currentPlayer].incrementWinCond();
    cout << endl << endl
         << "Player " << players[currentPlayer].getPlayerName() << " owns a creature in Room 5." << endl;
    if(players[currentPlayer].getWinCond() < 3)
      cout << "If the creature stays in the room 5 for " << 3 - players[currentPlayer].getWinCond() << " more rounds, they will win! "<< endl << endl << endl;
    else
      cout << "The creature has stayed in the room 5 for 3 rounds!" << endl << endl << endl;

    enterPrompt();
    printDoubleLine();
  }

  if (players[currentPlayer].getWinCond() == 3) {
    trueWinner = players[currentPlayer].getPlayerName();
    return false;
  }
  else { return true; }
}

void playGame(Player players[], int numPlayers, string &winner, int currentPlayer){ //function to start the game
  string trueWinner = "";

  while(checkWin(players, currentPlayer, trueWinner)){
    Player& current = players[currentPlayer];
    printMap();
    cout << "Player " << currentPlayer+1 << ", " << current.getPlayerName() << "'s turn! " << endl;
    printSingleLine();

    if (miniGame()){
      makeCreature(players, currentPlayer, current);
    } else {
      cout << endl << "Wrong guess. Better luck next time!" << endl << endl;
    }

    printDoubleLine();

    PlayerFunctions(players, numPlayers, currentPlayer);

    currentPlayer = (currentPlayer + 1) % numPlayers;
    saveGame(players, numPlayers, currentPlayer);
  }

  winner = trueWinner;
  ofstream outFile("saveFile.txt");
  outFile.close();
  for(int i =0; i<numPlayers; i++){
    players[i].clear();
  }
}
#endif
