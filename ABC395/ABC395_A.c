#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int prev = 0;
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num <= prev) {
            printf("No\n");
            return 0;
        } 
        prev = num;
    }
    printf("Yes\n");
}