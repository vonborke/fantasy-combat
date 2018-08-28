/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the implementation file for the linkedContainer class.
** It has all data and fuctions needed to create lineups and a loser container
** using a circular linked list. It has a member variable to keep track of the
** head of the lineup and member functions to check if lineup is empty, add a
** character to the back of the lineup, get the character at the head of the
** lineup, remove the first node. There is a function to move a fighter from
** the front of the lineup to the back, and a function to print a list of the
** losers in the reverse order they were added to the list.
*******************************************************************************/

#include <iostream>
using std::cout;
using std::endl;

#include "linkedContainer.hpp"


LinkedContainer::LinkedContainer()
{
    head = nullptr;
}


/*******************************************************************************
** Description: The isEmpty function has no parameters. It returns true if the
** container is empty, false if not.
*******************************************************************************/

bool LinkedContainer::isEmpty()
{
    // if there is no head, there is no container
    return !head;
}


/*******************************************************************************
** Description: The addBack function has one integer parameter, the character to
** be added to the back of the container. If the container is empty, a new node
** is created and its previous and next pointers point to the new node. If there
** is already one or more nodes, the new node is added to the back of container
** and the pointers are adjusted as needed. The function returns nothing.
*******************************************************************************/

void LinkedContainer::addBack(Character* character)
{
    // if container is empty, create new node
    if (isEmpty())
    {
        head = new CharacterNode(character, nullptr, nullptr);

        // make head's next and prev point to head since list is circular
        head->prev = head;
        head->next = head;
    }

    // else, create new node and reassign prev and next for nodes involved
    else
    {
        CharacterNode* oldBack = head->prev;
        CharacterNode* newBack = new CharacterNode(character, oldBack, head);
        head->prev = newBack;
        oldBack->next = newBack;
    }
}


/*******************************************************************************
** Description: The getFront function returns an integer of the first node's
** character. It has no parameters.
*******************************************************************************/

Character* LinkedContainer::getFront()
{
    return head->character;
}


/*******************************************************************************
** Description: The removeFront function removes the head node and deallocates
** the memory. If the container is empty, it prints a message that it's empty.
** The function has no parameters and returns nothing.
*******************************************************************************/

void LinkedContainer::removeFront()
{
    if (isEmpty())
    {
        cout << "Unable to remove front because container is empty." << endl;
    }

    // if there is only one node, delete it and set head to null
    else if (head == head->next)
    {
        delete head->getCharacter();
        delete head;
        head = nullptr;
    }
    
    // else, delete current head and reassign prev and next for nodes involved
    else
    {
        CharacterNode* newHead = head->next;
        newHead->prev = head->prev;
        head->prev->next = newHead;
        delete head->getCharacter();
        delete head;
        head = newHead;
    }
}


/*******************************************************************************
** Description: The moveFrontToBack function makes the head the next node.
** The function has no parameters and returns nothing.
*******************************************************************************/

void LinkedContainer::moveFrontToBack()
{
    if (!isEmpty())
    {
        head = head->next;   
    }
}


/*******************************************************************************
** Description: The printLosers function prints out the fighters in the 
** container, beginning with the last one added and finishing with the first
** one added. The function has no parameters and returns nothing.
*******************************************************************************/

void LinkedContainer::printLosers()
{
    if (isEmpty())
    {
        cout << "There are no losers." << endl;
    }

    else
    {
        CharacterNode* currentNode = head->prev;
        Character* loser;

        cout << "Losers are:\n" << endl;

        do
        {
            loser = currentNode->character;
            cout << loser->getType() << " " << loser->getName() << endl;
            currentNode = currentNode->prev;
        } 
        while (currentNode != head->prev);

        cout << endl;
    }
}

LinkedContainer::~LinkedContainer()
{
}
