#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int bib[n + 1], stare[n + 1], map[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &stare[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &bib[i]);
        map[bib[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", bib[stare[map[i]]]);
    }
}