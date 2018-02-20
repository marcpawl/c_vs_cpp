
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_replace(char *target, const char *needle, const char *replacement)
{
    size_t target_len = strlen(target);
    char* buffer =malloc(target_len);
    assert(buffer);
    char *insert_point = &buffer[0];
    const char *tmp = target;
    size_t needle_len = strlen(needle);
    size_t repl_len = strlen(replacement);
 
    while (1) {
        const char *p = strstr(tmp, needle);
 
        // walked past last occurrence of needle; copy remaining part
        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        // copy part before needle
        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;
 
        // copy replacement string
        memcpy(insert_point, replacement, repl_len);
        insert_point += repl_len;
 
        // adjust pointers, move on
        tmp = p + needle_len;
    }
 
    // write altered string back to target
    strcpy(target, buffer);

    free(buffer);
}

int main(int argc, char** argv)
{
  const char* orig=
 #include "data.txt"
  int len = strlen(orig);
  char* target = malloc(len+1);
  assert(target);
  strncpy(target, orig, len);

  const char* needle=",";
  const char* replacement = "\n";

  str_replace(target, needle, replacement);

#if 0
  fwrite(target, 1, len, stdout);
#endif

  return 0;
} 

