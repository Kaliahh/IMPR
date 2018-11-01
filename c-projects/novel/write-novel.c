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

void arrayComma(FILE *);

int main (void) {
   FILE * fP;
   char str[60];
   int i = 0;

   arrayComma(fP);

   return 0;
}

void arrayComma(FILE *fP) {
  char str[60];
  int i = 0;

  while (i <= 3000) {
    fP = fopen("word-list.txt", "r");

    fgets(str, 60, fP);
    printf("str: %s, ", str);

    fP = fopen("word-list-comma.txt", "w");

    fprintf(fP, "%s, ", str);

    i++;
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
