#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void encoding();
char * read_input(const char *, int *);

int main() {

  encoding();

  return 0;
}

void encoding() {
  GHashTable *dictionary = g_hash_table_new(g_str_hash, g_str_equal);

  int *length = malloc(sizeof(int));
  char *byte_array = read_input("input", length);

  int i;
  for (i = 0; i < *length; i = i + 1) {
    printf("%c", byte_array[i]);
  }

  free(length);
  free(byte_array);
}

char * read_input(const char *file_name, int *length) {
  FILE *input_file;
  input_file = fopen(file_name, "r");

  if (input_file == NULL) {
    printf("Can't open input file.\n");
  }

  fseek(input_file, 0, SEEK_END);
  *length = ftell(input_file);
  char *byte_array = malloc(*length);
  fseek(input_file, 0, SEEK_SET);
  fread(byte_array, 1, *length, input_file);

  fclose(input_file);
  return byte_array;
}
