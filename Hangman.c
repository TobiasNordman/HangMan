/* Hangman.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  srand(time(NULL));

  char guessWords[19][19];

  FILE* c;
  c = fopen("guessWord.txt","r");

  int i = 0;

  while(1)
  {
    char r = (char)fgetc(c);
    int k = 0;

    while(r != ',' && !feof(c))
    {
      guessWords[i][k++] = r;
      r = (char)fgetc(c);
    }
    guessWords[i][k]=0;

    if(feof(c))
    {
      break;
    }
      i++;
  }

      int randomIndex = rand() % 15 ;

      int numLives = 8;
      int numCorrect = 0;
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
            printf("_");
          }

        }

          printf("\n");

        printf("Number correct so far: %d\n",numCorrect );

        printf("Guess a letter: ");
        fgets(guess, 16, stdin);

        if(strncmp(guess, "quit", 4) == 0){
          quit = 1;
          break;
        }

        letterGuessed = guess[0];

        oldCorrect = numCorrect;

        printf("letterGuessed: %c\n", letterGuessed);
        for(loopIndex = 0; loopIndex < lenghtOfWord; loopIndex++)
        {
          if(letterGuessedPos[loopIndex] == 1)
          {
            continue;
          }

          if(letterGuessed == guessWords[randomIndex][loopIndex])
          {
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
