#include "memory.h"
#include "stdlib.h"
#include <stddef.h>
#include <stdint.h>
#include <sbi/sbi_version.h>

void kmain(void) {

  printf("Hello world! %d", 13);
  // printf("Hello world! %d before \r\n after", 12);
  return;
}
