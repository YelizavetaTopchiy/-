#include <stdio.h>
#include <stdlib.h>

int minSteps(int x, int y) {
    if (x == y) {
        return 0;
    }

    int distance = abs(y - x);
    int steps = 0;
    int current_length = 1;
    int total_distance = 0;

    while (total_distance < distance) {
        steps++;
        total_distance += current_length;
        if (total_distance >= distance) break;
        
        steps++;
        total_distance += current_length;
        if (total_distance >= distance) break;

        current_length++;
    }

    return steps;
}

int main() {
    int x, y;
    printf("Введіть x та y: ");
    scanf("%d %d", &x, &y);
    
    int result = minSteps(x, y);
    printf("Мінімальні кроки від %d до %d: %d\n", x, y, result);
    
    return 0;
