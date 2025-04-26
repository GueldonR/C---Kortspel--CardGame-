//
// main.cpp
// Gueldons_kortspel
//
// Created by Gueldon Roble on 2023-12-06.
// Last edited Friday 24 dec 2023 14.08
//
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Globala variabler för namn
string playerName2;
string playerName1;

// Globala initierade variabler för vinster och förluster
int wonGamesP1 = 0;
int wonGamesP2 = 0;
int lostGamesP1 = 0;
int lostGamesP2 = 0;

// Arrayer av strings element, indexerade efter en kortleks valörer och färger
string valueString[13]{"Ace", "2", "3", "4", "5", "6", "7",
                       "8", "9", "10", "Jack", "Queen", "King"};
string suitString[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

// Funktioner
void welcomeMessage();
string doesPlayerHaveFriend();
void getNameP1();
void getNameP2();
void displayNames();
void preGameProtocol();
void pressOneToDraw();
void pressTwoToDraw();
void pressFourResults();
void roundWinnerBySuit(int p1suit, int p2suit, int &p1points, int &p2points);
void roundWinnerByValue(int p1value, int p2value, int p1type, int p2type, int &p1points, int &p2points);
void showGameWinner(int p1points, int p2points, const int winScore);
void scoreBoard(int lostGamesP1, int lostGamesP2, int wonGamesP1, int wonGamesP2, int p1points, int p2points);
int randomiseCardValue();
int randomiseCardSuit();
void storeWinLoss(int &lostGamesP1, int &lostGamesP2, int p1points, int p2points, int &wonGamesP2, int &wonGamesP1);
void winLossTable(int lostGamesP1, int lostGamesP2, int wonGamesP1, int wonGamesP2);
void gameSequence();

int main()
{
    bool playAgain = true;
    preGameProtocol();

    while (playAgain)
    {
        gameSequence();

        char response;
        cout << endl
             << "PLAY AGAIN? (y/n): ";
        cin >> response;

        if (response != 'y')
        {
            playAgain = false;
        }
    }

    winLossTable(lostGamesP1, lostGamesP2, wonGamesP1, wonGamesP2);
    cout << endl
         << "Thanks for playing!" << endl;

    return 0;
}

void pressOneToDraw()
{
    string playerOneinput = "0";
    while (playerOneinput != "1")
    {
        cout << endl
             << "Press 1 and ENTER to draw card for: " << playerName1 << endl;
        cin >> playerOneinput;
    }
}

void pressTwoToDraw()
{
    string playerTwoinput = "0";
    while (playerTwoinput != "2")
    {
        cout << "Press 2 and then the ENTER key to draw card for " << playerName2 << endl;
        cin >> playerTwoinput;
    }
}

void pressFourResults()
{
    string revealResults = "0";
    while (revealResults != "4")
    {
        cout << "Press 4 and then the ENTER key to reveal the results" << endl;
        cin >> revealResults;
    }
}

string doesPlayerHaveFriend()
{
    string inputChoice;
    cout << "Do you have a friend?...<y/n>" << endl;
    cin >> inputChoice;
    return inputChoice;
}

void welcomeMessage()
{
    cout << "Welcome to Gueldons Card game" << endl
         << "You play as 2 players, so it's more fun to get a friend before you start" << endl;

    string choice = doesPlayerHaveFriend();

    if (choice == "y")
    {
        cout << "Let's name you two..." << endl;
    }
    else if (choice == "n")
    {
        cout << "No problem you can just play with yourself!" << endl;
    }
    else
    {
        cout << "Ahh well... You can't take instructions to save your life...." << endl;
    }
}

void getNameP1()
{
    cout << "Enter name for player one: ";
    cin >> playerName1;
}

void getNameP2()
{
    cout << "Enter name for player two: ";
    cin >> playerName2;
}

void displayNames()
{
    cout << "Selected Player Names Below:" << endl
         << "P1: " << playerName1 << " vs P2: " << playerName2 << endl;
}

void preGameProtocol()
{
    welcomeMessage();
    getNameP1();
    getNameP2();
    displayNames();
}

int randomiseCardValue()
{
    return rand() % 13;
}

int randomiseCardSuit()
{
    return rand() % 4;
}

void roundWinnerBySuit(int p1suit, int p2suit, int &p1points, int &p2points)
{
    if (p1suit > p2suit)
    {
        cout << "Round results: " << playerName1 << " wins this round by the card's suit value." << endl;
        p1points++;
    }
    else if (p1suit < p2suit)
    {
        cout << "Round results: " << playerName2 << " wins this round by the card's suit value." << endl;
        p2points++;
    }
    else
    {
        cout << "Oops! The two cards have identical suit values, so this round won't result in points." << endl;
    }
}

void roundWinnerByValue(int p1value, int p2value, int p1type, int p2type, int &p1points, int &p2points)
{
    if (p1value > p2value)
    {
        cout << "Round results: " << playerName1 << " wins this round by the card's numeric value." << endl;
        p1points++;
    }
    else if (p1value == p2value)
    {
        cout << "Values were the same, checking card type..." << endl;
        roundWinnerBySuit(p1type, p2type, p1points, p2points);
    }
    else
    {
        cout << "Round results: " << playerName2 << " wins this round by the card's numeric value." << endl;
        p2points++;
    }
}

void showGameWinner(int p1points, int p2points, const int winScore)
{
    if (p1points == winScore)
    {
        cout << "Winner of this match is " << playerName1 << endl;
    }
    else if (p2points == winScore)
    {
        cout << "Winner of this match is " << playerName2 << endl;
    }
}

void storeWinLoss(int &lostGamesP1, int &lostGamesP2, int p1points, int p2points, int &wonGamesP2, int &wonGamesP1)
{
    if (p1points > p2points)
    {
        wonGamesP1++;
        lostGamesP2++;
    }
    else
    {
        wonGamesP2++;
        lostGamesP1++;
    }
}

void scoreBoard(int lostGamesP1, int lostGamesP2, int wonGamesP1, int wonGamesP2, int p1points, int p2points)
{
    cout << "======================" << endl;
    cout << " Scoreboard" << endl;
    cout << "======================" << endl;
    cout << "P1: " << playerName1 << " Wins: " << wonGamesP1 << " Losses: " << lostGamesP1 << " Points: " << p1points << endl;
    cout << "P2: " << playerName2 << " Wins: " << wonGamesP2 << " Losses: " << lostGamesP2 << " Points: " << p2points << endl;
    cout << "======================" << endl;
}

void winLossTable(int lostGamesP1, int lostGamesP2, int wonGamesP1, int wonGamesP2)
{
    cout << "#### WIN-LOSS TABLE ####" << endl;
    cout << playerName1 << " - Wins: " << wonGamesP1 << " | Losses: " << lostGamesP1 << endl;
    cout << playerName2 << " - Wins: " << wonGamesP2 << " | Losses: " << lostGamesP2 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void gameSequence()
{
    srand(time(0));

    int p1cardValue, p1cardSuit, p2cardValue, p2cardSuit;
    int p1Points = 0, p2Points = 0;
    const int winScore = 2;

    while (p1Points < winScore && p2Points < winScore)
    {
        pressOneToDraw();
        p1cardValue = randomiseCardValue();
        p1cardSuit = randomiseCardSuit();
        cout << playerName1 << " drew: " << valueString[p1cardValue] << " of " << suitString[p1cardSuit] << endl;

        pressTwoToDraw();
        p2cardValue = randomiseCardValue();
        p2cardSuit = randomiseCardSuit();
        cout << playerName2 << " drew: " << valueString[p2cardValue] << " of " << suitString[p2cardSuit] << endl;

        pressFourResults();
        roundWinnerByValue(p1cardValue, p2cardValue, p1cardSuit, p2cardSuit, p1Points, p2Points);
        scoreBoard(lostGamesP1, lostGamesP2, wonGamesP1, wonGamesP2, p1Points, p2Points);
    }

    storeWinLoss(lostGamesP1, lostGamesP2, p1Points, p2Points, wonGamesP2, wonGamesP1);
    showGameWinner(p1Points, p2Points, winScore);
}