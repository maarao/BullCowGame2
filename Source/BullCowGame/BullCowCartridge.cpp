// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    // if game is over -> ClearScreen() + SetupGame();
    // else check player guess

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        // Checks guess
        ProcessGuess(Input);
        
        // Check if isogram
        // Check if right number of characters
        // Remove Life

        // Check if lives > 0
        // Yes -> guess again
        // No -> you lose; Hit enter to play again
    }
    
    
}
void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("abduct");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug Line
    
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i-letter word."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and\npress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You win!"));
        EndGame();
    }
    else
    {
        --Lives;
        if (Lives > 0)
        {
            if (Guess.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The HiddenWord is %i letters, try again!\nYou have %i live(s) left"), HiddenWord.Len(), Lives);
            }
        }
        else
        {
            EndGame();
        }
    }
}
