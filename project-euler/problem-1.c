# include <stdio.h>

int main(void) {

  int a = 0, i = 0;
  
  for(i = 1; i < 1000; ++i) { // Så længe i er mindre end 1000, fortsætter koden
    if (i % 5 == 0) {         // Hvis i går op i 5
      a += i;                 // lægges i til a
    }
    else if (i % 3 == 0) {    // Det samme her, bare med 3
      a += i;
    }                         // Dette kunne også forsimples med ||
    
    printf("a: %d, i: %d\n",a, i); // Her printes summen indtil videre, og skridtet
  }

  printf("%d\n", a); // Her printes den endelige sum


  return 0; 
}
