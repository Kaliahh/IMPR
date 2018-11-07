/* Name: Ane Søgaard Jørgensen
 * Date: 01/11-2018
 * Description: A C-program that writes a novel,
                based on the 3000 most used words in English,
                found on https://bit.ly/2Fg3K9r
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define WORD_COUNT 3000
# define WORD_LEN 30

void arrayComma(FILE *, char (*)[WORD_LEN]);
void arrayFiller(char (*)[WORD_LEN]);

int main (void) {
   FILE * fP;
   char words[WORD_COUNT][WORD_LEN];

   arrayFiller(words);

   arrayComma(fP, words);

   return 0;
}

void arrayComma(FILE *fP, char (*words)[WORD_LEN]) {
  char str[60];
  int i = 0;

  while (i < WORD_COUNT) {
    fP = fopen("word-list.txt", "r");
    //fgets(words[i], 60, fP);

    fscanf(fP, "%s ", str);
    printf("str: %s\n", str);
    //printf("%s\n", words[i]);

    i++;
  }
}

void arrayFiller(char (*words)[WORD_LEN]) {
  for (int i = 0; i < WORD_COUNT; i++) {
    for (int j = 0; j < WORD_LEN; j++) {
      words[i][j] = 'C';
    }
  }
}

/*
int main (void) {
   FILE *fp;
   char str[60];
   int i = 0;

   fp = fopen("word-list.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }

   while (i <= 3000) {
     if( fgets (str, 60, fp)!=NULL ) {
        fprintf(fP, "%s,\n", str);
     }

     i++;
   }

   return(0);
}
*/
