#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 300001
int main() {
    char* str = (char*) malloc(MAXLEN * sizeof(char));
    scanf("%s", str);
    int len = strlen(str);
    int i = 0;
    while (i < len - 1) {
        if (str[i] == 'W') {
            int j = i + 1;
            while(str[j] == 'W') j++;
            if (str[j] == 'A') {
                str[i] = 'A';
                for (int k = i + 1; k <= j; k++) {
                    str[k] = 'C';
                }
            }
            i = j + 1;
        } else {
            i++;
        }
    }
    printf("%s", str);
}