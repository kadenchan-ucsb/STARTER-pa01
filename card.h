// card.h
// Author: Your name
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
class Card {
    private:
        char suit;
        std::string num;
        int valToNum(const std::string p) const;
        int valToNum(const char p) const;
    public:
        Card(char su = 0, std::string nu = ""): suit(su), num(nu){}
        char getSuit() const { return suit; }
        std::string getNum() const { return num; }
        bool operator<(const Card& right) const;
        bool operator>(const Card& right) const;
        bool operator==(const Card& right) const;

};

std::ostream& operator<<(std::ostream &os, const Card &c);

#endif