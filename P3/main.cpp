#include "Absyn.H"
#include "Parser.H"
#include <cstdint>
#include <stdio.h>
#include "Generator.H"

int process(FILE *input) {
  Program *parse_tree = pProgram(input);
  if (parse_tree) {
    Generator generator;
    generator.generate(parse_tree);
  } else {
    printf("SYNTAX ERROR\n");
    exit(1);
  }
  return 0;
}

int main(int argc, char **argv) {
  FILE *input;
  char *filename = NULL;

  if (argc > 1) {
    filename = argv[1];
  } else {
    input = stdin;
  }

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
