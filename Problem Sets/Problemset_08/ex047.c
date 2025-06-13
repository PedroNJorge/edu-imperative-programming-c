#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 30
#define SKIP_EOL {while (getchar()!='\n') ;}
#define SKIP_SPACE {while (getchar()!=' ') ;}

char carlos[7] = {'C','a','r','l','o','s', '\0'};

int readAndCountWords();
char* readName();
int* rmFromArray(int index, int* array, int len);
int findOut(int p, int k, int* index_array);

int main() {
  int n, p, k;
  int carlos_pos, out_index;

  scanf("%d", &n);
  SKIP_EOL; // skip end_of_line

  for (int game = 0; game < n; game++) {
        p = readAndCountWords();
        scanf("%d", &k);
        getchar();

        char** names = (char **)malloc(sizeof(char *) * k);
        int* index_array = (int *)malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            index_array[i] = i;
            names[i] = readName();

            if (strcmp(names[i], carlos) == 0) carlos_pos = i;
        }


        out_index = findOut(p, k, index_array);
        if (out_index == carlos_pos) printf("O Carlos nao se livrou\n");
        else printf("O Carlos livrou-se (coitado do %s!)\n", names[out_index]);

        free(names);
        free(index_array);
    }
}

int readAndCountWords() {
  char ch= getchar();
  int nwords = 0;
  while (ch!='\n') {
    while ((ch=getchar())!=' ' && ch!='\n') ;
    nwords++;
    while (ch!='\n' && (ch=getchar()==' '));
  }
  return nwords;
}

char* readName() {
    char c = getchar();
    char* buffer = (char *)malloc(sizeof(char) * MAX_NAME_LEN);

    int i = 0;
    while (c != ' ' && c != '\n') {
        buffer[i] = c;
        c = getchar();
        i++;
    }

    buffer[i] = '\0';
    return buffer;
}

int* rmFromArray(int index, int* array, int len) {
    int* buffer = (int *)malloc(sizeof(int) * (len - 1));

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (i != index) {
            buffer[j] = array[i];
            j++;
        }
    }

    return buffer;
}

int findOut(int p, int k, int* index_array) {
    p--;

    int rm = 0;
    while (k > 1) {
        rm = (p + rm) % k;
        index_array = rmFromArray(rm, index_array, k);
        k--;
    }

    return index_array[0];
}
