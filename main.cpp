// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

using namespace std;

void playerOne(BST &handOne, BST &handTwo){
    for (auto it = handOne.begin(); it != handOne.end(); ++it) {
        
        if (handTwo.contains(*it)) { 
            auto val = *it;
            std::cout << "Alice picked matching card " << val << std::endl;
            handOne.remove(val);
            handTwo.remove(val);
            return; 
        }
    }
}
void playerTwo(BST &handOne, BST &handTwo){
    for (auto it = handOne.rbegin(); it != handOne.rend(); --it) {
        
        if (handTwo.contains(*it)) { 
            auto val = *it;
            std::cout << "Bob picked matching card " << val << std::endl;
            handOne.remove(val);
            handTwo.remove(val);
            return; 
        }
    }
}
bool dupes(BST &handOne, BST &handTwo){
    for (auto it = handOne.begin(); it != handOne.end(); ++it) {
      if (handTwo.contains(*it)) {
        return true;
      }
    }
    return false;
  }

void playGame(BST &handOne, BST &handTwo){
    int turn =0;
  while(dupes(handOne, handTwo)){
    if(turn%2 == 0){
      playerOne(handOne, handTwo);
      
    
    } else {
      playerTwo(handOne, handTwo);
      
    }
    
    
    turn++;
  }
  cout<<"\nAlice's cards" <<endl; 
  handOne.printInOrder();
  cout<<"\nBob's cards" <<endl;
  handTwo.printInOrder();
}


int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  BST handOne;
  BST handTwo;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    if (line.empty()) continue;
    istringstream iss(line);
    string suitTok, numTok;
    if (!(iss >> suitTok >> numTok)) continue;
    char suit = suitTok[0];
    Card c(suit, numTok);
    handOne.insert(c);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    if (line.empty()) continue;
    istringstream iss(line);
    string suitTok, numTok;
    if (!(iss >> suitTok >> numTok)) continue;
    char suit = suitTok[0];
    Card c(suit, numTok);
    handTwo.insert(c);
  }
  cardFile2.close();
  
  playGame(handOne, handTwo);
  


  
  return 0;
}
