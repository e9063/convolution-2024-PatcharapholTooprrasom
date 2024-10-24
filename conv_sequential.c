#include<stdio.h>
#include<stdlib.h>
#include <omp.h>
#include <time.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);
    int *FF = malloc(sizeof(int) * NF);
    int *R = malloc(sizeof(int) * (NA - NF + 1));

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    for(int i = 0; i < NF; i++){
        FF[i] = F[NF - i - 1];
    };

    // implement here
    clock_t start_time = clock();
    for(int j = 0; j < NA - NF + 1; j++){
        int sum = 0;
        for(int i = 0; i < NF; i++){
            sum += A[j + i]*FF[i];
        }
        R[j] = sum;
    }
    clock_t end_time = clock();

    // ---- free memory ----
    free(F);
    free(A);
    free(FF);
    free(R);
    // ---- end free ----
    double time = ((double)(end_time-start_time)) / CLOCKS_PER_SEC;
    printf("Sequential time: %f\n", time);
    return 0;
}
