/*
 * Bank management system
 * Made by: Ane Søgaard Jørgensen
 * Started on: 23/09-2018
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "user_info.h"

int new_account(void) {

  char user_name[25];

  FILE * fPointer;
  printf("\nInput a username: ");
  scanf("%s", user_name);

  fPointer = fopen("users.txt", "a");
  fprintf(fPointer, "{%s}", user_name);

  fclose(fPointer);
  
  printf("Your username is %s\n", user_name);
  
}

int details(void) {

}

int transaction(void) {

}


int main_menu(void) {

  char choice[3];

  printf("\nVIRTUAL BANK MANAGEMENT SYSTEM\n\n########## MAIN MENU ##########\n\n");
  
  printf("1. Create new account\n");
  printf("2. View details of an existing account\n");
  printf("3. Transactions\n");

  
  printf("\nInput a number to proceed, or q to quit: ");
  scanf("%s", choice);

  if (strcmp(choice, "1") == 0)
    new_account();
  else if (strcmp(choice, "2") == 0)
    details();
  else if (strcmp(choice, "3") == 0)
    transaction();
  else if (strcmp(choice, "q") == 0 || strcmp(choice, "Q") == 0)
    return 0;
  else {
    printf("Invalid entry");
    sleep(1);
    main_menu();
  }
    
  return 0;
}





int main(void) {


  
  main_menu();

  
  
  return 0;
}
