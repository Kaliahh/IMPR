/* Navn: Ane Søgaard Jørgensen
 * Dato: 09/11-2018
 * Beskrivelse: Opg 12.2 Sortering af et array af bøger
 */

 # include <stdio.h>
 # include <string.h>
 # include <stdlib.h>

 # define MAX_BOOKS 10
 # define TITLE_MAX 50
 # define AUTHOR_MAX 40
 # define PUBLISHER_MAX 20

 struct book {
   char title[TITLE_MAX];
   char author[AUTHOR_MAX];
   char publisher[PUBLISHER_MAX];
   int publishing_year;
   int university_text_book;
 };
 typedef struct book book;

 book make_book(char *title, char *author, char *publisher, int year, int text_book);
 void prnt_book(book b);
 void sortBooksTitle(book *, int);
 void sortBooksKindYear(book *, int);
 int titleComparator(const void *, const void *);
 int kindComparator(const void *, const void *);
 int yearComparator(const void *, const void *);

 int main(void) {
   book shelf[MAX_BOOKS];
   int i;

   shelf[0] =
     make_book("Problem Solving and Program Design in C", "Hanly and Koffman",
               "Pearson", 2010, 1);

   shelf[1] =
     make_book("C by Disssection", "Kelley and Pohl",
               "Addison Wesley", 2001, 1);

   shelf[2] =
     make_book("The C Programming Language", "Kernighan og Ritchie",
               "Prentice Hall", 1988, 1);

   shelf[3] =
     make_book("Pelle Erobreren", "Martin Andersen Nexoe",
               "Gyldendal", 1910, 0);

   shelf[4] = shelf[3];
   strcpy(shelf[4].title, "Ditte Menneskebarn");
   shelf[4].publishing_year = 1917;

   for(i = 0; i <= 4; i++) {
     prnt_book(shelf[i]);
   }

   sortBooksTitle(shelf, 4);

   printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n");

   for(i = 0; i <= 4; i++) {
     prnt_book(shelf[i]);
   }

   printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n");

   sortBooksKindYear(shelf, 4);

   for(i = 0; i <= 4; i++) {
     prnt_book(shelf[i]);
   }

   return 0;
 }


 book make_book(char *title, char *author, char *publisher,
                int year, int text_book){
   book result;
   strcpy(result.title, title); strcpy(result.author, author); strcpy(result.publisher, publisher);
   result.publishing_year = year;
   result.university_text_book = text_book;

   return result;
 }

 void prnt_book(book b){
   char *yes_or_no;

   yes_or_no = (b.university_text_book ? "yes" : "no");
   printf("Title: %s\n"
          "Author: %s\n"
          "Publisher: %s\n"
          "Year: %4i\n"
          "University text book: %s\n\n",
          b.title, b.author, b.publisher,
          b.publishing_year, yes_or_no);
 }

 void sortBooksTitle(book shelf[], int last) {
   qsort(shelf, last + 1, sizeof(struct book), titleComparator);
 }

 void sortBooksKindYear(book shelf[], int last) {

   int SENTINEL = 0;
   int i = 0;

   qsort(shelf, last + 1, sizeof(struct book), kindComparator);

   while (SENTINEL == 0) {
     if (shelf[i].university_text_book == 1) {
       SENTINEL = 1;
     }

     else {
       i++;
     }
   }

   qsort(shelf, i + 1, sizeof(struct book), yearComparator);
   qsort(shelf + i, last + 1 - i, sizeof(struct book), yearComparator);
 }

 int titleComparator(const void *a, const void *b) {
   book *p1 = (book*)a;
   book *p2 = (book*)b;
   return strcmp(p1->title, p2->title);
 }

 int kindComparator(const void *a, const void *b) {
   book *p1 = (book*)a;
   book *p2 = (book*)b;
   return ((p1->university_text_book) - (p2->university_text_book));
 }

 int yearComparator(const void *a, const void *b) {
   book *p1 = (book*)a;
   book *p2 = (book*)b;
   return ((p1->publishing_year) - (p2->publishing_year));
 }
