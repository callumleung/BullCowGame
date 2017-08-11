#include "FBullCowGame.h"
#include <string>

using FString = std::string;
using int32 = int;

void FBullCowGame::Reset()
{
	
	MyMaxTries = 5;
	bIsGameWon = false;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

FBullCowGame::FBullCowGame()
{
	Reset();


}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}





int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bIsGameWon;
}

EGuessStatus FBullCowGame:: CheckGuessValidity(FString CurrentGuess) const
{
	//if guess isnt an isogram
	if (!IsIsogram(CurrentGuess))
	{
		return EGuessStatus::Not_Isogram;//TODO write function
	}

	//if guess isnt all lower case
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;//TODO write function
	}

	//if the guess length is wrong 
	else if (CurrentGuess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Word_Length;
	}

	//otherwise
	else
	{
		return EGuessStatus::OK;
	}




	return EGuessStatus::OK;
}


//recives a valid guess, increments turn and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	
	MyCurrentTry++;

	
	FBullCowCount FBullCowCount;

	//hidden word and guess length must be the same to have reached this method
	int32 WordLength = MyHiddenWord.length();
	//loop through all letters in guess
	for (int32 i = 0; i < WordLength; i++) {

		//compare letters against hidden word

		for (int32 j = 0; j < WordLength; j++) {


			if (Guess[j] == MyHiddenWord[j] && i == j) //matches in exact position
			{
				FBullCowCount.Bulls++;
			}
			else if (Guess[i] == MyHiddenWord[j]) //matches in any position
			{
				FBullCowCount.Cows++;
			}
		
			//if match then:
				//increment bulls if in same place
			//else
				//increment cows if not
		}
	}

	if (FBullCowCount.Bulls == WordLength)
	{
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}
	return FBullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms

	//set up map
	if (Word.length() <= 1)
	{
		true;
	}

	TMap <char, bool> LetterSeen;

	for (auto Letter : Word)
	{

		Letter = tolower(Letter);
		//loop through letters of guess 
		if (LetterSeen[Letter])
		{
			return false; //not an isogram if already seen
		}
		else {
			LetterSeen[Letter] = true;
			//otherwise
				//add letter to map as seen
		}

	}
	return true; //for example if /0 is entered 
}
