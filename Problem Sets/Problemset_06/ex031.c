#include <stdio.h>
#include <stdbool.h>

int n, k;

int num_ways(int* potions, int current_index, int current_power, bool* used) {
    int ways = 0;

    if (current_power >= k) {
        ways++;
    }
    
    for (int i = current_index; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            ways += num_ways(potions, i + 1, current_power + potions[i], used);
            used[i] = false;
        }
    }

    return ways;
}

int main() {
    scanf("%d %d", &n, &k);

    int potions[n];
    bool used[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &potions[i]);
        used[i] = false;
    }

    printf("%d\n", num_ways(potions, 0, 0, used));
    return 0;
}
