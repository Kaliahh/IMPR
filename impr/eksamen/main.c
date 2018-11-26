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
# define SECONDS_PER_HOUR 3600
# define SECONDS_PER_MINUTE 60

/* En struct for en rytters resultat */
typedef struct {
  char race[MAX_NAME_LEN];
  char full_name[2 * MAX_NAME_LEN];
  char surname[MAX_NAME_LEN];
  int age;
  char team[MAX_ABREV_LEN];
  char nation[MAX_ABREV_LEN];
  char position[MAX_ABREV_LEN];
  char time[MAX_TIME];

} rider_result_sc;

/* En struct for en enkelt rytters point og efternavn */
typedef struct {
  char surname[MAX_NAME_LEN];
  int points;

} rider_info_sc;

rider_result_sc *createArrayResults(const int, FILE *);
rider_info_sc *createArraySurnamePoints(const int, const rider_result_sc *);
void findSurname(rider_result_sc *, const int);
int findNumResults(FILE *);
int calculatePoints(const char *, const int, rider_info_sc *);
int calculateTime(const char *);
int findAmountRiders(const int, const rider_result_sc *);

int main(void) {

  int num_of_results = 0;
  rider_result_sc *results;
  rider_info_sc *riders;
  FILE *fP;

  /* Åbner filen */
  fP = fopen("cykelloeb", "r");

  /* Checker om filen blev åbnet */
  if (fP == NULL) {
    perror("Error when opening file");
     return -1;
  }

  /* Finder antallet af resultater */
  num_of_results = findNumResults(fP);

  /* Tager resultaterne fra "cykelloeb", og lægger over i results arrayet */
  results = createArrayResults(num_of_results, fP);

  riders = createArraySurnamePoints(num_of_results, results);

  /* Frigiver hukommelse fra results arrayet, og lukker filpointeren fP */
  free(results);
  fclose(fP);

  return 0;
}

/* Finder antallet af resultater */
int findNumResults(FILE *fP) {
  char dump[200];
  int num_of_results = 0;

  while (feof(fP) == 0) {
    fgets(dump, 200, fP);
    num_of_results++;
  }

  /* Sætter filpointeren tilbage til starten af filen */
  rewind(fP);

  return num_of_results - 1;
}

/* Scanner resultaterne fra "cykelloeb" ind i et array */
rider_result_sc *createArrayResults(const int num_of_results, FILE *fP) {
  int result_index = 0;

  rider_result_sc *results;

  results = malloc(num_of_results * sizeof(rider_result_sc));

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

  /* Sætter filpointeren tilbage til starten af filen */
  rewind(fP);

  return results;
}


/* Finder rytterens efternavn */
void findSurname(rider_result_sc *results, int result_index) {
  int name_index = MAX_NAME_LEN;
  int SENTINEL = 0;

  while (SENTINEL == 0) {
    if (islower(results[result_index].full_name[name_index]) != 0) {
      name_index += 2; /* Den skal hen over mellemrummet og det lille bogstav */

      /* Kopierer efternavnet fra det fulde navn */
      strcpy(results[result_index].surname, results[result_index].full_name + name_index);
      SENTINEL = 1;
    }

    else {
      name_index--;
    }
  }
}

/* KUNNE BARE LÆGGES OVER I DEN STORE STRUCT */

/* Returnerer et array med rytterens efternavn navn og samlede antal point de har */
rider_info_sc *createArraySurnamePoints(const int num_of_results, const rider_result_sc *results) {
  rider_info_sc *riders;
  int individual_rider_amount = 0;
  int rider_index = 0;

  individual_rider_amount = findAmountRiders(num_of_results, results);

  printf("%d\n", individual_rider_amount);

  riders = malloc(individual_rider_amount * sizeof(rider_info_sc));

  for (rider_index = 0; rider_index < individual_rider_amount; rider_index++) {
    if (riders[rider_index].points == 0) {
      calculatePoints(riders[rider_index].surname, individual_rider_amount, riders);
    }
  }

  return riders;
}

/* Finder antallet af individuelle ryttere, returnerer antallet */
int findAmountRiders(const int num_of_results, const rider_result_sc *results) {
  int result_index = 0;
  int check_index = 0;
  int individual_rider_amount = 0;
  int SENTINEL = 0;

  /* Gennemgår result arrayet, og tjekker alle resultater op til resultat indekset.
   * Hvis den finder en rytter der allerede er talt, springes denne over */
  for (result_index = 0; result_index < num_of_results; result_index++) {
    for (check_index = 0; check_index < result_index; check_index++) {
      if (strcmp(results[result_index].surname, results[check_index].surname) == 0) {
        SENTINEL++;
        printf("%3d | %s\n", result_index + 1, results[result_index].surname);
      }
    }
    /* Hvis der ikke blev fundet nogen gengangere, er denne rytter ikke blevet talt */
    if (SENTINEL == 0) {
      individual_rider_amount++;
    }
    /* Ellers nulstilles flaget, klar til næste resultat */
    else {
      SENTINEL = 0;
    }
  }

  return individual_rider_amount;
}

/* Udregn point */
int calculatePoints(const char *rider_surname, const int individual_rider_amount, rider_info_sc *riders) {
  int points = 0;
  int rider_index = 0;

  for (rider_index = 0; rider_index < )


  return 0;
}

/* Udregn tiden for et resultat, returnerer antallet af sekunder*/
int calculateTime(const char *result) {
  int hours = 0;
  int minutes = 0;
  int seconds = 0;

  sscanf(result, "%d:%d:%d", &hours, &minutes, &seconds);
  return (hours * SECONDS_PER_HOUR + minutes * SECONDS_PER_MINUTE + seconds);
}

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
