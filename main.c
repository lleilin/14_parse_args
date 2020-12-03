#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **parse_args(char *line) {
  int n = strlen(line);
  char **args = malloc(sizeof(char*));
  char *p = line;
  int i = 0;
  args[i]=strsep(&p," ");
  while (args[i]) {
    i++;
    args[i] = strsep(&p," ");
  }

  return args;
}

int main() {
  char cmd[] = "ls -l -a";
  char **arguments = parse_args(cmd);
  execvp(arguments[0], arguments);
  return 0;
}
