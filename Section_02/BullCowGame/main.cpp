// main.cpp : Defines the entry point for the console application.
//

/*This is the console executable that makes use of the bull cow class.This acts as the view in a MVC pattern and is responsiible for all user interaction. .For game logic see the FBullcowgame class*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetGuess();
bool AskToPlayAgain();


FBullCowGame BCGame;

int main()
{
	//LOOP FOR MAX GUESSES
	bool bWantsToPlayAgain = false;
	do
	{
	PrintIntro();
	PlayGame();
	//TODO ADD A GAME SUMMARY
	bWantsToPlayAgain = AskToPlayAgain();
	} while (bWantsToPlayAgain);

	return 0;
}

// introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 4;
	std::cout << "Welcome to Bulls and Cows a pretty crap word game.\n";
	std::cout << "Can you guess the word i am thinking of?\n";
	std::cout << "The word is " << WORD_LENGTH;
	std::cout << " characters long\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	 //instantiate a new game. Make an instance of a new game
	int32 MaxTries = BCGame.GetMaxTries();

	//LOOP for number of turns asking for guesses
	//TODO change from FOR to While loop once we are validating tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		Ftext Guess = GetGuess(); //TODO Make loop to check valid guesses
		//SUBMIT VALID GUESS TO GAME
		//Print Number of bulls and Cows
		
		std::cout << "Your Guess was '" << Guess << "'" << std::endl;
		std::cout << std::endl;
	}
	//TODO SUMMARISE GAME
}

Ftext GetGuess()

{
		int32 MyCurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << MyCurrentTry << ". ";
		std::cout << "Please input your guess:\0";
		Ftext Guess = "";
		std::getline(std::cin, Guess);

	return Guess;

}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again?\n";
	Ftext Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'Y' || Response[0] == 'y');
}