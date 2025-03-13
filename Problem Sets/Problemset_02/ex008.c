#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, max_cost[2] = {0};
    scanf("%d", &n);

    int mountains[n], cost_array[n];

    // Get sequence and the max cost and respective index
    scanf("%d", &mountains[0]);
    for (int i = 1; i < n; i++) {
        scanf("%d", &mountains[i]);
        cost_array[i] = abs(mountains[i-1] - mountains[i]);
        
        if (cost_array[i] > max_cost[0]) {
            max_cost[0] = cost_array[i];
            max_cost[1] = i;
        }
    }

    // Make it circular (calculate the first element with the last)
    cost_array[0] = abs(mountains[0] - mountains[n-1]);
    if (cost_array[0] > max_cost[0]) {
        max_cost[0] = cost_array[0];
        max_cost[1] = 0;
    }

    // To minimize the cost, remove the costliest travel
    for (int i = 0; i < n; i++) {
        printf("%d", mountains[(i+max_cost[1]) % n]);
        if (i < n - 1)
            printf(" ");
    }

    printf("\n");
 
    return 0;
}
