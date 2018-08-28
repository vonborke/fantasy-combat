/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This program is a Fantasy Combat Tournament with Vampire, 
** Barbarian, Blue Men, Medusa, and Harry Potter characters. The characters each
** have their own methods of attacking and defending. Some have armor or special
** powers. There are two teams of character fighters. The fighters are lined up
** to fight in the order they are entered by the user. Each fighter starts with
** a certain level of strength, and lose points as they battle each other until
** one is defeated. The loser is moved to a stack of losers, and the winner is
** moved to the back of their team's lineup. The combat continues until one of
** the teams runs out of players. The team with the highest score at that point
** wins the tournament. To run the program, type "make" at the command line, 
** then type "./combat", then follow the prompts.
*******************************************************************************/

#include <vector>
using std::vector;

#include "tournament.hpp"
#include "menu.hpp"

int main()
{
    cout << "\n\n--------------------------------------------------\n\n";
    cout << "\nWelcome to Fantasy Combat Tournament!\n" << endl;

    cout << "Choose an option:" << endl;
    vector<string> startOptions = {"Play", "Exit"};
    Menu startMenu(startOptions);
    int choice = startMenu.run();

    while (choice == 1)
    {
        Tournament fantasyCombat;
        cout << "Choose an option:" << endl;
        vector<string> endOptions = {"Play again", "Exit"};
        Menu endMenu(endOptions);
        choice = endMenu.run();
    }

    return 0;
}
