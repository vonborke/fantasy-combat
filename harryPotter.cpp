/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the implementation file for the harryPotter class. It's
** derived from the character class and inherits member variables for name,
** armor, and strength, assigning them the appropriate values for this class. 
** The attack function is overridden to roll the dice for this character and
** display the results. It also overrides the defense function, displaying
** this character's strenth and armor, rolling defense points, calculating
** damage, updating strength and displaying the results.
*******************************************************************************/

#include "harryPotter.hpp"


/*******************************************************************************
** Description: The constructor function has one string parameter which is
** used to set the name variable of the character. It also initializes the
** armor and strength values. It has one unique bool variable that represents
** whether the character has died once already.
*******************************************************************************/

HarryPotter::HarryPotter(string name) : Character(name)
{
    this->type = "Harry Potter";
    this->name = name;
    this->armor = 0;
    this->strength = 10;
    this->maxStrength = 10;
    this->hasDiedOnce = false;
}


/*******************************************************************************
** Description: The attack function rolls the attack dice for this character
** and displays and returns the results as an integer. It has no parameters.
*******************************************************************************/

int HarryPotter::attack()
{
    int attackRoll = roll(2, 6);
    // cout << "Attacker's roll: " << attackRoll << endl;
    return attackRoll;
}


/*******************************************************************************
** Description: The defense function has one parameters, an integer representing
** the attack points. The function first checks to see if medusa glared. If so,
** and if harry has already dies once, he dies. If she glares and he hasn't died
** yet, he uses his special power to come back to life. If there is no medusa
** glare, dice are rolled for defense, calculates damage, updates strength. If
** harry's strength goes to zero or less, he has the special ability to come
** back to life once. 
*******************************************************************************/

void HarryPotter::defense(int attackRoll)
{
    // if medusa attacked
    if (attackRoll == 1000)
    {
        // if harry has already died once, medusa's glare kills him
        if (hasDiedOnce)
        {
            medusaGlared(attackRoll);
        }

        // else, he uses hogwarts and his strenth is set to 20
        else
        {
            // cout << "Harry Potter uses Hogwarts!" << endl;
            hasDiedOnce = true;
            strength = 20;
        }
    }

    else
    {
        // displayStrengthAndArmor();

        int defenseRoll = roll(2, 6);
        int damage = attackRoll - defenseRoll - armor;

        if (damage < 0)
        {
            damage = 0;
        }

        strength -= damage;

        // cout << "Defender's roll: " << defenseRoll << endl;
        // cout << "Damage inflicted: " << damage << endl;

        if (strength <= 0 && !hasDiedOnce)
        {
            // cout << "Harry Potter uses Howarts!" << endl;
            hasDiedOnce = true;
            strength = 20;
        }
    }

    // cout << "\nDefender's current strength: " << strength << endl;
}

HarryPotter::~HarryPotter()
{
}
