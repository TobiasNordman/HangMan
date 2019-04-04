/* Hangman.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

      srand(time(NULL));

      char guessWords[][16] = {
        "pumpkin",
        "dagger",
        "yes"
      };


      int randomIndex = rand() % 3 ; //ordets plats

      int numLives = 8;
      int numCorrect = 0; //antal rätt gissningar
      int oldCorrect = 0;

      int lenghtOfWord = strlen(guessWords[randomIndex]);
      int letterGuessedPos[8]={0,0,0,0,0,0,0,0};

      int quit = 0;

      int loopIndex = 0;

      char guess[16];
      char letterGuessed;

      printf("Word: %s randomIndex: %d lenghtOfWord: %d \n",
      guessWords[randomIndex],
      randomIndex,
      lenghtOfWord);

      while(numCorrect<lenghtOfWord){

        printf("\n\nWord:");
        for(loopIndex = 0; loopIndex < lenghtOfWord; loopIndex++){

          if(letterGuessedPos[loopIndex] == 1){
             printf("%c",guessWords[randomIndex][loopIndex]);
        }
          else{
            printf("-");
          }

        }

          printf("\n");

        printf("Number correct so far: %d\n",numCorrect );
        sleep(1);

        printf("Guess a letter: ");
        fgets(guess, 16, stdin);
        sleep(1);

        if(strncmp(guess, "quit", 4) == 0){
          quit = 1;
          break;
        }

        letterGuessed = guess[0];

        oldCorrect = numCorrect;
        for(loopIndex = 0; loopIndex < lenghtOfWord; loopIndex++){

          if(letterGuessedPos[loopIndex] == 1){
            continue;
        }

          if(letterGuessed == guessWords[randomIndex][loopIndex]){
            letterGuessedPos[loopIndex] = 1; numCorrect++;
          }
        }

          if(oldCorrect == numCorrect){
            numLives--;



            printf("Wrong.\nYou have %d lives left\n",numLives);
            if(numLives == 0){
              break;
            }
          }
            else{
            printf("Correct.\n");
          }

      }

      if( quit == 1 ){
        printf("\nYou quit.\n");
      }
        else if(numLives == 0){
          printf("\nYou lost, the word was: %s\n", guessWords[randomIndex]);
        }
        else{printf("\n You won!\n");
      }

  return 0;
}
