/* Ane Søgaard Jørgensen
 * asja18@student.aau.dk
 * Gruppe A411
 * Software
 * Afleveres 03/12-2018 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <ctype.h>

# define MAX_NAME_LEN 30
# define MAX_ABREV_LEN 4
# define MAX_TIME 10
# define MAX_NUM_RESULTS 800

/* En struct for en rytters resultat */
typedef struct {
  char race[MAX_NAME_LEN];
  char full_name[2 * MAX_NAME_LEN];
  char sur_name[MAX_NAME_LEN];
  int age;
  char team[MAX_ABREV_LEN];
  char nation[MAX_ABREV_LEN];
  char position[MAX_ABREV_LEN];
  char time[MAX_TIME];

} rider_result_sc;

/* En struct for en enkelt rytters point og efternavn */
typedef struct {
  char sur_name[MAX_NAME_LEN];
  int points;

} rider_points_sc;

int createArrayOfResults(rider_result_sc *);
void findSurname(rider_result_sc *, int);
int findNumOfResults(FILE *);

int main(void) {

  int fileOpened = 0;

  rider_result_sc *results;

  /* Tager resultaterne fra "cykelloeb", og lægger over i results arrayet.
   * fileOpened bliver tildelt -1 hvis filen ikke kunne åbnes */
  fileOpened = createArrayOfResults(results);

  /* Hvis filen med cykelløb ikke kunne åbnes, afsluttes programmet */
  if (fileOpened == -1) {
    perror("Error opening file");
    return -1;
  }

  free(results);

  return 0;
}

int findNumOfResults(FILE *fP) {
  char dump[200];
  int num_of_results = 0;

  while (feof(fP) == 0) {
    fgets(dump, 200, fP);
    num_of_results++;
  }

  return num_of_results - 1;
}

/* Scanner resultaterne fra "cykelloeb" ind i et array */
int createArrayOfResults (rider_result_sc *results) {
  int result_index = 0;
  int num_of_results = 0;
  FILE *fP;

  fP = fopen("cykelloeb", "r");

  /* Checker om filen blev åbnet */
  if (fP == NULL) {
     return -1;
  }

  num_of_results = findNumOfResults(fP);

  results = malloc(num_of_results * sizeof(rider_result_sc));

  /* Sætter filpointeren tilbage til starten af filen */
  rewind(fP);

  /* Så længe filpointeren ikke er kommet til slutningen af filen,
   * scannes resultaterne over i de forskellige dele af structen */
  while (result_index < num_of_results) {
    fscanf(fP, " %[a-zA-Z] \" %[-a-zA-Z' ] \" | %d %[A-Z] %[A-Z] | %[A-Z0-9] %[-0-9:] ",
           results[result_index].race,
           results[result_index].full_name,
           &results[result_index].age,
           results[result_index].team,
           results[result_index].nation,
           results[result_index].position,
           results[result_index].time);

    /* Finder efternavnet på spilleren i resultatet */
    findSurname(results, result_index);

    result_index++;
  }

  fclose(fP);
  return 0;
}

/* Finder rytterens efternavn */
void findSurname(rider_result_sc *results, int result_index) {
  int name_index = MAX_NAME_LEN;
  int SENTINEL = 0;

  while (SENTINEL == 0) {
    if (islower(results[result_index].full_name[name_index]) != 0) {
      name_index += 2; /* Den skal hen over mellemrummet og det lille bogstav */

      /* Kopierer efternavnet fra det fulde navn */
      strcpy(results[result_index].sur_name, results[result_index].full_name + name_index);
      SENTINEL = 1;
    }

    else {
      name_index--;
    }
  }
}

/* Udregn point */
/*
int calculatePoints(rider_result_sc *results, rider_points_sc *points) {
  int result_index = 0;

  for (result_index = 0; )
}
*/

/* Udregn tid */
/*
int calculateTime(rider_points_sc result) {

}
*/


/* Find og udskriv alle italienske cykelryttere over 30 år */

/* Retuner et array af alle danske cyklister */
/* Kald derefter funktionen og print hvor mange løb de har de har gennemført, print hver cyklist kun én gang */


/* Udskriv de 10 ryttere som har opnået flest point, sorteret efter antal point.
 * Ved pointlighed, sorteres der efter efternavn */

 /* Se på Paris Roubaix og Amstel Gold Race.
  * Find den rytter som har gennemført begge løb, og som har den mindste samlede køretid i begge løb
  * Skal have rytteren og den samlede køretid som outputparametre.
  * Kald funktionen og udskriv rytterens navn og den samlede køretid */

/* Beregn gennemsnitsalderen blandt de ryttere som har opnået en top ti placering i et eller flere løb */
