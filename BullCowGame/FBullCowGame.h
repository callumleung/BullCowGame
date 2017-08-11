#pragma once
#include <string>
#include <map>
#define TMap std::map

using FString = std:: string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Word_Too_Short,
	Word_Too_Long,
	Wrong_Word_Length, //catch all for use before implementing too long/ too short
	Invalid_Character,
	Not_Lowercase //is better to cast the given word to lower case I think
};



class FBullCowGame {
public:

	FBullCowGame(); //constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString CurrentGuess) const;

	void Reset(); // TODO make a more rich return value

	// counts bulls and cows and increases try #, assuming valid guess
	FBullCowCount SubmitValidGuess(FString);


private:

	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon;
	bool IsIsogram(FString word) const;

};