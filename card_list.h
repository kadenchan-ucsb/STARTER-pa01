// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include <iostream>
#include <string>
#include "card.h"

class Iterator;

struct Node{
        Card info;
        Node* left;
        Node* right;
        Node* parent;
        Node(const Card& card): info(card), left(nullptr), right(nullptr), parent(nullptr){}
    };

class BST{
    friend class Iterator;
    Node* root;
    public:
        BST(): root(nullptr){}
        ~BST();
        void insert(Card c);
        void insert(Card c, Node*& curr, Node* parent);
        bool remove(const Card c);
        bool contains(const Card c) const;
        void printInOrder() const;
        void printInOrder(Node* curr) const;
        Node* getNodeFor(Card c, Node* n) const;
        Node* getSuccessorNode(Card c) const;   
        Card getSuccessor(Card c) const; 
        void clear(Node *n);
        Iterator begin() const;
        Iterator end() const;
        Iterator rbegin() const;
        Iterator rend() const;





};


class Iterator{
    private:
        friend class BST;
        Node* curr;
        const BST* tree;
    public:
        using iterator_category = std::bidirectional_iterator_tag;

        
        using value_type        = Card;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const Card*;
        using reference         = const Card&;
        Iterator(Node* c, const BST* t): curr(c), tree(t){}
        reference operator*() const { return curr->info; }
        pointer operator->() const { return &(curr->info); }
        Iterator& operator++();
        Iterator& operator--();
        bool operator!=(const Iterator& right) const;
        bool operator==(const Iterator& right) const;
        
};
#endif
