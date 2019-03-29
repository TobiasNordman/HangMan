/* Hangman.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {

      srand(time(NULL));

      char guessWords[][16] = {
        "pumpkin",
        "dagger",
        "yes"
      };

      int randomIndex = rand() % 3 ; //byt 0 mot antal ord

      int numLives = 8;
      int numCorrect = 0; //antal rätt gissningar
      int oldCorrect = 0;

      int lenghtOfWord = strlen(guessWords[randomIndex]);
      int letterGuessedPos [8] = { 0,0,0,0,0,0,0,0 };

      int quit = 0;

      int loopIndex = 0;

      char guess[16];
      char letterGuessed;

      printf("guessWords: %s randomIndex: %d lenghtOfWord: %d \n",
      guessWords[randomIndex],
      randomIndex,
      lenghtOfWord);

      while ( numCorrect < lenghtOfWord) {
        printf("Number correct so far: %d\n",numCorrect );
        printf("Guess a letter: ");
        fgets(guess, 16, stdin);

        if( strncmp(guess, "quit", 4) == 0) {
          quit = 1;
          break;
        }

        letterGuessed = guess[0];

        printf("letterGuessed: %c\n", letterGuessed);
        for(loopIndex = 0; loopIndex < lenghtOfWord; loopIndex++){

          if(letterGuessedPos[loopIndex] == 1) {
            continue;
          }

          if(letterGuessed == guessWords[randomIndex][loopIndex]) {
            letterGuessedPos[loopIndex] = 1; numCorrect++;
          }
        }

      }

      if( quit == 1 ){
        printf("\nAre you sure you want to quit?\nYes/No: ");
      }

  return 0;
}
