#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME_LEN 101
#define MAX_EMAIL_LEN 31

typedef struct person {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int birth_date;
    int phone;
} Person;

int compare_person(const void* a, const void* b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n, flag;
    scanf("%d", &n);
    getchar();

    Person friends[n];
    for (int i = 0; i < n; i++) {
        fgets(friends[i].name, MAX_NAME_LEN, stdin);
        friends[i].name[strcspn(friends[i].name, "\n")] = '\0';

        fgets(friends[i].email, MAX_EMAIL_LEN, stdin);
        friends[i].email[strcspn(friends[i].email, "\n")] = '\0';

        scanf("%d", &friends[i].birth_date);
        getchar();

        scanf("%d", &friends[i].phone);
        getchar();
    }

    scanf("%d", &flag);
    getchar();

    if (flag == 0) {
        int month;
        scanf("%d", &month);

        bool found = false;
        for (int i = 0; i < n; i++) {
            char birth_date[9];
            sprintf(birth_date, "%d", friends[i].birth_date);

            char friend_birth_month[3] = {'\0'};
            strncpy(friend_birth_month, &birth_date[4], 2);
            if (atoi(friend_birth_month) == month) {
                found = true;
                printf("%s %d\n", friends[i].name, friends[i].phone);
            }
        }
        if (!found) printf("NONE\n");
    } else if (flag == 1) {
        qsort(friends, n, sizeof(Person), compare_person);

        for (int i = 0; i < n; i++) {
            printf("%s\n", friends[i].name);
            printf("%s\n", friends[i].email);
            printf("%d\n", friends[i].birth_date); 
            printf("%d\n", friends[i].phone);
        }
    }

    return 0;
}
