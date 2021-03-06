#include "CuTest.h"
#include <stdio.h>

CuSuite* testSuite(void);

void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, testSuite());  /* Adding our test suite */

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main(void) {
    RunAllTests();
}
