// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include "card.h"
#include <iostream>

using namespace std;


int Card::valToNum(const char p)const{
    int val;
    if (p=='c'){
        val=1;
    }else if(p=='d'){
        val=2;
    }else if(p=='s'){
        val=3;
    }else if(p=='h'){
        val=4;
    }
    return val;
}
int Card::valToNum(const std::string p)const{
    int val;
    
    if(p=="2"){
        val=2;
    }else if(p=="3"){
        val=3;
    }else if(p=="4"){
        val=4;
    }else if(p=="5"){
        val=5;
    }else if(p=="6"){
        val=6;
    }else if(p=="7"){
        val=7;
    }else if(p=="8"){
        val=8;
    }else if(p=="9"){
        val=9;
    }else if(p=="10"){
        val=10;
    }else if(p=="a"){
        val=1;
    }else if(p=="j"){
        val=11;
    }else if(p=="q"){
        val=12;
    }else if(p=="k"){
        val=13;
    }
    return val;
}

bool Card::operator<(const Card& right) const {
	if(valToNum(suit)!=valToNum(right.suit)){
        return valToNum(suit)<valToNum(right.suit);
    }
    return valToNum(num)<valToNum(right.num);

    
	
}
bool Card::operator>(const Card& right) const { return right < *this; }
bool Card::operator==(const Card& right) const { return num == right.num && suit == right.suit; }

ostream& operator<<(ostream& os, const Card& c) {
	os << c.getSuit()<<" "<<c.getNum() ;
	return os;
}