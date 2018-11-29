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
# define MAX_TIME_LEN 10
# define NUM_OF_RACES 4
# define MAX_RACE_NAME_LEN 25
# define SECONDS_PER_WEEK 86400
# define SECONDS_PER_HOUR 3600
# define SECONDS_PER_MINUTE 60
# define VERY_BIG_NUMBER 10000

/* En struct for et enkelt løb */
typedef struct {
  char race[MAX_RACE_NAME_LEN];
  char time_str[MAX_TIME_LEN];
  int seconds;
  int position;
  int points;

} race_result_sc;

/* En samlet struct for en rytter */
typedef struct {
  char full_name[2 * MAX_NAME_LEN];
  char surname[MAX_NAME_LEN];
  char nation[MAX_ABREV_LEN];
  char team[MAX_ABREV_LEN];
  int time;
  int points_sum;
  double age;
  race_result_sc result[NUM_OF_RACES];

} rider_info_sc;

/* En struct med et navn der kan kopieres */
typedef struct {
  char name[2 * MAX_NAME_LEN];
} name_sc;

/* En struct for antallet af ryttere i hvert løb */
typedef struct {
  int Paris;
  int Amstel;
  int LaFleche;
  int Liege;

} races_sc;

/* Enumeration for DNF og OTL */
enum final_position {OTL = VERY_BIG_NUMBER, DNF};

/* Prototyper */
int printAll(FILE *);
int menu(FILE *);
int findNumResults(FILE *);
rider_info_sc *createArrayRiders(FILE *, const int);
int findRiders(FILE *, const int, name_sc *);
int checkRider(const name_sc *, const char *, const int);
int qCompNames(const void *a, const void *b);
races_sc raceCount(FILE *);
int binaryMatchRiderName(const char *, const name_sc *, const int, const int);
void addRider(rider_info_sc *, FILE *, const int, races_sc, const char *, const char *);
void findSurname(const char *, char *);
int findRaceIndex(const char *);
int calculateTime(const char *);
int calculatePosition(const char *);
int calculatePoints(const int, const races_sc, const char *);


/* Opgave 1 */
void printRiders(const rider_info_sc *, const int, const char *, const double);
/* Opgave 2 */
rider_info_sc *createArrayRidersOfNation(const rider_info_sc *, const int, const char *, int *);
int countRidersOfNation(const rider_info_sc *, const int, const char *);
/* Opgave 3 */
void findTopTen(rider_info_sc *, const int);
int qCompAvg(const void *a, const void *b);
/* Opgave 4 */
void findFastestRider(const rider_info_sc *, const int, char *, char *);
void printFastestRider(const char *, const char *);
/* Opgave 5 */
double calculateAvgAge(const rider_info_sc *, const int);
int positionChecker(const rider_info_sc *, const int);



int main(int argc, char *argv[]) {
  FILE *fP;

  /* Åbner filen */
  fP = fopen("cykelloeb", "r");

  /* Checker om filen blev åbnet */
  if (fP == NULL) {
    perror("Error when opening file");
    return -1;
  }

  /* Hvis programparametre "--print" blev brugt, printes alle resultater med det samme */
  if (argc == 2 && strcmp(argv[1], "--print") == 0) {
    printAll(fP);
  }
  else {
    menu(fP);
  }

  fclose(fP);
  return 0;
}

/* Printer alle resultater */
int printAll(FILE *fP) {
  int num_of_results = 0;
  int rider_amount = 0;
  int nation_rider_amount = 0;
  rider_info_sc *riders;
  rider_info_sc *danish_riders;
  name_sc *name_dump;
  char fast_rider_time[MAX_TIME_LEN];
  char fast_rider[2 * MAX_NAME_LEN];

  /* Finder antallet af resultater */
  num_of_results = findNumResults(fP);

  /* Laver et array af ryttere */
  riders = createArrayRiders(fP, num_of_results);


  /* Allokerer plads til et array der kan smides væk,
   * finder antallet af individuelle ryttere */
  name_dump = malloc(num_of_results * sizeof(name_sc));
  rider_amount = findRiders(fP, num_of_results, name_dump);


  /* Printer alle løbsresultater hvor rytteren er italiensk og over 30 år gammel */
  printf("Italienere over 30: \n");
  printRiders(riders, rider_amount, "ITA", 30);
  printf("\n\n");

  /* Laver et array af danske ryttere, der har en position */
  danish_riders = createArrayRidersOfNation(riders, rider_amount, "DEN", &nation_rider_amount);
  printf("Danskere der har deltaget i et løb: \n");
  printRiders(danish_riders, nation_rider_amount, "DEN", 0);
  printf("\n\n");

  /* Finder og printer de ti spillere der har fået flest point */
  printf("Top ti ryttere: \n");
  findTopTen(riders, rider_amount);
  printf("\n\n");

  /* Finder den rytter der har den mindste køretid i Paris Roubaix og Amstel Gold Race */
  findFastestRider(riders, rider_amount, fast_rider, fast_rider_time);
  printFastestRider(fast_rider, fast_rider_time);
  printf("\n\n");

  /* Finder gennemsnitsalderen af alle de ryttere der har opnået en top-ti plads i et eller flere løb */
  printf("Gennemsnitsalderen for ryttere med en top-ti plads er %0.4lf\n", calculateAvgAge(riders, rider_amount));
  printf("\n\n");

  /* Frigiver hukommelse fra results arrayet, og lukker filpointeren fP */
  free(riders);
  free(name_dump);

  return 0;
}

/* En menu, så brugeren selv kan vælge hvad der skal udregnes og printes */
int menu(FILE *fP) {

  int num_of_results = 0;
  int rider_amount = 0;
  int nation_rider_amount = 0;
  rider_info_sc *riders;
  rider_info_sc *danish_riders;
  name_sc *name_dump;
  char fast_rider_time[MAX_TIME_LEN];
  char fast_rider[2 * MAX_NAME_LEN];
  int choice = 0;

  /* Finder antallet af resultater */
  num_of_results = findNumResults(fP);

  /* Laver et array af ryttere */
  riders = createArrayRiders(fP, num_of_results);


  /* Allokerer plads til et array der kan smides væk,
   * finder antallet af individuelle ryttere */
  name_dump = malloc(num_of_results * sizeof(name_sc));
  rider_amount = findRiders(fP, num_of_results, name_dump);

  printf("\n####################  MENU  ####################\n\n");
  printf("Vælg en opgave: \n");
  printf("1: Opgave 1 - Italienere over 30\n");
  printf("2: Opgave 2 - Danskere der har deltaget i et løb\n");
  printf("3: Opgave 3 - Top ti ryttere\n");
  printf("4: Opgave 4 - Hurtigste rytter\n");
  printf("5: Opgave 5 - Gennemsnitsalderen\n");
  printf("6: Afslut\n\n");
  printf("Indtast et tal mellem 1 og 6: ");
  scanf(" %d", &choice);
  printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n");

  if (choice == 6) {
    printf("Farvel!\n");
    return 0;
  }

  else if (choice == 1) {
    /* Printer alle løbsresultater hvor rytteren er italiensk og over 30 år gammel */
    printf("Italienere over 30: \n");
    printRiders(riders, rider_amount, "ITA", 30);
    printf("\n\n");
  }

  else if (choice == 2) {
    /* Laver et array af danske ryttere, der har en position */
    danish_riders = createArrayRidersOfNation(riders, rider_amount, "DEN", &nation_rider_amount);
    printf("Danskere der har deltaget i et løb: \n");
    printRiders(danish_riders, nation_rider_amount, "DEN", 0);
    printf("\n\n");
  }

  else if (choice == 3) {
    /* Finder og printer de ti spillere der har fået flest point */
    printf("Top ti ryttere: \n");
    findTopTen(riders, rider_amount);
    printf("\n\n");
  }

  else if (choice == 4) {
    /* Finder den rytter der har den mindste køretid i Paris Roubaix og Amstel Gold Race */
    findFastestRider(riders, rider_amount, fast_rider, fast_rider_time);
    printFastestRider(fast_rider, fast_rider_time);
    printf("\n\n");
  }

  else if (choice == 5) {
    /* Finder gennemsnitsalderen af alle de ryttere der har opnået en top-ti plads i et eller flere løb */
    printf("Gennemsnitsalderen for ryttere med en top-ti plads er %0.4lf\n", calculateAvgAge(riders, rider_amount));
    printf("\n\n");
  }

  else {
    printf("Ugyldigt indput\n");
  }

  rewind(fP);
  menu(fP);

  /* Frigiver hukommelse fra results arrayet, og lukker filpointeren fP */
  free(riders);
  free(name_dump);

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

  rewind(fP);

  /* Da den sidste linje tages med 2 gange, trækkes én fra */
  return num_of_results - 1;
}

/* Laver et array af ryttere, med deres resultater i de forskellige løb, og alt anden information */
rider_info_sc *createArrayRiders(FILE *fP, const int num_of_results) {
  rider_info_sc *riders;
  races_sc riders_in_race_count;
  int rider_amount = 0;
  int result_index = 0;
  int check_index = 0;

  name_sc names_list[num_of_results];
  char temp_name[2 * MAX_NAME_LEN];
  char race_name[MAX_NAME_LEN];

  /* Finder antallet af ryttere */
  rider_amount = findRiders(fP, num_of_results, names_list);

  /* Sorterer navnelisten, klar til binær søgning */
  qsort(names_list, rider_amount, sizeof(name_sc), qCompNames);

  riders = malloc(rider_amount * sizeof(rider_info_sc));

  /* Tæller antallet af ryttere i hvert løb */
  riders_in_race_count = raceCount(fP);

  /* Gennemgår antallet af resultater, for at fylde riders arrayet med de nødvendige informationer */
  for (result_index = 0; result_index < num_of_results; result_index++) {
    fscanf(fP, " %s \" %[-a-zA-Z' ] \"", race_name, temp_name);

    /* Finder det sted i rider arrayet hvor denne rytter har plads */
    check_index = binaryMatchRiderName(temp_name, names_list, 0, rider_amount - 1);

    /* Hvis rytteren ikke blev fundet, meldes fejlen */
    if (check_index == -1) {
      printf("Rytter ikke fundet: %s\n", temp_name);
      return riders;
    }

    /* Hvis han er i listen, tilføjes han til rider arrayet */
    else {
      addRider(riders, fP, check_index, riders_in_race_count, race_name, temp_name);
    }
  }

  rewind(fP);
  return riders;
}

/* Finder mængden af individuelle ryttere, og laver en sorteret liste over deres navne */
int findRiders(FILE *fP, const int num_of_results, name_sc *names_list) {
  char temp[200];
  char temp_name[60];

  int rider_amount = 0;
  int result_index = 0;
  int SENTINEL = 0;

  /* Gennemgår alle resultaterne, og finder de enkelte ryttere */
  for (result_index = 0; result_index < num_of_results; result_index++) {
    fgets(temp, 200, fP);
    sscanf(temp + MAX_RACE_NAME_LEN, " \" %[-a-zA-Z' ]", temp_name);

    SENTINEL = checkRider(names_list, temp_name, rider_amount);

    /* Hvis rytteren ikke allerede var blevet talt,
     * tælles han med og tilføjes til listen af navne*/
    if (SENTINEL == 0) {
      strcpy(names_list[rider_amount].name, temp_name);
      rider_amount++;
    }
    else {
      SENTINEL = 0;
    }
  }

  rewind(fP);
  return rider_amount;
}

/* Checker om en rytter allerede er i listen af navne */
int checkRider(const name_sc *names_list, const char *temp_name, const int rider_amount) {
  int name_index = 0;

  /* Hvis rytteren allerede er blevet talt springes han over */
  for (name_index = 0; name_index < rider_amount; name_index++) {
    if (strcmp(temp_name, names_list[name_index].name) == 0) {
      return 1;
    }
  }
  return 0;
}

/* Sammenligningsfunktion til qsort af navne */
int qCompNames(const void *a, const void *b) {
  name_sc *p1 = (name_sc*)a;
  name_sc *p2 = (name_sc*)b;

  return strcmp(p1->name, p2->name);
}

/* Tæller antallet af ryttere i hvert ræs */
races_sc raceCount(FILE *fP) {
  races_sc riders_in_race_count;
  int result_index = 0;
  char temp[200];
  char race_name[MAX_RACE_NAME_LEN];

  /* Nulstiller antallet af resultater i structen */
  riders_in_race_count.Paris = 0;
  riders_in_race_count.Amstel = 0;
  riders_in_race_count.LaFleche = 0;
  riders_in_race_count.Liege = 0;

  while (feof(fP) == 0) {
    fgets(temp, 200, fP);
    sscanf(temp, " %s \"", race_name);

    if (strcmp(race_name, "ParisRoubaix") == 0) {
      riders_in_race_count.Paris++;
    }
    else if (strcmp(race_name, "AmstelGoldRace") == 0) {
      riders_in_race_count.Amstel++;
    }
    else if (strcmp(race_name, "LaFlecheWallonne") == 0) {
      riders_in_race_count.LaFleche++;
    }
    else {
      riders_in_race_count.Liege++;
    }
    result_index++;
  }

  /* Da LiegeBastogneLiege er den sidste i filen, og der bliver talt en ekstra med, trækkes én fra */
  riders_in_race_count.Liege--;

  rewind(fP);
  return riders_in_race_count;
}

/* Finder en rytters indeks ud fra hans navn. Inspireret af DTG lektion 18 */
int binaryMatchRiderName(const char *temp_name, const name_sc *names_list, const int lower, const int upper) {
  int middle = (lower + upper) / 2;

  if (strcmp(temp_name, names_list[middle].name) == 0) {
    return middle;
  }
  /* Hvis navnet der søges efter er mindre end navnet der kigges på,
   * må navnet ligge i den nedre halvdel */
  else if (strcmp(temp_name, names_list[middle].name) < 0 && lower < middle) {
    return binaryMatchRiderName(temp_name, names_list, lower, middle - 1);
  }
  /* Hvis navnet der søges efter er større end navnet der kigges på,
   * må navnet ligger i den øvre halvdel */
  else if (strcmp(temp_name, names_list[middle].name) > 0 && middle < upper) {
    return binaryMatchRiderName(temp_name, names_list, middle + 1, upper);
  }
  /* Hvis rytteren ikke kunne findes, returneres -1 */
  return -1;
}

/* Tilføjer en rytter til rider arryet */
void addRider(rider_info_sc *riders, FILE *fP, const int check_index, races_sc riders_in_race_count, const char *race_name, const char *temp_name) {
  char position[MAX_ABREV_LEN];
  char time[MAX_TIME_LEN];
  int race_index = 0;

  /* Hvis rytteren ikke allerede er på listen, tilføjes hans navn */
  if (strcmp(riders[check_index].full_name, temp_name) != 0) {
    strcpy(riders[check_index].full_name, temp_name);
    findSurname(riders[check_index].full_name, riders[check_index].surname);
  }

  /* Resten af informationerne indsamles */
  fscanf(fP, " | %lf %3s %3s | %[A-Z0-9] %[-0-9:]",
         &riders[check_index].age,
         riders[check_index].team,
         riders[check_index].nation,
         position,
         time);

  /* Finder det sted i rytterens result array, hvor løbsresultaterne skal indsættes */
  race_index = findRaceIndex(race_name);
  /* Indsætter løbsresultater */
  strcpy(riders[check_index].result[race_index].race, race_name);
  strcpy(riders[check_index].result[race_index].time_str, time);
  riders[check_index].result[race_index].seconds  = calculateTime(time);
  riders[check_index].result[race_index].position = calculatePosition(position);
  riders[check_index].result[race_index].points   = calculatePoints(riders[check_index].result[race_index].position, riders_in_race_count, race_name);
  riders[check_index].points_sum += riders[check_index].result[race_index].points;
}

/* Finder en rytters efternavn */
void findSurname(const char *full_name, char *surname) {
  int name_index = MAX_NAME_LEN;
  int SENTINEL = 0;

  while (SENTINEL == 0) {

    if (islower(full_name[name_index]) != 0) {
      name_index += 2; /* Den skal hen over mellemrummet og det lille bogstav */

      strcpy(surname, full_name + name_index);
      SENTINEL = 1;
    }

    else {
      name_index--;
    }
  }
}

/* Finder indekset løbet har i rytternes result array */
int findRaceIndex(const char *race_name) {

  return (strcmp(race_name, "ParisRoubaix") == 0)     ? 0 :
         (strcmp(race_name, "AmstelGoldRace") == 0)   ? 1 :
         (strcmp(race_name, "LaFlecheWallonne") == 0) ? 2 : 3;
}

/* Udregner tiden for et resultat, returnerer antallet af sekunder*/
int calculateTime(const char *time) {
  int hours = 0;
  int minutes = 0;
  int seconds = 0;
  char c = ' ';

  sscanf(time, "%c", &c);

  if (c == '-') {
    return 0;
  }

  sscanf(time, "%d:%d:%d", &hours, &minutes, &seconds);
  return (hours * SECONDS_PER_HOUR + minutes * SECONDS_PER_MINUTE + seconds);
}

/* Udregner positionen for en rytter i et løb */
int calculatePosition(const char *position_str) {
  int position = 0;

  if (strcmp(position_str, "DNF") == 0) {
    return DNF;
  }
  else if (strcmp(position_str, "OTL") == 0) {
    return OTL;
  }
  else {
    sscanf(position_str, "%d", &position);
  }

  return position;
}

/* Udregn point */
int calculatePoints(const int position, const races_sc riders_in_race_count, const char *race_name) {
  int points = 0;
  int riders = 0;

  /* Hvis rytteren gennemfører løbet, men uden for tidsgrænsen, gives 1 point */
  if (position == OTL) {
    points += 1;
  }

  /* Hvis rytteren gennemfører løbet inden for tidsgrænsen, gives 3 point */
  else if (position != DNF) {
    points += 3;

    /* Yderligere gives point for placeringen i løbet,
     * (M - P) / 13, hvor M er antallet af ryttere i løbet (Inklusiv DNF), og P er rytterens placering */
    riders = (strcmp(race_name, "ParisRoubaix") == 0)     ? riders_in_race_count.Paris    :
             (strcmp(race_name, "AmstelGoldRace") == 0)   ? riders_in_race_count.Amstel   :
             (strcmp(race_name, "LaFlecheWallonne") == 0) ? riders_in_race_count.LaFleche : riders_in_race_count.Liege;

    points += (riders - position) / 13;

    /* Der gives yderligere point hvis rytteren er på podiet */
    points += (position == 1) ? 10 :
              (position == 2) ? 5  :
              (position == 3) ? 2 : 0;
  }

  /* Ellers må rytteren ikke have gennemført løbet, og får derfor 0 point */
  else {
    points = 0;
  }

  return points;
}



/* Opgave 1 */
/* Finder og udskriver alle cykelryttere af en bestem nationalitet over en bestemt alder */
void printRiders(const rider_info_sc *riders, const int rider_amount, const char *nation, const double age) {
  int rider_index = 0;
  int race_index = 0;

  for (rider_index = 0; rider_index < rider_amount; rider_index++) {
    if (strcmp(riders[rider_index].nation, nation) == 0 && riders[rider_index].age > age) {
      printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
      printf("Navn: %-30s\n", riders[rider_index].full_name);
      /* Checker om rytteren har deltaget i hver løb, og om hans position var over eller under OTL */
      for (race_index = 0; race_index < NUM_OF_RACES; race_index++) {
        if (isupper(riders[rider_index].result[race_index].race[0]) != 0 && riders[rider_index].result[race_index].position < OTL) {
          printf("%-25s | Points: %2d | Position: %3d | Tid: %s\n",
                 riders[rider_index].result[race_index].race,
                 riders[rider_index].result[race_index].points,
                 riders[rider_index].result[race_index].position,
                 riders[rider_index].result[race_index].time_str);
        }

        else if (isupper(riders[rider_index].result[race_index].race[0]) != 0 && riders[rider_index].result[race_index].position >= OTL) {
          printf("%-25s | Points: %2d | Position: %3s | Tid: %s\n",
                 riders[rider_index].result[race_index].race,
                 riders[rider_index].result[race_index].points,
                 (riders[rider_index].result[race_index].position == OTL) ? "OTL" : "DNF",
                 riders[rider_index].result[race_index].time_str);
        }
      }
    }
  }
}


/* Opgave 2 */
/* Laver et array med alle ryttere fra en bestemt nation, som har gennemført mindst ét løb */
rider_info_sc *createArrayRidersOfNation(const rider_info_sc *riders, const int rider_amount, const char *nation, int *nation_rider_amount) {
  rider_info_sc *nation_riders;
  int rider_index = 0;
  int nation_rider_index = 0;

  /* Tæller antallet af danske ryttere */
  *nation_rider_amount = countRidersOfNation(riders, rider_amount, nation);

  nation_riders = malloc(*nation_rider_amount * sizeof(rider_info_sc));

  /* Kopierer de danskere der har en position som ikke er DNF, over i danske ryttere arrayet */
  for (rider_index = 0; rider_index < rider_amount && nation_rider_index < *nation_rider_amount; rider_index++) {
    if (strcmp(riders[rider_index].nation, nation) == 0 && riders[rider_index].points_sum > 0) {
      nation_riders[nation_rider_index] = riders[rider_index];
      nation_rider_index++;
    }
  }

  return nation_riders;
}

/* Tæller antallet af ryttere af en specifik nationalitet */
int countRidersOfNation(const rider_info_sc *riders, const int rider_amount, const char *nation) {
  int rider_index = 0;
  int danish_rider_amount = 0;

  for (rider_index = 0; rider_index < rider_amount; rider_index++) {
    if (strcmp(riders[rider_index].nation, nation) == 0) {
      danish_rider_amount++;
    }
  }

  return danish_rider_amount;
}


/* Opgave 3 */
/* Udskriver de 10 ryttere som har opnået flest point, sorteret efter antal point.
 * Ved pointlighed, sorteres der efter efternavn */
void findTopTen(rider_info_sc *riders, const int rider_amount) {
  int rider_index = 0;

  qsort(riders, rider_amount, sizeof(rider_info_sc), qCompAvg);

  for (rider_index = 0; rider_index < 10; rider_index++) {
    printf("%2d | %-28s : %d point\n", rider_index + 1, riders[rider_index].full_name, riders[rider_index].points_sum);
  }
}

/* Sammenligningsfunktion til qsort */
int qCompAvg(const void *a, const void *b) {
  rider_info_sc *p1 = (rider_info_sc*)a;
  rider_info_sc *p2 = (rider_info_sc*)b;

  if ((p1->points_sum - p2->points_sum) == 0) {
    return strcmp(p1->surname, p2->surname);
  }

  else {
    return (p2->points_sum - p1->points_sum);
  }
}


/* Opgave 4 */
/* Finder den rytter der har den mindste køretid i Paris Roubaix og Amstel Gold Race */
void findFastestRider(const rider_info_sc *riders, const int rider_amount, char *fast_rider, char *fast_rider_time) {
  int rider_index = 0;
  int temp_time = 0;
  int fast_rider_seconds = 0;

  for (rider_index = 0; rider_index < rider_amount; rider_index++) {
    if (strcmp(riders[rider_index].result[0].race, "ParisRoubaix") == 0 && strcmp(riders[rider_index].result[1].race, "AmstelGoldRace") == 0 &&
        riders[rider_index].result[0].seconds != 0 && riders[rider_index].result[1].seconds != 0) {
      temp_time = riders[rider_index].result[0].seconds + riders[rider_index].result[1].seconds;

      if (temp_time < fast_rider_seconds || fast_rider_seconds == 0) {
        strcpy(fast_rider, riders[rider_index].full_name);
        fast_rider_seconds = temp_time;
      }
    }
  }

  sprintf(fast_rider_time, "%d:%d:%d",
         (fast_rider_seconds % SECONDS_PER_WEEK) / SECONDS_PER_HOUR,
         (fast_rider_seconds % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE,
         (fast_rider_seconds % SECONDS_PER_MINUTE));
}

/* Printer en rytter og en tid */
void printFastestRider(const char *fast_rider, const char *fast_rider_time) {
  printf("Den cykelrytter med den mindste samlede tid\ni Paris Roubaix og Amstel Gold Race,\ner %s med tiden %s\n", fast_rider, fast_rider_time);
}


/* Opgave 5 */
/* Beregn gennemsnitsalderen blandt de ryttere som har opnået en top ti placering i et eller flere løb */
double calculateAvgAge(const rider_info_sc *riders, const int rider_amount) {
  int rider_index = 0;
  int position_check = 0;
  double age_sum = 0.0;
  double num_of_riders = 0.0;

  for (rider_index = 0; rider_index < rider_amount; rider_index++) {
    position_check = positionChecker(riders, rider_index);

    if (position_check == 1) {
      num_of_riders++;
      age_sum += riders[rider_index].age;
      position_check = 0;
    }
  }

  return age_sum / num_of_riders;
}

int positionChecker(const rider_info_sc *riders, const int rider_index) {
  int race_index = 0;

  for (race_index = 0; race_index < NUM_OF_RACES; race_index++) {
    if (riders[rider_index].result[race_index].position > 0 && riders[rider_index].result[race_index].position <= 10) {
      return 1;
    }
  }
  return 0;
}
