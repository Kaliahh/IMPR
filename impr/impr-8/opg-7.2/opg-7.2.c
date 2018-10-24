/* Navn: Ane Søgaard Jørgensen
 * Dato: 24/10-2018
 * Beskrivelse: En test af program der tager et input sekunder og outputter timer, minutter, sekunder
 */

# include <stdio.h>
# include <assert.h>
# include "CuTest.h"

# define S_IN_MIN 60
# define S_IN_HOUR 3600
# define S_IN_DAY 86400

/*
void timeExchange(int, int *, int *, int *);

int main(void) {

  int t, sec, min, hour;

  printf("Input et antal sekunder: ");
  scanf(" %d", &t);

  timeExchange(t, &sec, &min, &hour);

  printf("Timer: %2d\nMinutter: %2d\nSekunder: %2d\n", hour, min, sec);

  return 0;
}
*/

void timeExchange(int t, int *sec, int *min, int *hour) {

  *sec = t % S_IN_MIN;
  *min = (t % S_IN_HOUR) / S_IN_MIN;
  *hour = t / S_IN_HOUR;
}

void test4000(CuTest *tc) {
  int sec, min, hour;

  timeExchange(4000, &sec, &min, &hour);

  int actualSec = sec;
  int actualMin = min;
  int actualHour = hour;

  int expectedSec = 40;
  int expectedMin = 6;
  int expectedHour = 1;

  CuAssertIntEquals(tc, expectedSec, actualSec);
  CuAssertIntEquals(tc, expectedMin, actualMin);
  CuAssertIntEquals(tc, expectedHour, actualHour);
}

void test75(CuTest *tc) {
  int sec, min, hour;

  timeExchange(75, &sec, &min, &hour);

  int actualSec = sec;
  int actualMin = min;
  int actualHour = hour;

  int expectedSec = 15;
  int expectedMin = 1;
  int expectedHour = 0;

  CuAssertIntEquals(tc, expectedSec, actualSec);
  CuAssertIntEquals(tc, expectedMin, actualMin);
  CuAssertIntEquals(tc, expectedHour, actualHour);
}

void test3700(CuTest *tc) {
  int sec, min, hour;

  timeExchange(3700, &sec, &min, &hour);

  int actualSec = sec;
  int actualMin = min;
  int actualHour = hour;

  int expectedSec = 40;
  int expectedMin = 1;
  int expectedHour = 1;

  CuAssertIntEquals(tc, expectedSec, actualSec);
  CuAssertIntEquals(tc, expectedMin, actualMin);
  CuAssertIntEquals(tc, expectedHour, actualHour);
}

void test55(CuTest *tc) {
  int sec, min, hour;

  timeExchange(55, &sec, &min, &hour);

  int actualSec = sec;
  int actualMin = min;
  int actualHour = hour;

  int expectedSec = 55;
  int expectedMin = 0;
  int expectedHour = 0;

  CuAssertIntEquals(tc, expectedSec, actualSec);
  CuAssertIntEquals(tc, expectedMin, actualMin);
  CuAssertIntEquals(tc, expectedHour, actualHour);
}

void test3661(CuTest *tc) {
  int sec, min, hour;

  timeExchange(3661, &sec, &min, &hour);

  int actualSec = sec;
  int actualMin = min;
  int actualHour = hour;

  int expectedSec = 1;
  int expectedMin = 1;
  int expectedHour = 1;

  CuAssertIntEquals(tc, expectedSec, actualSec);
  CuAssertIntEquals(tc, expectedMin, actualMin);
  CuAssertIntEquals(tc, expectedHour, actualHour);
}



CuSuite* testSuite(void) {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test4000);
  SUITE_ADD_TEST(suite, test75);
  SUITE_ADD_TEST(suite, test3700);
  SUITE_ADD_TEST(suite, test55);
  SUITE_ADD_TEST(suite, test3661);
  return suite;
}
