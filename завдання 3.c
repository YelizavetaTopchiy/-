#include <stdio.h>

int main() {
    int p;
    printf("p: ");
    scanf("%d", &p);

    if (p == 0) {
        printf("Кількість чисел: 0\n");
        return 0;
    }

    int end5[p + 1];
    int end9[p + 1];

    end5[1] = 1; 
    end9[1] = 1; 
    if (p > 1) {
        end5[2] = 2; 
        end9[2] = 2;
    }

    for (int i = 3; i <= p; i++) {
        end5[i] = end5[i - 1] + end9[i - 1] - end5[i - 2];
        end9[i] = end5[i - 1] + end9[i - 1] - end9[i - 2];
    }

    int total = end5[p] + end9[p];
    printf("Кількість чисел із %d розрядів: %d\n", p, total);

    return 0;
}
