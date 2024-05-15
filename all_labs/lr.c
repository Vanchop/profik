#include"lr.h"
#include<stdio.h>
int lab1(){
    float x1,x2,d,a,b,c;
    printf("Ввод a: \n");
    scanf("%f", &a);
    printf("Ввод b: \n");
    scanf("%f", &b);
    printf("Ввод c: \n");
    scanf("%f", &b);
    d = b * b - 4 * a;
    x1 = (-b + d*1/2)/(2*a);
    x2 = (-b - d*1/2)/(2*a);
    printf("Корни: \n");
    printf("x1 = %f\n",x1);
    printf("x2 = %f",x2);
    return 0;
}
int lab2() {
    int N;//кол-во итераций
    float epsilon = 0.0001; // заданная точность
    float sum = 0.0;// вводим сумму
    float elem;//дробь
    int i;
    printf("Введите количество итераций: ");
    scanf("%d", &N);
    for (i = 1; i <= N && (elem = (float)i / ((i+1)*(i+1))) > epsilon; i++) {
        sum += elem;
    }
    printf("%f , %d ", sum, i);
    return 0;
}
int lab3(){
        printf("Вводите слова:");

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


        printf("Самое длинное слово:");
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
    int main() {
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
}
int lab5(){
    int arr[10];
    int sum_first_half = 0, sum_second_half = 0;

    printf("Введите 10 целых чисел для массива:\n");
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

    printf("Результат: ");
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
    printf("Введите элементы массива %dx%d:\n", N, K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Вывод введенного массива
    printf("\nВведенный массив:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    zeroOtherRows(arr);

    // Вывод измененного массива
    printf("\nИзмененный массив:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int lab7(){
    long long int P;

    printf("Введите число: ");
    scanf("%lld", &P);

    for (int i = 0; i < sizeof(long long int); i++) {
        int count = 0;
        for (int j = 0; j < 8; j++) {
            if ((P & (1 << (i*8 + j))) != 0) {
                count++;
            }
        }
        printf("Байт %d: %d единиц\n", i+1, count);
    }

    return 0;
}

