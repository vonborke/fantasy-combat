/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the implementation file for the vampire class. It's
** derived from the character class and inherits member variables for name,
** armor, and strength, assigning them the appropriate values for this class. 
** The attack function is overridden to roll the dice for this character and
** display the results. It also overrides the defense function, displaying
** this character's strenth and armor, rolling defense points, calculating
** damage, updating strength and displaying the results.
*******************************************************************************/

#include "vampire.hpp"


/*******************************************************************************
** Description: The constructor function has one string parameter which is
** used to set the name variable of the character. It also initializes the
** armor and strength values.
*******************************************************************************/

Vampire::Vampire(string name) : Character(name)
{
    this->type = "Vampire";
    this->name = name;
    this->armor = 1;
    this->strength = 18;
    this->maxStrength = 18;
}


/*******************************************************************************
** Description: The attack function rolls the attack dice for this character
** and displays and returns the results as an integer. It has no parameters.
*******************************************************************************/

int Vampire::attack()
{
    int attackRoll = roll(1, 12);
    // cout << "Attacker's roll: " << attackRoll << endl;
    return attackRoll;
}


/*******************************************************************************
** Description: The defense function has one parameters, an integer representing
** the attack points. It first gets a random number to determine if the charm
** power will be used. If so, it displays a message and the attack is over. If
** not, it displays the strength and armor values, rolls dice for defense, 
** calculates damage, and updates strength. In either case, it displays the
** updated strength. The function has no parameters.
*******************************************************************************/

void Vampire::defense(int attackRoll)
{
    int charm = getRandNum(0, 1);

    // if (charm)
    // {
        // cout << "Vampired charmed opponent.\nAttack never happened!\n";
    // }

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
    }

    // cout << "\nDefender's current strength: " << strength << endl;
}

Vampire::~Vampire()
{
}
