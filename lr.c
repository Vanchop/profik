#include"lr.h"
#include<stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3
int is_gl(char c) {
    char gl[] = "aeiouyAEIOUY";
    for (int i = 0; i < 12; i++) {
        if (c == gl[i]) {
            return 1;
        }
    }
    return 0;
}
int count_gl(char *word) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (is_gl(word[i])) {
            count++;
        }
    }
    return count;
}
int count_consonants(char *word) {
    int count = 0;
    for (int i = 0; word[i] != '\0' && word[i] != ' '; i++) {
        if (!is_gl(word[i]) && word[i] >= 'A' && word[i] <= 'z') {
            count++;
        }
    }
    return count;
}
void removeWord(char *string, int start, int end) {
    int i;
    for (i = end; string[i] != '\0'; i++, start++) {
        string[start] = string[i];
    }
    string[start] = '\0';
}
void bubbleSort2D(int arr[ROWS][COLS]) {
    int temp;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < ROWS; k++) {
                for (int l = 0; l < COLS; l++) {
                    if (arr[k][l] > arr[i][j]) {
                        temp = arr[k][l];
                        arr[k][l] = arr[i][j];
                        arr[i][j] = temp;
                    }
                }
            }
        }
    }
}
int lab1(){
    float x1,x2,d;
    d = 4 * 4-3 * 4;
    x1 = (-4+d*1/2)/2;
    x2 = (-4-d*1/2)/2;
    printf("x1= %f\n",x1);
    printf("x2= %f\n",x2);
    return 0;
}
int lab11(){
    float x1,x2,d,a,b,c;
    printf("Vvod a: \n");
    scanf("%f", &a);
    printf("Vvod b: \n");
    scanf("%f", &b);
    printf("Vvod c: \n");
    scanf("%f", &b);
    d = b * b - 4 * a;
    x1 = (-b + d*1/2)/(2*a);
    x2 = (-b - d*1/2)/(2*a);
    printf("Korni: \n");
    printf("x1 = %f\n",x1);
    printf("x2 = %f",x2);
    return 0;
}
int lab2() {
    float epsilon = 0.0001; //заданная точность
    float sum = 0.0;
    float elem;
    int i=1;
    while ((elem = (float)i / ((i+1)*(i+1)))>epsilon){
        sum += elem;
        i++;
    }
    printf("%f , %d ",sum, i);
    return 0;
}
int lab21(){
    int N;//кол-во итераций
    float epsilon = 0.0001; // заданная точность
    float sum = 0.0;// вводим сумму
    float elem;//дробь
    int i;
    printf("Vvedite kolvo iteracii: ");
    scanf("%d", &N);
    for (i = 1; i <= N && (elem = (float)i / ((i+1)*(i+1))) > epsilon; i++) {
        sum += elem;

    }
    printf("%f , %d ", sum, i);
    return 0;
}
int lab3(){
        printf("text:");

        char c;
        char word[100];
        char longest_word[100];
        int max_length = 0;
        int length = 0;
        while ((c = getchar ()) != EOF) {
            if (c != '\n') {
                word[length] = c ;
                length++;
            } else {
                if (length > max_length){
                    max_length = length;
                    for (int i = 0; i < length; i++) {
                        longest_word[i] = word[i];
                    }
                }
                length = 0;
            }
        }
        printf("dlinslovo:");
        for (int i = 0; i < max_length; i++){
            printf("%c", longest_word[i]);
        }
        printf("\n");
        return 0;
}
int lab4(){
    int isVowel(char c) {
    c = tolower(c);//Приводим символ к нижнему регистру
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    char str[100];
    printf("Strokaa: ");
    fgets(str, 100, stdin);
    int i = 0, j = 0, vowelCount = 0;

    while (1) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0') {
            if (vowelCount % 2 == 0) { //Заменить слово пробелами
                for (int k = j; k < i; k++) {
                    str[k] = ' ';
                }
            }
            j = i + 1;
            vowelCount = 0;
        } else if (isVowel(str[i])) {
            vowelCount++;
        }

        if (str[i] == '\0') {
            break;
        }
        i++;
    }

    printf("stroka posle del: %s\n", str);
    return 0;
}
int lab41(){
    char str[100], word[20], newstr[100];
    int i, j = 0, gls, cons, to_index = 0;

    printf("Vvedite stroku: ");
    char c;
    i = 0;
    while ((c = getchar()) != '\n' && i < 100) {
        str[i] = c;
        i++;
    }
    str[i] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            word[j++] = str[i];
        } else {
            if (j > 0) {
                word[j] = '\0';
                gls = count_gl(word);
                cons = count_consonants(word);

                if ((gls % 2 != 0) || (gls % 2 == 0 && cons % 2 == 0)) {
                    int k = 0;
                    while (word[k] != '\0') {
                        newstr[to_index] = word[k];
                        to_index++;
                        k++;
                    }
                    newstr[to_index] = ' ';
                    to_index++;
                }
            }
            j = 0;
        }
    }

    newstr[to_index] = '\0';

    printf("Resultat: %s\n", newstr);

    return 0;
}
int lab5(){
    int arr[10];
    int sum_first_half = 0, sum_second_half = 0;

    printf("10 chisel dlya massiva:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        sum_first_half += arr[i];
        sum_second_half += arr[i + 5];
    }

    if (sum_first_half < sum_second_half) {
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    } else {
        for (int i = 5; i < 10; i++) {
            arr[i] = 0;
        }
    }

    printf("Rezultat: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
int lab51(){
    int arr[10];
    int sum_first_half = 0, sum_second_half = 0;
    int count_first_half = 0, count_second_half = 0;

    printf("Vvedite 10 celix chisel dlya massiva:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        sum_first_half += arr[i];
        sum_second_half += arr[i + 5];
        if (arr[i] != 0) {
            count_first_half++;
        }
        if (arr[i + 5] != 0) {
            count_second_half++;
        }
    }

    int diff;
    if (sum_first_half < sum_second_half) {
        diff = sum_second_half - sum_first_half;
    } else {
        diff = sum_first_half - sum_second_half;
    }

    // Если условие для обнуления не выполняется, увеличиваем diff до значения, при котором count_first_half или count_second_half меньше sum_first_half
    while (diff % (count_first_half - 1) != 0 && diff % (count_second_half - 1) != 0) {
        diff++;
    }

    if (sum_first_half < sum_second_half) {
        for (int i = 0; i < 5; i++) {
            if (arr[i] == 0) {
                arr[i] = diff / count_first_half; // Устанавливаем значение элемента так, чтобы сумма не изменилась
            }
        }
    } else {
        for (int i = 5; i < 10; i++) {
            if (arr[i] == 0) {
                arr[i] = diff / count_second_half; // Устанавливаем значение элемента так, чтобы сумма не изменилась
            }
        }
    }

    printf("Resultat: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
int lab6() {
    #define N 4
    #define K 3
    void zeroOtherRows(int arr[N][K]) {
    int minRow = 0, maxRow = 0;
    int minElement = arr[0][0], maxElement = arr[0][0];

    // Находим минимальный и максимальный элементы массива и строки, содержащей их
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (arr[i][j] < minElement) {
                minElement = arr[i][j];
                minRow = i;
            }
            if (arr[i][j] > maxElement) {
                maxElement = arr[i][j];
                maxRow = i;
            }
        }
    }

    // Обнуляем все элементы массива, кроме строки, содержащей минимальный и максимальный элементы
    for (int i = 0; i < N; i++) {
        if (i != minRow && i != maxRow) {
            for (int j = 0; j < K; j++) {
                arr[i][j] = 0;
            }
        }
    }
}

    int arr[N][K];

    // Ввод массива
    printf("Vvedite elem massiva %dx%d:\n", N, K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Вывод введенного массива
    printf("\nvved massiv:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    zeroOtherRows(arr);

    // Вывод измененного массива
    printf("\nizm massiv:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int lab61(){
    int arr[ROWS][COLS];

    printf("Vvedite %d elementa dlya 2mernogo massiva razmerom %d x %d:\n", ROWS * COLS, ROWS, COLS);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nIsxodniy massiv:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    bubbleSort2D(arr);

    printf("\nOtsortirovaniy 2mer massiv:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int lab7(){
    long long int P;

    printf("vved chislo: ");
    scanf("%lld", &P);

    for (int i = 0; i < sizeof(long long int); i++) {
        int count = 0;
        for (int j = 0; j < 8; j++) {
            if ((P & (1 << (i*8 + j))) != 0) {
                count++;
            }
        }
        printf("bait %d: %d edinic\n", i+1, count);
    }
    return 0;
}

