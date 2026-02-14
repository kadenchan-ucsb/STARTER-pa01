#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "card.h"
#include "card_list.h"



using namespace std;

BST emptyTree, single, multiple, edgeOne, edgeTwo;

BST commonOne, commonTwo;
BST emptyOne, cardsTwo;
BST diffOne, diffTwo;


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
  cout<<"\nPlayer One's cards:" <<endl; 
  handOne.printInOrder();
  cout<<"\nPlayer Two's cards:" <<endl;
  handTwo.printInOrder();
}




void setup(){
    single.insert(Card('h', "10"));
    multiple.insert(Card('h', "10"));
    multiple.insert(Card('d', "5"));
    multiple.insert(Card('s', "a"));
    edgeOne.insert(Card('h', "10"));
    edgeOne.insert(Card('d', "5"));
    edgeOne.insert(Card('s', "a"));
    edgeTwo.insert(Card('h', "10"));
    edgeTwo.insert(Card('d', "5"));
    edgeTwo.insert(Card('s', "a"));

    commonOne.insert(Card('h', "10"));
    commonOne.insert(Card('d', "5"));
    commonOne.insert(Card('s', "a"));
    commonTwo.insert(Card('h', "10"));
    commonTwo.insert(Card('d', "5"));
    commonTwo.insert(Card('s', "a"));

    emptyOne = BST();
    cardsTwo = BST();
    cardsTwo.insert(Card('h', "10"));
    cardsTwo.insert(Card('d', "5"));
    cardsTwo.insert(Card('s', "a"));

    diffOne.insert(Card('h', "10"));
    diffOne.insert(Card('d', "5"));
    diffOne.insert(Card('s', "a"));
    diffTwo.insert(Card('c', "2"));
    diffTwo.insert(Card('c', "3"));
    diffTwo.insert(Card('c', "4"));
}

int main(){
    setup();
    
    cout << "Empty tree checks:" << endl;
    
    cout << "Single node tree: " << endl;
    single.printInOrder();
    cout << "Single node tree inserting d 5 and s a: " << endl;
    single.insert(Card('d', "5"));
    single.insert(Card('s', "a"));
    single.printInOrder();

    cout << "Multiple node tree: " << endl;
    multiple.printInOrder();
    cout << "Multiple node tree contains s a: " << endl;
    cout << (multiple.contains(Card('s', "a")) ? "true" : "false") << endl;
    cout << "Multiple node tree remove s a: " << endl;
    multiple.remove(Card('s', "a"));
    multiple.printInOrder();
    cout << "Multiple node tree contains s a: " << endl;
    cout << (multiple.contains(Card('s', "a")) ? "true" : "false") << endl;

    cout << "Edge case 1 (remove nonexistent): " << endl;
    edgeOne.remove(Card('s', "10"));
    edgeOne.printInOrder();
    cout << "Edge case 2 (add duplicate): " << endl;
    edgeTwo.insert(Card('s', "a"));
    edgeTwo.printInOrder();

    cout << "iterating single node" << endl;
    for (auto it = single.begin(); it != single.end(); ++it) {
        cout << *it << endl;
    }

    cout << "emptyTree.begin() == emptyTree.end(): " << (emptyTree.begin() == emptyTree.end() ? "true" : "false") << endl;
    cout << "emptyTree.rbegin() == emptyTree.rend(): " << (emptyTree.rbegin() == emptyTree.rend() ? "true" : "false") << endl;
    cout << "emptyTree.contains(h 10): " << (emptyTree.contains(Card('h', "10")) ? "true" : "false") << endl;
    
    cout<< "iterating multiple node increasing" << endl;
    for (auto it = multiple.begin(); it != multiple.end(); ++it) {
        cout << *it << endl;
    }
    cout<< "iterating multiple node decreasing" << endl;
    for (auto it = multiple.rbegin(); it != multiple.rend(); --it) {
        cout << *it << endl;
    }
    cout<< "iterating past the end" << endl;   
    auto it = multiple.end();
    ++it;
    cout << (*it) << endl;

    cout<< "iterating past the rend" << endl;   
    auto rit = multiple.rend();
    --rit;
    cout << (*rit) << endl;

    cout<< "testing ==" << endl; 
    for (auto it = multiple.begin(); it != multiple.end(); ++it) {
        for (auto rit = multiple.rbegin(); rit != multiple.rend(); ++rit) {
         cout << "Comparing " << *it << " and " << *rit << ": " << ((it == rit)) << endl;
        }
    }
    cout<< "testing !=" << endl; 
    for (auto it = multiple.begin(); it != multiple.end(); ++it) {
        for (auto rit = multiple.rbegin(); rit != multiple.rend(); ++rit) {
         cout << "Comparing " << *it << " and " << *rit << ": " << ((it != rit)) << endl;
        }
    }
    

    cout << "\n\nPlaying game with common cards" << endl;
    playGame(commonOne, commonTwo);
    cout << "\n\nPlaying game with empty tree and cards" << endl;
    playGame(emptyOne, cardsTwo);
    cout << "\n\nPlaying game with no common cards" << endl;
    playGame(diffOne, diffTwo);




    return 0;
}