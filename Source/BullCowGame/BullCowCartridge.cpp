// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug Line
    
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i-letter word."), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checks guess
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You win!"));
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The HiddenWord is %i letters, try again!"), HiddenWord.Len());
        }
        PrintLine(TEXT("You lost!"));   
    }
    // Check if isogram
    // Check if right number of characters
    // Remove Life

    // Check if lives > 0
    // Yes -> guess again
    // No -> you lose; Hit enter to play again
}
void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("abduct");
    Lives = HiddenWord.Len();
}
