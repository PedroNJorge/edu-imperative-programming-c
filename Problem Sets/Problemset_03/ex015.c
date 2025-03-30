#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 50
#define MAX_WORDS 1000

typedef struct Word {
    char original[MAX_WORD_SIZE + 1];
    char sorted[MAX_WORD_SIZE + 1];
} Word;

typedef struct Group {
    char representative[MAX_WORD_SIZE + 1];
    int num_elements;
} Group;

int compare_char(const void *x, const void *y) {
    return *(char *)x - *(char *)y;
}

int compare_group(const void *x, const void *y) {
    Group* Gx = (Group *) x;
    Group* Gy = (Group *) y;

    if (Gx->num_elements != Gy->num_elements)
        return Gy->num_elements - Gx->num_elements;

    return strcmp(Gx->representative, Gy->representative);
}

int main() {
    int N;
    int NUM = 1; 

    while (scanf("%d", &N) == 1 && N != 0) {
        if (NUM > 1)
            printf("\n");

        Word words[N];
        
        // Read words
        for (int i = 0; i < N; ++i) {
            scanf("%s", words[i].original);
            strcpy(words[i].sorted, words[i].original);
            qsort(words[i].sorted, strlen(words[i].sorted), sizeof(char), compare_char);
        }

        Group groups[N];
        int used_words[MAX_WORDS] = {0};
        int num_groups = 0;

        for (int i = 0; i < N; ++i) {
            if (used_words[i])
                continue;

            // Make group with the new word
            strcpy(groups[num_groups].representative, words[i].original);
            groups[num_groups].num_elements = 1;

            // Check anagrams for the new word
            for (int j = i + 1; j < N; ++j) {
                if (!used_words[j] && strcmp(words[i].sorted, words[j].sorted) == 0) {
                    // Check if new anagram is appears first in alphabetic order
                    if (strcmp(groups[num_groups].representative, words[j].original) > 0)
                        strcpy(groups[num_groups].representative, words[j].original);

                    ++groups[num_groups].num_elements;
                    used_words[j] = 1;    
                }
            }
            ++num_groups;
        }

        // Sort groups
        qsort(groups, num_groups, sizeof(Group), compare_group);

        // Output
        printf("#%d\n", NUM);
        for (int i = 0; i < num_groups; ++i) {
            printf("%s: %d\n", groups[i].representative, groups[i].num_elements);
        }

        ++NUM;
    }

    return 0;
}
