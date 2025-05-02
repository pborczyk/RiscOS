#include "memory.h"
#include "stdlib.h"
#include <stddef.h>
#include <stdint.h>
#include <sbi/sbi_version.h>
#include "csr.h"

void kmain(void) {

  printf("Hello world! %d", 13);
  unsigned long time;
  time = read_csr(CSR_TIME);
  printf("Time: %d", time);
}