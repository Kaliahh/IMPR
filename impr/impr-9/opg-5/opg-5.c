/* Navn: Ane Søgaard Jørgensen
 * Dato: 26/10-2018
 * Beskrivelse: Opgave 5 i bogen (Problem solving....), side 469
 */

# include <stdio.h>
# include <stdlib.h>

int checkBar(int *, int);
int sumOfOdd(int *, int);
int sumOfEven(int *, int);

int main(void) {

  int a[] = {0, 7, 9, 4, 0, 0, 8, 0, 4, 5, 0, 1};
  int b[] = {0, 2, 4, 0, 0, 0, 1, 6, 2, 8, 6, 0};
  int c[] = {0, 1, 1, 1, 1, 0, 8, 5, 6, 8, 0, 7};
  int d[] = {0, 5, 1, 0, 0, 0, 1, 3, 8, 1, 0, 1};

  checkBar(a, sizeof(a) / sizeof(int));
  checkBar(b, sizeof(b) / sizeof(int));
  checkBar(c, sizeof(c) / sizeof(int));
  checkBar(d, sizeof(d) / sizeof(int));

  return 0;
}

int checkBar(int *arr, int size) {
  int check = 0;
  int even = sumOfEven(arr, size);
  int odd = sumOfOdd(arr, size) * 3;
  int result = odd + even;
  printf("Result: %d\n", result);

  if (result % 10 == 0) {
    if (arr[size - 1] == 0) {
      printf("Yay!\n");
    }
    else {
      printf("Nay\n");
    }
  }
  else {
    check = 10 - (result % 10);

    if (arr[size - 1] == check) {
      printf("Yay!\n");
    }

    else {
      printf("Nay\n");
    }
  }
}

int sumOfOdd(int *arr, int size) {
  int sum = 0;

  for (int i = 0; i < size - 1; i += 2) {
    //printf("Odd: %d\n", arr[i]);
    sum += arr[i];
  }
  //printf("Odd sum: %d\n", sum);
  return sum;
}

int sumOfEven(int *arr, int size) {
  int sum = 0;
  for (int i = 1; i < size - 1; i += 2) {
    //printf("Even: %d\n", arr[i]);
    sum += arr[i];
  }
  //printf("Even sum: %d\n", sum);
  return sum;
}
