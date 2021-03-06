/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the declaration file for the blueMen class. It's
** derived from the character class and inherits member variables for name,
** armor, and strength, assigning them the appropriate values for this class. 
** The attack function is overridden to roll the dice for this character and
** display the results. It also overrides the defense function, displaying
** this character's strenth and armor, rolling defense points, calculating
** damage, updating strength and displaying the results.
*******************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class BlueMen : public Character
{
    public:
        BlueMen(string name);
        virtual int attack();
        virtual void defense(int attackRoll);
        virtual ~BlueMen();
};

#endif
