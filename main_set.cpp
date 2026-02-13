// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include "card.h"

using namespace std;

  bool dupes(set<Card> &s1, set<Card> &s2){
    for (const auto& card : s1) {
      if (s2.find(card) != s2.end()) {
        return true;
      }
    }
    return false;
  }
  void playerOneTurn(set<Card> &s1, set<Card> &s2){
    auto it = s1.begin();
    while (it != s1.end()) {
      if (s2.erase(*it)){
        cout << "Alice picked matching card " << *it << endl;
        it = s1.erase(it);
        return;
      } else {
        ++it;
      }
    }
  }
  
 
void playerTwoTurn(set<Card> &s1, set<Card> &s2) {
  for (auto it = s1.rbegin(); it != s1.rend(); ) {
    auto match = s2.find(*it);
    if (match != s2.end()) {
        cout << "Bob picked matching card " << *it << endl;
        s2.erase(match);
        
        auto next_it = std::next(it);      // Advance first (so it stays valid)
        auto fwd_it = std::prev(it.base()); // Get forward iterator to current element
        s1.erase(fwd_it);
        it = next_it;
        return;
    } else {
        ++it;
    }
}
}
  
  
  

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  set<Card> handOne;
  set<Card> handTwo;

  while (getline(cardFile1, line)){
    if (line.empty()) continue;
    istringstream iss(line);
    string suitTok, numTok;
    if (!(iss >> suitTok >> numTok)) continue;
    char suit = suitTok[0];
    Card c(suit, numTok);
    handOne.insert(c);
  }
  cardFile1.close();

  while (getline(cardFile2, line)){
    if (line.empty()) continue;
    istringstream iss(line);
    string suitTok, numTok;
    if (!(iss >> suitTok >> numTok)) continue;
    char suit = suitTok[0];
    Card c(suit, numTok);
    handTwo.insert(c);
  }
  cardFile2.close();



  int turn =0;
  while(dupes(handOne, handTwo) && handOne.size()>0 && handTwo.size()>0){
    if(turn%2 == 0){
      playerOneTurn(handOne, handTwo);
    
    } else {
      playerTwoTurn(handOne, handTwo);
    
    }
    turn++;
  }

  cout << "\nAlice's hand: "<<endl;
  for (const auto& card : handOne) {
    cout << card << " "<<endl;
  }
  cout << endl;

  cout << "Bob's hand: "<<endl;
  for (const auto& card : handTwo) {
    cout << card << " "<<endl;
  }
  
  

  
  return 0;
}
