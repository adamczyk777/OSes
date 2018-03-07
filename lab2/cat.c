#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void cat(FILE* f) {
  int c;
  while(EOF != (c = getc(f))) {
    if (EOF == putchar(c)) {
      perror("cat");
      return;
    }
  }
  if (ferror(f)) {
    perror("cat");
    return;
  }
}

int main(int argc, char **argv) {
  if (argc==1) return cat(stdin), 0;
  for(int i=1; i<argc; i++) {
    if (!strcmp("-", argv[i])) {
      cat(stdin);
      continue;
    }
    FILE *f = fopen(argv[i], "r");
    if (!f) {
      perror("cat");
      continue;
    }
    cat(f);
    fclose(f);
  }
  return 0;
}