#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *LoadString(int N) {
    char *str = (char *)malloc((N + 1) * sizeof(char));
    if (str == NULL) exit(1);
    printf("Enter a string: ");
    fgets(str, N + 1, stdin);
    str[strcspn(str, "\n")] = '\0';
    return str;
}

int StringLength(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

void LoadArray(char *p, char arr[]) {
    int i = 0;
    while (p[i] != '\0') {
        arr[i] = p[i];
        i++;
    }
    arr[i] = '\0';
}

void ReverseArray(char arr[], char rev[], int n) {
    for (int i = 0; i < n; i++) {
        rev[i] = arr[n - 1 - i];
    }
    rev[n] = '\0';
}

void DisplayArray(char arr[], int n) {
    for (int i = 0; i < n; i++) printf("%c", arr[i]);
    printf("\n");
}

int SumStringASCII(char *p) {
    if (*p == '\0') return 0;
    return *p + SumStringASCII(p + 1);
}

void ReverseString(char *start, char *end) {
    if (start >= end) return;
    char temp = *start;
    *start = *end;
    *end = temp;
    ReverseString(start + 1, end - 1);
}

int main() {
    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar();

    str = LoadString(n);
    int len = StringLength(str);
    char arr[len + 1], rev[len + 1];

    LoadArray(str, arr);

    printf("\nOriginal array: ");
    DisplayArray(arr, len);

    ReverseArray(arr, rev, len);
    printf("Reversed array: ");
    DisplayArray(rev, len);

    int sum = SumStringASCII(str);
    printf("\nSum of ASCII values: %d\n", sum);

    ReverseString(str, str + len - 1);
    printf("String reversed recursively: %s\n", str);

    free(str);
    return 0;
}
