// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    HiddenWord = TEXT("abduct"); // Sets HiddenWord
    Lives = HiddenWord.Len(); // Sets lives
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the 6-letter word.")); // TODO: Magic number remove!!!!!
    PrintLine(TEXT("Press enter to continue..."));
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
        PrintLine(TEXT("You lost!"));   
    }
    // Check if isogram
    // Check if right number of characters
    // Remove Life

    // Check if lives > 0
    // Yes -> guess again
    // No -> you lose; Hit enter to play again
}