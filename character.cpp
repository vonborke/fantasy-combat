/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the implementation file for the character class. It's
** the base class for vampire, barbarian, blue men, medusa, and harry potter
** classes. The character class has member variables for a characters armor, 
** strength, and name. There are member functions to get name and get strength,
** roll dice, and display the strength and armor values. It has two virtual
** functions for attack and defense which will be overridden in the indivual
** character classes.
*******************************************************************************/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#include "character.hpp"
#include "utility.hpp"


/*******************************************************************************
** Description: The construction has one string parameter user to set the name.
*******************************************************************************/

Character::Character(string name)
{
    this->name = name;
}


/*******************************************************************************
** Description: The getType function returns the character's type.
*******************************************************************************/

string Character::getType()
{
    return type;
}


/*******************************************************************************
** Description: The getName function returns the character's name.
*******************************************************************************/

string Character::getName()
{
    return name;
}


/*******************************************************************************
** Description: The getStrength function returns the character's strength.
*******************************************************************************/

int Character::getStrength()
{
    return strength;
}


/*******************************************************************************
** Description: The roll function has two integer parameters, one for the 
** number of dice to be rolled, and another for the number of side the dice
** have. It generates radom values for each roll and returns the total roll as
** an integer.
*******************************************************************************/

int Character::roll(int numberOfDice, int numberOfSides)
{
    int totalRoll = 0;

    for (int i = 0; i < numberOfDice; i++)
    {
        totalRoll += getRandNum(1, numberOfSides);
    }

    return totalRoll;
}


/*******************************************************************************
** Description: The medusaGlared function has an integer parameter for the
** number of attack points. If the number of points is equal to medusa's glare
** value, a message is displayed that the defender was killed and its strength
** is set to zero. The function returns true if medusa glared and killed, and
** false if not.
*******************************************************************************/

bool Character::medusaGlared(int attackRoll)
{
    if (attackRoll == 1000)
    {
        cout << "Medusa's glare killed defender." << endl;
        strength = 0;
        return true;
    }

    return false;
}


/*******************************************************************************
** Description: The displayStrengthAndArmor function displays the character's
** strength and armor values. It has no parameters and returns nothing.
*******************************************************************************/

void Character::displayStrengthAndArmor()
{
    cout << "Defender's strength: " << strength << endl;
    cout << "Defender's armor: " << armor << endl;
}


/*******************************************************************************
** Description: The restoreStrength function gets a random integer between
** 1 and 3 and uses that to determine how much of the character's strength is
** restored after combat. If the random number is 3, they gain a third of their
** lost strength back. If the random number is a 2, they gain half of their lost
** strength back. If it's a 1, their strength is fully restored. The function
** has no parameters and returns nothing.
*******************************************************************************/

void Character::restoreStrength()
{
    int rand = roll(1, 3);
    
    if (rand == 3)
    {
        strength = strength + ((maxStrength - strength) / 3);
    }

    else if (rand == 2)
    {
        strength = strength + ((maxStrength - strength) / 2);
    }

    else 
    {
        strength = maxStrength;
    }
}

Character::~Character()
{
}
