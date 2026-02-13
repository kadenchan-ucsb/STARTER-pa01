// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h


#include "card_list.h"
#include <iostream>

using namespace std;



void BST::insert(Card c) {
    insert(c, root, nullptr); // Pass the root and a null parent to start
}


void BST::insert(Card c, Node*& curr, Node* parent) {
    
    if (curr == nullptr) {
        curr = new Node(c);
        curr->parent = parent; 
        return;
    }
    if (c < curr->info) {
        insert(c, curr->left, curr);
    } else if (c > curr->info) {
        insert(c, curr->right, curr);
    } else {
        return;
    }
}

bool BST::remove(const Card c){
    Node * curr = getNodeFor(c, root);
    if(!curr){
        return false;
    }
    if(curr->left&&curr->right){
        Node * succ = getSuccessorNode(curr->info);
        curr->info=succ->info;
        curr=succ;
        
    }
    Node * child;
    if(curr->left){
        child=curr->left;
    }else{
        child=curr->right;
    }
    if (child) child->parent = curr->parent;
    if(!curr->parent){
        root = child;
    } else if((curr->parent->left)==curr){
        curr->parent->left=child;
    } else {
        curr->parent->right=child;
    }
    delete curr;
    return true;
    
}


bool BST::contains(const Card c) const{
    Node* curr = root;
    while(curr!=nullptr){
        if(c<curr->info){
            curr=curr->left;
        }else if(c>curr->info){
            curr=curr->right;
        }else{
            return true;
        }
    }
    return false;
}
void BST::printInOrder() const{
    printInOrder(root);
}
void BST::printInOrder(Node* curr) const{
    if(curr==nullptr){
        return;
    }
    printInOrder(curr->left);
    std::cout<<curr->info<<std::endl;
    printInOrder(curr->right);
}

Node* BST::getNodeFor(Card c, Node* n) const{
    if (n == nullptr) {
        return nullptr;
    }
    if(n->info==c){
        return n;
    }
    if(n->info>c){
        
        return getNodeFor(c, n->left);
        
    }else{
        
        return getNodeFor(c, n->right);
        
    }
}

Node* BST::getSuccessorNode(Card c) const{
    Node * curr = getNodeFor(c, root);
    if(!curr){
        return nullptr;
    }
    if(curr&&curr->right){
            curr=curr->right;
            while(curr->left){
                curr=curr->left;
            }
            return curr;
    }
    Node * currtwo = getNodeFor(c, root)->parent;
    while(currtwo&&currtwo->right==curr){
        curr = currtwo;
        currtwo = curr->parent;
    }
    return currtwo;
}
Card BST::getSuccessor(Card c) const{
    Node * curr = getSuccessorNode(c);
    if(curr){
        return curr->info;
    }else{
        return 0;
    }
}
BST::~BST() { clear(root); }
void BST::clear(Node *n) {
    if (!n) return;
    if (n->left) {
        clear(n->left);
    }
    if (n->right) {
        clear(n->right);
    }
    delete n;
} 
Iterator& Iterator::operator++(){
    if (curr->right) {
        curr = curr->right; 
        while (curr->left) {
            curr = curr->left;
        }
    } else {
        Node* p = curr->parent;
        while (p && curr == p->right) {
            curr = p;
            p = p->parent;
        }
        curr = p;
    }
    return *this;
}
Iterator& Iterator::operator--(){
    if (curr->left) {
        curr = curr->left; 
        while (curr->right) {
            curr = curr->right;
        }
    } else {
        Node* p = curr->parent;
        while (p && curr == p->left) {
            curr = p;
            p = p->parent;
        }
        curr = p;
    }
    return *this;
}
Iterator BST::begin() const{
    Node * curr = root;
    while(curr&&curr->left){
        curr=curr->left;
    }
    return Iterator(curr, this);

};
Iterator BST::end() const{
    return Iterator(nullptr, this);
}
Iterator BST::rbegin() const{
    Node * curr = root;
    while(curr&&curr->right){
        curr=curr->right;
    }
    return Iterator(curr, this);
}
Iterator BST::rend() const{
    return Iterator(nullptr, this);
}
bool Iterator::operator!=(const Iterator& right) const{
    if(curr==right.curr){
        return false;
    }
    return true;
}