#include <stdio.h>

typedef struct Knight {
    int T;
} Knight;

typedef struct Dragon {
    int F;
} Dragon;

int main() {
    int n;
    Knight hero;
    Dragon dragon = (Dragon){0};
    scanf("%d %d", &n, &hero.T);

    int mana[n];

    for (int i = 0; i < n; i++) {
        hero.T = (hero.T + mana[i]) * (hero.T + mana[i]);
        dragon.F += mana[i];

        if ((hero.T - dragon.F*dragon.F) - dragon.F >= 0) {
            printf("%d\n", i+1);
            return 0;
        }
    }
    return 0;
}
