/* Navn: Ane Søgaard Jørgensen
 * Dato: 12/10-2018
 * Beskrivelse: En fil til at lave nye filer
 */

int mkdir(char*);

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int main(void) {

  char input[50], c_file[50], h_file[50], h_start[50],
  path[50] = "/",
  c_end[5] = ".c",
  h_end[5] = ".h";

  /* Prompter brugeren for navn på et projekt */
  printf("Dette program laver en c-fil og en h-fil\n\n");
  printf("Input navnet på dit projekt: ");
  scanf("%s", input);

  /* Laver en mappe */
  mkdir(input);

  /* Navngiver de to filer, med stien i navnet */
  sprintf(c_file, "%s%s%s%s", input, path, input, c_end);
  sprintf(h_file, "%s%s%s%s", input, path, input, h_end);
  sprintf(h_start, "%s%s", input, h_end);

  /* Initierer pointeren */
  FILE * fP;

  /* Laver .c-filen */
  fP = fopen(c_file, "w");

  /* Skriver include statement for .h filen */
  fprintf(fP, "# include \"%s\"", h_start);

  /* Laver .h-filen */
  fP = fopen(h_file, "w");

  /* Lukker pointeren */
  fclose(fP);

  return 0;
}
