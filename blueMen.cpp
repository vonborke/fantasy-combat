/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the implementation file for the blueMen class. It's
** derived from the character class and inherits member variables for name,
** armor, and strength, assigning them the appropriate values for this class. 
** The attack function is overridden to roll the dice for this character and
** display the results. It also overrides the defense function, displaying
** this character's strenth and armor, rolling defense points, calculating
** damage, updating strength and displaying the results.
*******************************************************************************/

#include "blueMen.hpp"


/*******************************************************************************
** Description: The constructor function has one string parameter which is
** used to set the name variable of the character. It also initializes the
** armor and strength values.
*******************************************************************************/

BlueMen::BlueMen(string name) : Character(name)
{
    this->type = "Blue Men";
    this->name = name;
    this->armor = 3;
    this->strength = 12;
    this->maxStrength = 12;
}


/*******************************************************************************
** Description: The attack function rolls the attack dice for this character
** and displays and returns the results as an integer. It has no parameters.
*******************************************************************************/

int BlueMen::attack()
{
    int attackRoll = roll(2, 10);
    // cout << "Attacker's roll: " << attackRoll << endl;
    return attackRoll;
}


/*******************************************************************************
** Description: The defense function has one parameters, an integer representing
** the attack points. It displays the strength and armor values. The blue men
** lose one die for every 4 points of strenth lost. If and dice remain, they are
** rolled as defense, calculates damage, updates strength, and displays results.
** It has no parameters.
*******************************************************************************/

void BlueMen::defense(int attackRoll)
{
    if (!medusaGlared(attackRoll))
    {
        // displayStrengthAndArmor();

        int numDice = strength / 4;

        // cout << "Number of dice to roll: " << numDice << endl;

        int defenseRoll;

        if (numDice > 0)
        {
            defenseRoll = roll(numDice, 6);
            // cout << "Defender's roll: " << defenseRoll << endl;
        }

        else
        {
            defenseRoll = 0;
            // cout << "Defender has no dice to roll." << endl;
        }

        int damage = attackRoll - defenseRoll - armor;

        if (damage < 0)
        {
            damage = 0;
        }

        strength -= damage;

        // cout << "Damage inflicted: " << damage << endl;
        // cout << "\nDefender's current strength: " << strength << endl;
    }
}

BlueMen::~BlueMen()
{
}
