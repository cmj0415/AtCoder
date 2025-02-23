#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 200001

bool isPair(char c1, char c2) {
    if (c1 == '(') return c2 == ')';
    else if (c1 == '[') return c2 == ']';
    else if (c1 == '<') return c2 == '>';
    else return false;
}

bool isColorful(char* str, int len) {
    if (len % 2) return false;
    char* queue = (char*) malloc(MAXLEN * sizeof(char));
    int rear = 0;
    queue[rear++] = str[0];
    for (int i = 1; i < len; i++) {
        if (isPair(queue[rear - 1], str[i])) {
            rear--;
        } else {
            queue[rear++] = str[i];
        }
    }
    return (rear == 0);
}   
int main() {
    char* str = (char*) malloc(MAXLEN * sizeof(char));
    scanf("%s", str);
    int len = strlen(str);
    if (isColorful(str, len)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}