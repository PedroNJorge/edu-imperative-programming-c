#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_NAME 51

typedef struct Empresa {
    unsigned int NIF;
    char name[MAX_LEN_NAME];
    char area[MAX_LEN_NAME];
    unsigned int area_code;
    unsigned int rendimentos;
} Empresa;

int compare(const void* a, const void* b) {
    return ((((Empresa *)a)->area_code) - ((Empresa *)b)->area_code);
}

int main() {
    int num_empresas, flag;
    scanf("%d %d", &num_empresas, &flag);
    getchar();

    Empresa empresas[num_empresas];
    for (int i = 0; i < num_empresas; i++) {
        scanf("%d", &empresas[i].NIF);
        getchar();

        fgets(empresas[i].name, MAX_LEN_NAME, stdin);
        empresas[i].name[strcspn(empresas[i].name, "\n")] = '\0';

        fgets(empresas[i].area, MAX_LEN_NAME, stdin);
        empresas[i].area[strcspn(empresas[i].area, "\n")] = '\0';

        scanf("%d", &empresas[i].area_code);
        getchar();

        scanf("%d", &empresas[i].rendimentos);
        getchar();
    }
    
    qsort(empresas, num_empresas, sizeof(Empresa), compare);

    if (flag == 0) {
        int num_uniq_area_code = 1;
        int last_seen_area_code = empresas[0].area_code;
        for (int i = 1; i < num_empresas; i++) {
            if (empresas[i].area_code != last_seen_area_code) {
                num_uniq_area_code++;
                last_seen_area_code = empresas[i].area_code;
            }
        }
        printf("%d\n", num_uniq_area_code);
    }
    else if (flag == 1) {
        int curr_area_code = empresas[0].area_code;
        unsigned long int sum_rendimentos = empresas[0].rendimentos;

        for (int i = 1; i < num_empresas; i++) {
            if (empresas[i].area_code != curr_area_code) {
                printf("%d %lu\n", curr_area_code, sum_rendimentos);
                curr_area_code = empresas[i].area_code;
                sum_rendimentos = empresas[i].rendimentos;
            }
            else {
                sum_rendimentos += empresas[i].rendimentos;
            }
        }
        printf("%d %lu\n", curr_area_code, sum_rendimentos);
    }

    return 0;
}
