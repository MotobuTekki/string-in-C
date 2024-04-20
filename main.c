#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeExtraSpaces(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i]; i++) {
        if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0')) {
            continue;
        }
        str[j++] = str[i];
    }
    str[j] = '\0';
}

void swapWords(char *str) {
    char *min_word = NULL, *max_word = NULL;
    int min_len = strlen(str), max_len = 0;

    char *word = strtok(str, " ");
    while (word != NULL) {
        int len = strlen(word);
        if (len < min_len) {
            min_len = len;
            min_word = word;
        }
        if (len > max_len) {
            max_len = len;
            max_word = word;
        }
        word = strtok(NULL, " ");
    }

    if (min_word && max_word) {
        char temp[strlen(max_word) + 1];
        strcpy(temp, max_word);
        strcpy(max_word, min_word);
        strcpy(min_word, temp);
    }
}

int main() {
    char str[1000];

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

  
    printf("Строка повторяется три раза с запятой: %s, %s, %s\n", str, str, str);
    printf("Количество символов в строке: %d\n", (int)strlen(str));

    
    if (strlen(str) > 5) {
        printf("Первые три символаПоследние три символа: %.3s\n", str);
        printf("Последние три символа: %.3s\n", str + strlen(str) - 3);
    } else {
        for (int i = 0; i < strlen(str); i++) {
            printf("%c", str[0]);
        }
        printf("\n");
    }

    
    removeExtraSpaces(str);
    printf("Строка с удаленными лишними пробелами: %s\n", str);

    
    swapWords(str);
    printf("Строка, в которой самые большие и самые маленькие слова поменялись местами: %s\n", str);

    return 0;
}


