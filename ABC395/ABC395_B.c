#include <stdio.h>
#include <stdlib.h>
void paint(char** grid, int i, int j, char c) {
    for (int k = i; k <= j; k++) {
        grid[i][k] = grid[k][i] = grid[j][k] = grid[k][j] = c;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    char** grid = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) grid[i] = (char*) malloc(n * sizeof(char));
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (i % 2) {
            paint(grid, i, n - i - 1, '.');
        } else {
            paint(grid, i, n - i - 1, '#');
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}