/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the implementation file for the tournament class, which
** has all the data and functions needed to run the Fantasy Combat Tournament.
** To use it, create a tournament object in main. When the tournament runs, the
** user will be asked it they would like to play or quit. If play, they will be
** prompted for how many fighters on teams. For the number of fighters, they 
** will choose the type and enter a nume. Games will be played between the first
** fighter in each lineup. When one is defeated, the loser is put in a container
** of losers and the winner is placed at the end of the lineup. This goes on 
** until one of the team is out of fighters. At that point, a tournament winner
** is announce, a list of losers optionally displayed, and the user is asked if
** they would like to play again or quit the program.
*******************************************************************************/

#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

#include "tournament.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
#include "menu.hpp"

Tournament::Tournament()
{
    srand(time(0));
    run();
}


/*******************************************************************************
** Description: The run function asks the user how many fighters they would
** like for each team and calls a function to create each team lineup. It also
** creates a container to hold the losers. A function to start the tournament
** is called. After the tournament is over, the user is asked if they would like
** to print a list of the losers. The function has no parameters and returns
** nothing.
*******************************************************************************/

void Tournament::run()
{
    int numFightersInLineup;

    cout << "How many fighters would you like on Team A?" << endl;
    numFightersInLineup = getInt(1, 20);
    createLineup(numFightersInLineup, lineupA);

    cout << "\n\nHow many fighters would you like on Team B?" << endl;
    numFightersInLineup = getInt(1, 20);
    createLineup(numFightersInLineup, lineupB);

    losers = new LinkedContainer;

    playTournament();

    vector<string> printOptions = {"Yes", "No"};
    Menu printLosersMenu(printOptions);
    cout << "\nWould you like to print a list of the losers?" << endl;
    int choice = printLosersMenu.run();

    if (choice == 1)
    {
        losers->printLosers();
        cout << "--------------------------------------------------\n\n";
    }
}


/*******************************************************************************
** Description: The createLineup function has two parameters, and integer for
** the number of fighters on the team, and a reference to a lineup container
** for the fighters. For the number of fighters, the user is prompted to 
** choose a type, and a function is called to get the name of the fighter and
** create the fighter object. It is then added to the lineup for that team.
*******************************************************************************/

void Tournament::createLineup(int numFighters, LinkedContainer*& lineup)
{
    lineup = new LinkedContainer;

    for (int i = 0; i < numFighters; i++)
    {
        vector<string> characterOptions = {"Vampire", "Barbarian",
            "Blue Men", "Medusa", "Harry Potter"};

        Menu characterMenu(characterOptions);
        int characterChoice;

        cout << "\nChoose a character for your team:" << endl;
        characterChoice = characterMenu.run();

        Character* character = createCharacter(characterChoice - 1);
        lineup->addBack(character);
    }

    cout << "\n\n--------------------------------------------------\n\n";
}


/*******************************************************************************
** Description: The createCharacter funciton has one parameter, an integer
** representing the character choice made by the user. The function prompts the
** user to enter a name for the character, and then creates and returns a
** pointer to a character with that name.
*******************************************************************************/

Character* Tournament::createCharacter(int character)
{
    string name;

    if (character == VAMPIRE)
    {
        cout << "Enter Vampire fighter name:" << endl;
        getline(cin, name);
        return new Vampire(name);
    }

    else if (character == BARBARIAN)
    {
        cout << "Enter Barbarian fighter name:" << endl;
        getline(cin, name);
        return new Barbarian(name);
    }

    else if (character == BLUE_MEN)
    {
        cout << "Enter Blue Men fighter name:" << endl;
        getline(cin, name);
        return new BlueMen(name);
    }

    else if (character == MEDUSA)
    {
        cout << "Enter Medusa fighter name:" << endl;
        getline(cin, name);
        return new Medusa(name);
    }

    else
    {
        cout << "Enter Harry Potter fighter name:" << endl;
        getline(cin, name);
        return new HarryPotter(name);
    }
}


/*******************************************************************************
** Description: The playTournament function sets the game count and each team's
** score to zero. It checks to make sure there are players in each lineup, and
** if so, increments the game count and calls a function to play a game. It
** then calls a function to display the results and print the score for each
** team. The function has no parameters and returns nothing.
*******************************************************************************/

void Tournament::playTournament()
{
    int gameCount = 0;
    teamAscore = 0;
    teamBscore = 0;

    while (!lineupA->isEmpty() && !lineupB->isEmpty())
    {
        gameCount++;
        playGame(gameCount);
    }

    displayTournamentResults(teamAscore, teamBscore);

    cout << "Team A score: " << teamAscore << endl;
    cout << "Team B score: " << teamBscore << endl;
}


/*******************************************************************************
** Description: The displayTournamentResults function has two parameters, 
** integers for team A and team B scores. It compares the scores and announces
** the winner. Or if the tournement is a tie, it announces that. The function
** returns nothing.
*******************************************************************************/

void Tournament::displayTournamentResults(int aScore, int bScore)
{
    if (aScore > bScore)
    {
        cout << "Team A won the tournament!\n" << endl;
    }

    else if (bScore > aScore)
    {
        cout << "Team B won the tournament!\n" << endl;
    }

    else
    {
        cout << "The tournament was a tie.\n" << endl;
    }
}


/*******************************************************************************
** Description: The playGame function has one parameter, an integer of the
** current game count. The function gets the first figheter in each lineup
** and plays rounds until one of the fighters is dead. It then calls a function
** to display the results of the game. The function returns nothing.
*******************************************************************************/

void Tournament::playGame(int gameCount)
{
    Character* playerA = lineupA->getFront();
    Character* playerB = lineupB->getFront();

    while (!playerDead(playerA) && !playerDead(playerB))
    {
        playRound(playerA, playerB);
    }

    cout << "Game " << gameCount << ":\n" << endl;
    getGameResults(playerA, playerB);
}


/*******************************************************************************
** Description: The playRound function has two parameters, a character pointer
** for the player from Team A and a character pointer for player from Team B.
** Functions are called to run the first attack, and if player B is still alive,
** another attack is called. The function returns nothing.
*******************************************************************************/

void Tournament::playRound(Character* playerA, Character* playerB)
{
    attack(playerA, playerB);

    if (!playerDead(playerB))
    {
        attack(playerB, playerA);
    }
}


/*******************************************************************************
** Description: The attack function has two parameters, a character pointer for
** the attacker and a character pointer for the defender. It calls the attack
** and defense function for characters passed in. The function returns nothing.
*******************************************************************************/

void Tournament::attack(Character* attacker, Character* defender)
{
    int attackPoints = attacker->attack();
    defender->defense(attackPoints);
}


/*******************************************************************************
** Description: THe getGameResults function has two parameters, a character
** pointer for the player from Team A and a character pointer for the player
** from Team B. It announces the players of that game and calls functions to 
** process the winner and loser (move them, restore strength), and then prints
** each team's current score. The function returns nothing.
*******************************************************************************/

void Tournament::getGameResults(Character* playerA, Character* playerB)
{
    cout << "Team A " << playerA->getType() << " " << playerA->getName()
         << " vs. " << "Team B " << playerB->getType() << " " 
         << playerB->getName() << "\n\n";

    if (playerA->getStrength() > playerB->getStrength())
    {
        processWinner(playerA, lineupA);
        processLoser(playerB, lineupB);

        teamAscore += 2;
        teamBscore -= 1;

        if (teamBscore < 0)
        {
            teamBscore = 0;
        }
    }

    else
    {
        processWinner(playerB, lineupB);
        processLoser(playerA, lineupA);

        teamBscore += 2;
        teamAscore -= 1;

        if (teamAscore < 0)
        {
            teamAscore = 0;
        }
    }

    cout << "Team A score: " << teamAscore << endl;
    cout << "Team B score: " << teamBscore << endl;
    cout << "\n--------------------------------------------------\n\n";
}


/*******************************************************************************
** Description: The processWinner function has two parameters, a character
** pointer for the winner, and the winner's lineup. The winner's type and name
** are announced, and their strength restored. They are then moved from the
** front of the container to the back. The function returns nothing.
*******************************************************************************/

void Tournament::processWinner(Character* winner, LinkedContainer* winnerLineup)
{
    cout << winner->getType() << " " << winner->getName() << " won!\n";

    winner->restoreStrength();
    cout << "\nWinner's strength was restored to " 
         << winner->getStrength() << "\n\n";

    winnerLineup->moveFrontToBack();
}


/*******************************************************************************
** Description: The processLoser function has two parameters, a character
** pointer for the defeated player, and a pointer to the loser container.
** A new loser character object is created and added to the loser container and
** the defeated fighter is removed from their team's lineup. The function 
** returns nothing.
*******************************************************************************/

void Tournament::processLoser(Character* loser, LinkedContainer* loserLineup)
{
    Character* defeated;
    string defeatedType = loser->getType();
    string defeatedName = loser->getName();

    if (defeatedType == "Vampire")
    {
        defeated = new Vampire(defeatedName);
    }

    else if (defeatedType == "Barbarian")
    {
        defeated = new Barbarian(defeatedName);
    }

    else if (defeatedType == "BlueMen")
    {
        defeated = new BlueMen(defeatedName);
    }

    else if (defeatedType == "Medusa")
    {
        defeated = new Medusa(defeatedName);
    }

    else
    {
        defeated = new HarryPotter(defeatedName);
    }
    
    losers->addBack(defeated);
    loserLineup->removeFront();
}


/*******************************************************************************
** Description: The playerDead function has one paramenter, a pointer to a
** character. If the characters strength is less than or equal to zero, the
** function returns true. If not, it returns false.
*******************************************************************************/

bool Tournament::playerDead(Character* player)
{
    return player->getStrength() <= 0;
}


/*******************************************************************************
** Description: The destructor function loops through each container that isn't
** empty, calling a function to delete the node from the container. It then
** deletes each container.
*******************************************************************************/

Tournament::~Tournament()
{
    while (!lineupA->isEmpty())
    {
        lineupA->removeFront(); 
    }

    while (!lineupB->isEmpty())
    {
        lineupB->removeFront();
    }
    
    while (!losers->isEmpty())
    {
        losers->removeFront();
    }

    delete lineupA;
    delete lineupB;
    delete losers;
}
