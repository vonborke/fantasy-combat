/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the declaration file for the medusa class. It's
** derived from the character class and inherits member variables for name,
** armor, and strength, assigning them the appropriate values for this class. 
** The attack function is overridden to roll the dice for this character and
** display the results. It also overrides the defense function, displaying
** this character's strenth and armor, rolling defense points, calculating
** damage, updating strength and displaying the results.
*******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class Medusa : public Character
{
    public:
        Medusa(string name);
        virtual int attack();
        virtual void defense(int attackRoll);
        virtual ~Medusa();
};

#endif
