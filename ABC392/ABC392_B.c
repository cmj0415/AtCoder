#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;
    scanf("%d%d", &n, &m);
    int arr[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }
    int count = n;
    bool absent[n];
    for (int i = 0; i < n; i++) {
        absent[i] = true;
    }
    for (int i = 0; i < m; i++) {
        absent[arr[i] - 1] = false;
        count--;
    }
    printf("%d\n", count);
    for (int i = 0; i < n; i++) {
        if (absent[i]) {
            printf("%d ", i + 1);
        }
    }
}