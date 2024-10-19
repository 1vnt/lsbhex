#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    fprintf(stderr, "usage: %s <lsb data>\n", argv[0]);
    return 1;
  };

  char *orig = argv[1];
  size_t len = strlen(orig);
  if ((len % 2) != 0) {
    fprintf(stderr, "invalid data length\n");
    return 1;
  }

  int pos = 0;
  int last = len - 2;
  while (pos < last) {
    char tmp1 = orig[pos];
    char tmp2 = orig[pos + 1];

    orig[pos] = orig[last];
    orig[pos + 1] = orig[last + 1];

    orig[last] = tmp1;
    orig[last + 1] = tmp2;

    pos += 2;
    last -= 2;
  }

  unsigned long long num = strtoull(orig, NULL, 16);
  printf("%llu\n", num);
  return 0;
}
