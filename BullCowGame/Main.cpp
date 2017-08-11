/*This is the console executable, that makes use of the BullCow class. 
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see FBullCowGame class.


*/



#include <iostream>
#include <string>
#include "FBullCowGame.h"

//using namespace std;
using FText = std::string;
using int32 = int;


void printIntro();
void PrintGameSummary(bool);
void PlayGame();
void PrintGuess(FText);
FText GetValidGuess();
bool AskToPlayAgain();


FBullCowGame BCGame; //instantiate a new game


int main()
{

	bool bPlayAgain = false;
	do {
		printIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		
	} 
	while (bPlayAgain);
	

	return 0;
	
}

void PlayGame()
{
	BCGame.Reset(); 
	int MaxTries = BCGame.GetMaxTries();
	std::cout << "Max tries = " << MaxTries << std:: endl;

	//TODO  change to while loop
	//loop asking for guess until game is oine and bool isGameWon is true
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {


		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess. \n";
		FText Guess = GetValidGuess(); //TODO vaildate guess

	
		
		//submit valid guess and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//print number of cows and bulls
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "." << std:: endl;
		//PrintGuess(Guess);
		//std:: cout << "Guesses remaining:" << BCGame.GetMaxTries() - BCGame.GetCurrentTry() << std::endl << std::endl;

		//TODO summarise game
	}

	PrintGameSummary(BCGame.IsGameWon());
}


//Game intro


void printIntro() {
	// int32 WORD_LENGTH = BCGame.GetHiddenWordLength;
	std:: cout << "\n\nWelcome to Bulls and Cows. \n";
	std:: cout << "Guess the " << BCGame.GetHiddenWordLength();
	std:: cout << " letter isogram.\n";

	return;
}

void PrintGameSummary(bool IsGameWon) {

	if (IsGameWon)
	{
		std::cout << "Congratulations! You won!\n";
	}
	else
	{
		std::cout << "Better luck next time...\n";
	}

	return;
}
//read in guess and return guess
//loop continually until valid guess is entered
FText GetValidGuess() {

	EGuessStatus Status = EGuessStatus::Invalid_Character;
	FText Guess = "";
	do {
		//get guess from player
		std::cout << "Enter isogram guess: ";
		
		std::getline(std::cin, Guess);

		//checking for valid guess length
		 Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{

		case EGuessStatus::Wrong_Word_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " word.\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter guess in lowercase format." << std::endl;
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram guess. \n";
			break;

		default:
			break;
		}


		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //keep looping until no errors are returned
	return Guess;
}

bool AskToPlayAgain()
{
	std:: cout << "Do you want to play again with the same hidden word? (y/n)\n";
	FText response = "";
	std::getline(std::cin, response);
	std:: cout << std:: endl;
	return (response[0] == 'y' || response[0] == 'Y');
}

//pass the guess to the function and print to console
void PrintGuess(FText Guess) {

	
	std:: cout << "Guess was " << Guess << std:: endl;
}
