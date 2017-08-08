#include "FBullCowGame.h"
#include <string>

using FString = std::string;
using int32 = int;

void FBullCowGame::Reset(int32 MaxTries)
{
	
	MyMaxTries = MaxTries;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

FBullCowGame::FBullCowGame()
{
	Reset(8);


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
	return false;
}

EGuessStatus FBullCowGame:: CheckGuessValidity(FString CurrentGuess) const
{
	//if guess isnt an isogram
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}

	//if guess isnt all lower case
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment turn number
	MyCurrentTry++;

	//set up return variable
	FBullCowCount FBullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	//loop through all letters in guess
	for (int32 i = 0; i < HiddenWordLength; i++) {

		//compare letters against hidden word

		for (int32 j = 0; j < HiddenWordLength; j++) {


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
	return FBullCowCount;
}
