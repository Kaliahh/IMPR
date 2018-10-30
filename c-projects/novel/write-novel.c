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
# include <math.h>

int main (void) {
   FILE *fp;
   char str[60];
   int i = 0;

   /* opening file for reading */
   fp = fopen("word-list.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }

   while (i <= 3000) {
     if( fgets (str, 60, fp)!=NULL ) {
        /* writing content to stdout */
        printf("%s,\n", str);
     }

     i++;
   }

   return(0);
}
