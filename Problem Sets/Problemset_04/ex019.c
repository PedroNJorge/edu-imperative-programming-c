#include <stdio.h>

int main() {
    // A matrix
    int N, M, K;
    scanf("%d %d", &N, &M);

    int A[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // B matrix
    scanf("%d %d", &M, &K);

    int B[M][K];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // A*B matrix
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int k = 0; k < M; k++) {
            sum += A[i][k]*B[k][0];
        }
        printf("%d", sum);

        for (int j = 1; j < K; j++) {
            sum = 0;
            for (int k = 0; k < M; k++) {
                sum += A[i][k]*B[k][j];
            }
            printf(" %d", sum);
        }
        printf("\n");
    }
    return 0;
}
