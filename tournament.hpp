/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Authors: Kelly von Borstel
** Date: 3/4/2018
** Description: This is the declaration file for the tournament class, which
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

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include "character.hpp"
#include "linkedContainer.hpp"

enum CharacterType {VAMPIRE, BARBARIAN, BLUE_MEN, MEDUSA, HARRY_POTTER};

class Tournament
{
    private:
        LinkedContainer* lineupA;
        LinkedContainer* lineupB;
        int teamAscore;
        int teamBscore;
        LinkedContainer* losers;

    public:
        Tournament();
        void run();
        void createLineup(int numFighters, LinkedContainer*& lineup);
        Character* createCharacter(int character);
        void playTournament();
        void displayTournamentResults(int aScore, int bScore);
        void playGame(int gameCount);
        void playRound(Character* playerA, Character* playerB);
        void attack(Character* attacker, Character* defender);
        void getGameResults(Character* playerA, Character* playerB);
        void processWinner(Character* winner, LinkedContainer* winnerLineup);
        void processLoser(Character* loser, LinkedContainer* loserLineup);
        bool playerDead(Character* player);
        ~Tournament();
};

#endif
