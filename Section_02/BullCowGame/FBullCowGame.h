#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); //constructor


	int32 GetMaxTries() const;
	int32 GetCurrentTry()const;
	bool IsGameOver()const;

	void Reset(); //Make a more rich return value
	bool CheckGuessValidity(FString); //Make a more rich return value

	//Provide a method for counting bulls and cows, and increasing guess number




private:
	//SEE CONSTRUCTOR FOR INITIALIZATION
	int32 MyCurrentTry;
	int32 MyMaxTries;
};