/* Navn: Ane Søgaard Jørgensen
 * Dato: 15/10-2018
 * Beskrivelse: https://bit.ly/2CgJEhf
 */

# include <stdio.h>

/* Prototype */
void change(int, int *, int *, int *, int *);

int main(void) {

  int input = 10;
  int hundred, halvtreds, tyve, ti;

  /* Loopet bliver ved til inputtet ikke er dividerbart med 10 */
  while (input % 10 == 0) {

    /* Prompter brugeren for et beloeb */
    printf("Indtast et beloeb, der er dividerbart med 10: ");
    scanf("%d", &input);

    /* Checker om inputtet er dividerbart med 10 */
    if (input % 10 != 0) {
      printf("Beloebet skal være dividerbart med 10\n");
      return 0;
    }

    /* Finder antallet af sedler */
    change(input, &hundred, &halvtreds, &tyve, &ti);

    /* Printer sedlerne */
    printf("Hundred: %d, halvtreds: %d, tyve: %d, ti: %d\n\n", hundred, halvtreds, tyve, ti);
  }

  return 0;
}

/* Finder antallet af sedler, og sender resultatet tilbage til main funktionen */
void change(int input, int *hundred, int *halvtreds, int *tyve, int *ti  ) {

  int rem;

  *hundred = input / 100;
  rem = input % 100;

  *halvtreds = rem / 50;
  rem = rem % 50;

  *tyve = rem / 20;
  rem = rem % 20;

  *ti = rem / 10;

}
