#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Word {
    char word[31];
    int consonantCount;
};

int compareWords(const void *a, const void *b) {
    struct Word *wordA = (struct Word *)a;
    struct Word *wordB = (struct Word *)b;
    return wordA->consonantCount - wordB->consonantCount;
}

int isDelimiter(char c) {
    // Визначаємо, чи є символ роздільником (не слово)
    return !isalpha(c);
}

int main() {
    char filename[100];
    printf("Введіть назву файлу: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n Можливо, файл не існує або немає прав на його читання.\n"
               "Перевірте, чи введено правильну назву файлу та повторіть спробу.\n"
               "Назва файлу не повинна містити пробілів.\n"
               "Приклад назви файлу: input.txt\n"
               "Упевніться що копія файлу перебуває в одній папці з виконуваним файлом та cmake-build-debug при наявності такої.\n");
        return 1;
    }

    struct Word words[10000];
    int wordCount = 0;

    char wordBuffer[31];
    int wordBufferIndex = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (isDelimiter(c)) {
            if (wordBufferIndex > 0) {
                if (wordBufferIndex > 31) {
                    wordBuffer[31] = '\0';
                } else {
                    wordBuffer[wordBufferIndex] = '\0';
                }

                int isDuplicate = 0;
                for (int i = 0; i < wordCount; i++) {
                    if (strcmp(words[i].word, wordBuffer) == 0) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    strcpy(words[wordCount].word, wordBuffer);
                    words[wordCount].consonantCount = 0;
                    for (int i = 0; wordBuffer[i] != '\0'; i++) {
                        if (isalpha(wordBuffer[i]) && !strchr("aeiouAEIOU", wordBuffer[i])) {
                            words[wordCount].consonantCount++;
                        }
                    }
                    wordCount++;
                }

                wordBufferIndex = 0;
            }
        } else {
            if (wordBufferIndex < 30) {
                wordBuffer[wordBufferIndex++] = c;
            }
        }
    }

    qsort(words, wordCount, sizeof(struct Word), compareWords);

    printf("Слова без повторень, відсортовані за зростанням кількості приголосних літер:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s (%d приголосних літер)\n", words[i].word, words[i].consonantCount);
    }

    fclose(file);
    return 0;
}
