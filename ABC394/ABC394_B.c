#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    char* strings[n];
    int length[n];
    bool taken[n];
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(51 * sizeof(char));
        scanf("%s", strings[i]);
        length[i] = strlen(strings[i]);
        taken[i] = false;
    }

    char* answer = (char*)malloc(2600 * sizeof(char));
    strcpy(answer, "");
    for (int i = 0;  i < n; i++) {
        int mini = 100, min_index = 0;
        for (int j = 0; j < n; j++) {
            if (taken[j]) continue;
            if (length[j] < mini) {
                mini = length[j];
                min_index = j;
            }
        }
        answer = strcat(answer, strings[min_index]);
        taken[min_index] = true;
    }
    printf("%s\n", answer);
}