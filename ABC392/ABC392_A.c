#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a >= b && a >= c) {
        if (a == b * c) {
            printf("Yes\n");
            return 0;
        }
    } else if(b >= a && b >= c) {
        if (b == a * c) {
            printf("Yes\n");
            return 0;
        }
    } else {
        if (c == a * b) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}