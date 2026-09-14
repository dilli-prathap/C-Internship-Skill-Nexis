#include <stdio.h>
#include <ctype.h>

int countWords(char *str) {
    int count = 0;
    int inWord = 0;

    while (*str != '\0') {
        if (!isspace(*str) && inWord == 0) {
            count++;
            inWord = 1;
        }
        else if (isspace(*str)) {
            inWord = 0;
        }
        str++;
    }
    return count;
}
int main() {
    char str[200];
    int words;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    words = countWords(str);

    printf("Number of words = %d", words);

    return 0;
}
