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
  char team[MAX_ABREV_LEN];
  char nation[MAX_ABREV_LEN];
  char position[MAX_ABREV_LEN];
  char time[MAX_TIME];
  int seconds;
  int age;
  double points;

} rider_result_sc;

/* En struct for hvert løb */
typedef struct {
  int Paris;
  int Paris_time;
  int Amstel;
  int Amstel_time;
  int LaFleche;
  int LaFleche_time;
  int Liege;
  int Liege_time;

} races_sc;

/* En struct for en enkelt rytters efternavn, samlede antal point,
 * nationalitet, alder og de løb personen har deltaget i */
typedef struct {
  char full_name[MAX_NAME_LEN];
  char surname[MAX_NAME_LEN];
  char nation[MAX_ABREV_LEN];
  int points_sum;
  int age;
  races_sc races;

} rider_info_sc;


/* Prototyper */
rider_result_sc *createArrayResults(const int, FILE *);
races_sc raceCount(const rider_result_sc *, const int);
rider_info_sc *createArrayRiders(const int, const rider_result_sc *);
void findSurname(rider_result_sc *, const int);
int findNumResults(FILE *);
double calculatePoints(const races_sc, rider_result_sc);
int calculateTime(const char *);
int findAmountRiders(const int, const rider_result_sc *);
void printItalians(rider_result_sc *, const int);
void copyInfo(rider_info_sc *, const rider_result_sc);
int findRider(const rider_info_sc *, const int, const rider_result_sc);

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

  /* Tager resultaterne fra results, og laver et array af individuelle cykelryttere */
  riders = createArrayRiders(num_of_results, results);

  /* Printer alle løbsresultater hvor rytteren er italiensk og over 30 år gammel */

  /* printItalians(results, num_of_results); */
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

  /* Da den sidste linje tages med 2 gange, trækkes én fra */
  return num_of_results - 1;
}

/* Scanner resultaterne fra "cykelloeb" ind i et array */
rider_result_sc *createArrayResults(const int num_of_results, FILE *fP) {
  int result_index = 0;
  races_sc riders_in_race_count;

  rider_result_sc *results;

  results = malloc(num_of_results * sizeof(rider_result_sc));

  /* Så længe filpointeren ikke er kommet til slutningen af filen,
   * scannes resultaterne over i de forskellige dele af structen */
  for (result_index = 0; result_index < num_of_results; result_index++) {
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

    results[result_index].seconds = calculateTime(results[result_index].time);
  }

  /* Finder antallet af ryttere i hvert ræs */
  riders_in_race_count = raceCount(results, num_of_results);

  /* Finder antallet af point rytteren i det nuværende resultat har opnået */
  for (result_index = 0; result_index < num_of_results; result_index++) {
    results[result_index].points = calculatePoints(riders_in_race_count, results[result_index]);
  }

  /* Sætter filpointeren tilbage til starten af filen */
  rewind(fP);

  return results;
}

/* Udregn point */
double calculatePoints(const races_sc riders_in_race_count, rider_result_sc result) {
  double points = 0;
  double position = 0;
  int riders = 0;

  /* Hvis rytteren gennemfører løbet, men uden for tidsgrænsen, gives 1 point */
  if (strcmp("OTL", result.position) == 0) {
    points += 1;
  }

  /* Hvis rytteren gennemfører inden for tidsgrænsen, gives 3 point */
  else if (strcmp("DNF", result.position) != 0) {
    sscanf(result.position, "%lf", &position);
    points += 3;

    /* Yderligere gives point for placeringen i løbet,
     * (M - P) / 13, hvor M er antallet af ryttere i løbet (Inklusiv DNF), og P er rytterens placering */
    riders = (strcmp(result.race, "ParisRoubaix") == 0)     ? riders_in_race_count.Paris    :
             (strcmp(result.race, "AmstelGoldRace") == 0)   ? riders_in_race_count.Amstel   :
             (strcmp(result.race, "LaFlecheWallonne") == 0) ? riders_in_race_count.LaFleche : riders_in_race_count.Liege;

    points += (riders - position) / 13;

    /* Der gives yderligere point hvis rytteren er på podiet */
    points += (position == 1) ? 10 :
              (position == 2) ? 5  :
              (position == 3) ? 2 : 0;
  }

  else {
    points = 0;
  }

  return points;
}

/* Tæller antallet af ryttere i hvert ræs */
races_sc raceCount(const rider_result_sc *results, const int num_of_results) {
  races_sc riders_in_race_count;
  int result_index = 0;

  /* Nulstiller antallet af resultater */
  riders_in_race_count.Paris = 0;
  riders_in_race_count.Amstel = 0;
  riders_in_race_count.LaFleche = 0;
  riders_in_race_count.Liege = 0;

  for (result_index = 0; result_index < num_of_results; result_index++) {
    if (strcmp(results[result_index].race, "ParisRoubaix") == 0) {
      riders_in_race_count.Paris++;
    }
    else if (strcmp(results[result_index].race, "AmstelGoldRace") == 0) {
      riders_in_race_count.Amstel++;
    }
    else if (strcmp(results[result_index].race, "LaFlecheWallonne") == 0) {
      riders_in_race_count.LaFleche++;
    }
    else {
      riders_in_race_count.Liege++;
    }
  }

  /*
  printf("Paris:    %d\n", riders_in_race_count.Paris);
  printf("Amstel:   %d\n", riders_in_race_count.Amstel);
  printf("LaFleche: %d\n", riders_in_race_count.LaFleche);
  printf("Liege:    %d\n", riders_in_race_count.Liege);

  printf("Sum: %d\n", riders_in_race_count.Paris + riders_in_race_count.Amstel + riders_in_race_count.LaFleche + riders_in_race_count.Liege); */

  return riders_in_race_count;
}

/* Udregner tiden for et resultat, returnerer antallet af sekunder*/
int calculateTime(const char *result) {
  int hours = 0;
  int minutes = 0;
  int seconds = 0;
  char c = ' ';

  sscanf(result, "%c", &c);

  if (c == '-') {
    return 0;
  }

  sscanf(result, "%d:%d:%d", &hours, &minutes, &seconds);
  return (hours * SECONDS_PER_HOUR + minutes * SECONDS_PER_MINUTE + seconds);
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

/* Returnerer et array af structs med hver enkelt rytters samlede antal point,
 * efternavn, de ræs han har været i, nationalitet og alder */
rider_info_sc *createArrayRiders(const int num_of_results, const rider_result_sc *results) {
  rider_info_sc *riders;
  int individual_rider_amount = 0;
  int rider_index = 0;
  int result_index = 0;
  int check_index = 0;

  /* Finder antallet af individuelle ryttere */
  individual_rider_amount = findAmountRiders(num_of_results, results);

  /* Laver et array af individuelle ryttere, på den rigtige størrelse */
  riders = malloc(individual_rider_amount * sizeof(rider_info_sc));

  /* Kopierer informationer fra results arrayet over i rider arrayet,
   * udregner rytterens samlede antal point, og de løb han har deltaget i */
  for (result_index = 0; result_index < num_of_results; result_index++) {

    /* Hvis rytteren allerede er blevet tilføjet, findes hans indeks */
    check_index = findRider(riders, rider_index, results[result_index]);

    /* Hvis rytteren ikke blev fundet, tilføjes han til arrayet */
    if (check_index == -1) {
      copyInfo(&riders[rider_index], results[result_index]);
      rider_index++;
    }

    /* Hvis han allerede findes, opdateres hans point og de løb han har deltaget i */
    else if (check_index != -1) {
      riders[check_index].points_sum += results[result_index].points;
      /* Dette burde være en funktion */
      /* Dette virker ikke */
      if (strcmp(results[result_index].race, "ParisRoubaix") == 0) {
        riders[check_index].races.Paris = 1;
        riders[check_index].races.Paris_time = results[result_index].seconds
      }
      else if (strcmp(results[result_index].race, "AmstelGoldRace") == 0) {
        riders[check_index].races.Amstel = 1;
        riders[check_index].races.Amstel_time = results[result_index].seconds
      }
      else if (strcmp(results[result_index].race, "LaFlecheWallonne") == 0) {
        riders[check_index].races.LaFleche = 1;
        riders[check_index].races.LaFleche_time = results[result_index].seconds
      }
      else {
        riders[check_index].races.Liege = 1;
        riders[check_index].races.Liege = results[result_index].seconds
      }
    }
  }

  /*
  for (rider_index = 0; rider_index < individual_rider_amount; rider_index++) {
    printf("%3d | %-25s - %d\n", rider_index, riders[rider_index].surname, riders[rider_index].races.Amstel);
  }
  */

  return riders;
}

/* Returnerer -1 hvis den ikke kunne finde rytteren */
/* Returnerer indekset hvis den finder rytteren */
int findRider(const rider_info_sc *riders, const int rider_index, const rider_result_sc result) {
  int check_index = 0;

  for (check_index = 0; check_index < rider_index; check_index++) {
    if (strcmp(result.full_name, riders[check_index].full_name) == 0) {
      return check_index;
    }
  }
  return -1;
}

/* Kopierer informationer fra et resultat til en rytter */
void copyInfo(rider_info_sc *rider, const rider_result_sc result) {
  strcpy(rider->full_name, result.full_name);
  strcpy(rider->surname, result.surname);
  strcpy(rider->nation, result.nation);
  rider->age = result.age;
  rider->points_sum = result.points;

  if (strcmp(result.race, "ParisRoubaix")) {
    rider->races.Paris = 1;
  }
  else if (strcmp(result.race, "AmstelGoldRace")) {
    rider->races.Amstel = 1;
  }
  else if (strcmp(result.race, "LaFlecheWallonne")) {
    rider->races.LaFleche = 1;
  }
  else {
    rider->races.Liege = 1;
  }

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
      if (strcmp(results[result_index].full_name, results[check_index].full_name) == 0) {
        SENTINEL = 1;
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


/* Opgave 1 */
/* Find og udskriv alle italienske cykelryttere over 30 år */
void printItalians(rider_result_sc *results, const int num_of_results) {
  int result_index = 0;

  for (result_index = 0; result_index < num_of_results; result_index++) {
    if (strcmp("ITA", results[result_index].nation) == 0 && results[result_index].age > 30) {
      printf("%-20s %-22s | %2d %3s %3s | %4s %8s\n",
             results[result_index].race,
             results[result_index].full_name,
             results[result_index].age,
             results[result_index].team,
             results[result_index].nation,
             results[result_index].position,
             results[result_index].time);
    }
  }
}

/* Opgave 2 */
/* Retunerer et array af alle danske cyklister */
/* Kald derefter funktionen og print hvor mange løb de har de har gennemført, print hver cyklist kun én gang */



/* Udskriv de 10 ryttere som har opnået flest point, sorteret efter antal point.
 * Ved pointlighed, sorteres der efter efternavn */

 /* Se på Paris Roubaix og Amstel Gold Race.
  * Find den rytter som har gennemført begge løb, og som har den mindste samlede køretid i begge løb
  * Skal have rytteren og den samlede køretid som outputparametre.
  * Kald funktionen og udskriv rytterens navn og den samlede køretid */

/* Beregn gennemsnitsalderen blandt de ryttere som har opnået en top ti placering i et eller flere løb */
