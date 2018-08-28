/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the declaration file for the character class. It's
** the base class for vampire, barbarian, blue men, medusa, and harry potter
** classes. The character class has member variables for a characters armor, 
** strength, and name. There are member functions to get name and get strength,
** roll dice, and display the strength and armor values. It has two virtual
** functions for attack and defense which will be overridden in the indivual
** character classes.
*******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#include "utility.hpp"

class Character
{
    protected:
        int armor;
        int strength;
        int maxStrength;
        string type;
        string name;

    public:
        Character(string name);
        virtual int attack() = 0;
        virtual void defense(int attackDamage) = 0;
        string getType();
        string getName();
        int getStrength();
        int roll(int numberOfDice, int numberOfSides);
        bool medusaGlared(int attackRoll);
        void displayStrengthAndArmor();
        void restoreStrength();
        virtual ~Character();
};

#endif
