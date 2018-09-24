# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int write(void) {

  char stat[50];

  FILE * fP;

  printf("Input your statement: ");
  scanf("%s", stat);

  fP = fopen("file.txt", "w");
  fprintf(fP, "%s", stat);

  fclose(fP);

}

int read(void) {

  FILE * fP;



  fclose(fP);

}

int append(void) {

}

int chooser(void) {

  char choice[1];

  printf("Do you want to read, write, append or quit? (r / w / a / q): ");
  scanf("%s", choice);

  if (strcmp(choice, "r") == 0) {
    read();
    printf("\n");
    chooser();
  }
  else if (strcmp(choice, "w") == 0) {
    write();
    printf("\n");
    chooser();
  }
  else if (strcmp(choice, "a") == 0) {
    append();
    printf("\n");
    chooser();
  }
  else if (strcmp(choice, "q") == 0)
    return 0;
  else {
    printf("Invalid input.\n");
    printf("\n");
    chooser;
  }

  return 0;
}





int main(void) {

  chooser();

  return 0;
  
}
