#include "Absyn.H"
#include "Parser.H"
#include "TypeChecker.H"
#include <stdio.h>

void process(FILE *input) {
  Program *parse_tree = pProgram(input);
  if (parse_tree) {
    TypeChecker *checker = new TypeChecker();
    if (checker->check(parse_tree)) {
      printf("OK\n");
    } else {
      printf("TYPE ERROR\n");
      exit(1);
    }
  } else {
    printf("SYNTAX ERROR\n");
    exit(1);
  }
}

int main(int argc, char **argv) {
  FILE *input;
  char *filename = NULL;

  if (argc > 1)
    filename = argv[1];
  else
    input = stdin;

  if (filename) {
    input = fopen(filename, "r");
    if (!input) {
      printf("Cannot open the input file");
      exit(1);
    }
  } else {
    input = stdin;
  }
  process(input);
  return 0;
}
