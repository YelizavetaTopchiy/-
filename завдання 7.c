#include <stdio.h>
#include <math.h>

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int intersection_points(int x1, int y1, int r1, int x2, int y2, int r2) {
    double dist = distance(x1, y1, x2, y2);

    const double epsilon = 1e-6;

    if (dist > r1 + r2) {
        return 0; 
    } else if (fabs(dist) < epsilon && r1 == r2) {
        return -1; 
    } else if (dist + r1 < r2 || dist + r2 < r1) {
        return 0; 
    } else if (fabs(dist - (r1 + r2)) < epsilon || fabs(dist - fabs(r1 - r2)) < epsilon) {
        return 1; 
    } else {
        return 2; 
    }
}

int main() {
    int x1, y1, r1, x2, y2, r2;

    printf("Введіть координати та радіус першого кола (x1, y1, r1): ");
    scanf("%d %d %d", &x1, &y1, &r1);

    printf("Введіть координати та радіус другого кола (x2, y2, r2): ");
    scanf("%d %d %d", &x2, &y2, &r2);

    int points = intersection_points(x1, y1, r1, x2, y2, r2);

    if (points == -1) {
        printf("Кола мають безкінечну кількість точок перетину.\n");
    } else {
        printf("Кількість точок перетину: %d\n", points);
    }

    return 0;
}