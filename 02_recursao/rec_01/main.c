#include <stdio.h>

void ImprimeInvertido(char *string);

int main() {
  char texto[1001];

  while(scanf("%s", texto) == 1) {
    ImprimeInvertido(texto);
    printf(" ");
  }

  return 0; 
}

void ImprimeInvertido(char *string) {
  if(string[0] == '\0') {
    return;
  } else {
    ImprimeInvertido(string+1);
    printf("%c", string[0]);
  }
}

