#include <stdio.h>

// Функция для нахождения минимального из 4 чисел
double findMin(double a, double b, double c, double d) {
    double min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}

// Собственная сортировка (пузырьком)
void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    double A, B, C, D;
    printf("Введите 4 числа (A, B, C, D): ");
    scanf("%lf %lf %lf %lf", &A, &B, &C, &D);

    if (B > C && A > D) {
        // Условие выполнено — уменьшаем все числа на минимум
        double min = findMin(A, B, C, D);
        A -= min;
        B -= min;
        C -= min;
        D -= min;
    } else {
        // Условие не выполнено — ищем наибольшее из отрицательных и заменяем на 0
        double arr[4] = {A, B, C, D};
        double maxNegative = -1e9; // достаточно маленькое число
        int index = -1;

        for (int i = 0; i < 4; i++) {
            if (arr[i] < 0 && arr[i] > maxNegative) {
                maxNegative = arr[i];
                index = i;
            }
        }

        if (index != -1) arr[index] = 0; // заменяем наибольшее отрицательное на 0

        // возвращаем значения
        A = arr[0];
        B = arr[1];
        C = arr[2];
        D = arr[3];
    }

    printf("Результат:\nA = %.2f\nB = %.2f\nC = %.2f\nD = %.2f\n", A, B, C, D);

    return 0;
}