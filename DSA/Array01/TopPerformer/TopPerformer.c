#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the marks of students:\n");

    int marks[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    int top = n * 0.1;
    if (top == 0) {
        top = 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] < marks[j + 1]) {
                int swap = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = swap;
            }
        }
    }

    printf("Top performance:\n");
    for (i = 0; i < top; i++) {
        printf("%d\n", marks[i]);
    }

    return 0;
}
