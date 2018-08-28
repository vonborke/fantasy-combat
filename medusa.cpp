/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the implementation file for the medusa class. It's
** derived from the character class and inherits member variables for name,
** armor, and strength, assigning them the appropriate values for this class. 
** The attack function is overridden to roll the dice for this character and
** display the results. It also overrides the defense function, displaying
** this character's strenth and armor, rolling defense points, calculating
** damage, updating strength and displaying the results.
*******************************************************************************/

#include "medusa.hpp"


/*******************************************************************************
** Description: The constructor function has one string parameter which is
** used to set the name variable of the character. It also initializes the
** armor and strength values.
*******************************************************************************/

Medusa::Medusa(string name) : Character(name)
{
    this->type = "Medusa";
    this->name = name;
    this->armor = 3;
    this->strength = 8;
    this->maxStrength = 8;
}


/*******************************************************************************
** Description: The attack function rolls the attack dice for this character.
** If the roll is 12, it triggers medusa's special glare power and returns 1000,
** a number that no other character can beat. If she doesn't roll a 12, it
** displays and returns an integer of roll result. It has no parameters.
*******************************************************************************/

int Medusa::attack()
{
    int attackPoints;
    int attackRoll = roll(2, 6);

    // cout << "Attacker's roll: " << attackRoll << endl;

    if (attackRoll == 12)
    {
        // cout << "Medusa uses Glare!" << endl;
        attackPoints = 1000;
    }

    else
    {
        // attackPoints = attackRoll;
    }

    return attackPoints;
}


/*******************************************************************************
** Description: The defense function has one parameters, an integer representing
** the attack points. It displays the strength and armor values, rolls dice
** for defense, calculates damage, updates strength, and displays the results.
** It has no parameters.
*******************************************************************************/

void Medusa::defense(int attackRoll)
{
    if (!medusaGlared(attackRoll))
    {
        // displayStrengthAndArmor();

        int defenseRoll = roll(1, 6);
        int damage = attackRoll - defenseRoll - armor;

        if (damage < 0)
        {
            damage = 0;
        }

        strength -= damage;

        // cout << "Defender's roll: " << defenseRoll << endl;
        // cout << "Damage inflicted: " << damage << endl;
        // cout << "\nDefender's current strength: " << strength << endl;
    }
}

Medusa::~Medusa()
{
}
