/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the declaration file for the linkedContainer class.
** It has all data and fuctions needed to create lineups and a loser container
** using a circular linked list. It has a member variable to keep track of the
** head of the lineup and member functions to check if lineup is empty, add a
** character to the back of the lineup, get the character at the head of the
** lineup, remove the first node. There is a function to move a fighter from
** the front of the lineup to the back, and a function to print a list of the
** losers in the reverse order they were added to the list.
*******************************************************************************/

#ifndef LINKED_CONTAINER_HPP
#define LINKED_CONTAINER_HPP

#include "character.hpp"

class CharacterNode
{
    public:
        Character* character;
        CharacterNode* prev;
        CharacterNode* next;

        // The constructor has three parameters, a pointer to a character and 
        // two CharacterNode pointers to previous and next nodes in container.
        CharacterNode(Character* c, CharacterNode* p, CharacterNode* n)
        {
            character = c;
            prev = p;
            next = n;
        }

        Character* getCharacter()
        {
            return character;
        }
};

class LinkedContainer
{
    private:
        CharacterNode* head;

    public:
        LinkedContainer();
        bool isEmpty();
        void addBack(Character* character);
        Character* getFront();
        void removeFront();
        void moveFrontToBack();
        void printLosers();
        ~LinkedContainer();
};

#endif
