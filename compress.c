#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

  int start_position = 0;
  int buffer_size = 0;

  if (start_position < *length) {
    buffer_size = buffer_size + 1;
    char buffer[buffer_size + 1];
    strncpy(buffer, &byte_array[start_position], buffer_size);
    buffer[buffer_size] = '\0';

    if (g_hash_table_contains(dictionary, buffer) == FALSE) {
      // emit code to output of buffer - 1

      g_hash_table_add(dictionary, buffer);
    }
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
