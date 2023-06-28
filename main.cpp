#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "mainFunctions.h"
#include "Player.h"
#include "CreatureList.h"
using namespace std;

int main(){
  //////////MAIN MENU VARIABLES///////////
  int choice;
  string input;
  int numPlayers;
  const int MAX_PLAYERS = 4;
  int rooms[] = {1,2,3,4,5,6,7,8,9};
  Player players[MAX_PLAYERS];
  string winner;
  int currentPlayer;
  int lineNum;

  //////////LOAD GAME VARIABLES///////////

  ifstream inputFile;
  string line;
  string creatureLine;
  string playerName;
  int winCond;
  string creatureName;
  int attackVal;
  int creaturePosition;


  //////////////MAIN MENU/////////////////

  while(true){
    printMainMenu();
    cout << "> ";

    while(true){ //input validation
      getline(cin, input);
      choice = atoi(input.c_str());
      if(choice >=1 && choice <=4) break;
      printSingleLine();
      cout << "Invalid choice." << endl;
      printSingleLine();
      cout << "> ";
    }

    printDoubleLine();
    switch(choice){
      case 1: /////////////////NEW GAME/////////////////////
              cout << "Creating New Game..." << endl;
              printSingleLine();
              cout << "Enter number of player (2-4)" << endl << endl;
              printDoubleLine();
              cout << "> ";

              while(true){ //input validation
                getline(cin, input);
                choice = atoi(input.c_str());
                if(choice >=2 && choice <=4) break;
                printSingleLine();
                cout << "Invalid number of player." << endl;
                printSingleLine();
                cout << "> ";
              }
              numPlayers = choice;
              printDoubleLine();
              cout << endl << "CREATURE WARFARE" << endl << endl;
              printDoubleLine();
              printMap();
              cout << "Generating Players..." << endl;
              printDoubleLine();

              for(int i=0; i<numPlayers; i++){
                cout << "Insert Player " << i+1 << "'s Name: " << endl;
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
                players[i].setPlayerName(input);
                players[i].setPlayerID(i+1);
                printDoubleLine();
              }
              cout << "Player List" << endl;
              printSingleLine();
              for(int i=0; i<numPlayers; i++){
                cout << "Player " << players[i].getPlayerID() << ": " << players[i].getPlayerName() << endl;
              }
              printSingleLine();
              cout << "Game Start!" << endl;
              printSingleLine();
              enterPrompt();
              printDoubleLine();
              playGame(players, numPlayers, winner, 0);

              printWinner(winner);
              break;

      case 2: ///////////LOAD GAME////////////////
              inputFile.open("saveFile.txt");
              if(inputFile.peek() == ifstream::traits_type::eof()){
                cout << "No previous game available" << endl;
                printSingleLine();
                enterPrompt();
                break;
              }

              numPlayers = 0;
              currentPlayer = 0;
              lineNum = 0;

              while(getline(inputFile, line)){
                if(lineNum == 0){
                  currentPlayer = stoi(line);
                  lineNum++;
                  continue;
                }
                size_t commaPos = line.find(',');
                playerName = line.substr(0, commaPos);
                line = line.substr(commaPos + 1);

                commaPos = line.find(' ');
                winCond = stoi(line.substr(0, commaPos));
                line = line.substr(commaPos + 1);


                while(!line.empty()){
                  commaPos = line.find(',');
                  string creatureName = line.substr(0, commaPos);
                  line = line.substr(commaPos + 1);

                  commaPos = line.find(' ');
                  attackVal = stoi(line.substr(0, commaPos));
                  line = line.substr(commaPos + 1);

                  commaPos = line.find('.');
                  creaturePosition = stoi(line.substr(0, commaPos));
                  line = line.substr(commaPos + 1);

                  players[numPlayers].appendCreature(creatureName, attackVal, creaturePosition);
                }

                players[numPlayers].setPlayerName(playerName);
                players[numPlayers].setWinCond(winCond);
                numPlayers++;
              }

              inputFile.close();

              cout << endl << "CREATURE WARFARE" << endl << endl;
              printDoubleLine();
              cout << "Loading previous game from save file....." << endl << endl << endl;
              enterPrompt();
              printDoubleLine();
              cout << "Players and creatures List" << endl;
              printSingleLine();
              for(int i=0; i<numPlayers; i++){
                cout << "[Player " << i+1 << "]" << endl;
                displayCreature(players[i]);
                printSingleLine();
              }
              cout << "Game Continues!" << endl;
              printSingleLine();
              enterPrompt();
              printDoubleLine();
              playGame(players, numPlayers, winner, currentPlayer);

              printWinner(winner);
              break;

      case 3: ///////////ABOUT GAME/////////////////
              printAboutGame();
              enterPrompt();

              break;

      case 4: //////////QUIT GAME/////////////////
              cout << "Till we meet again" << endl << "Quitting...." << endl;
              printDoubleLine();

              return 0;
    }
  }
  return 0;
}
