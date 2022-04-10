#include <ctype.h>

int
io_parseamt(int argc, char *argv[]) {
  int scn = atoi(argv[1]);
  
  if (argc < 2) {
    return 0;
  }

  return scn;
}

char *
io_parsectx(int argc, char *argv[], char *ctx) {
  if (argc < 3) {
    return ctx;
  }
  
  return argv[2];
}
