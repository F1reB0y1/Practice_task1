#include <stdio.h>      // Для вводу/виводу
#include <stdlib.h>     // Для роботи з пам'яттю
#include <time.h>       // Для генерації випадкових чисел
#include "array.h"      // Підключаємо заголовочний файл

// Функція для заповнення масиву випадковими числами
void fill_array(int **array, size_t n) {
    for (size_t i = 0; i < n; i++) { // Проходимо по рядках
        for (size_t j = 0; j < n; j++) { // Проходимо по стовпцях
            array[i][j] = rand() % 11; // Заповнюємо випадковими числами від 0 до 10
        }
    }
}

// Функція для виводу масиву
void print_array(int **array, size_t n) {
    for (size_t i = 0; i < n; i++) { // Проходимо по рядках
        for (size_t j = 0; j < n; j++) { // Проходимо по стовпцях
            printf("%d ", array[i][j]); // Виводимо елемент масиву
        }
        printf("\n"); // Виводимо новий рядок після кожного рядка масиву
    }
}

// Функція для обчислення суми головної діагоналі
int sum_main_diagonal(int **array, size_t n) {
    int sum = 0; // Ініціалізуємо змінну для суми
    for (size_t i = 0; i < n; i++) { // Проходимо по головній діагоналі
        sum += array[i][i]; // Додаємо елемент до суми
    }
    return sum; // Повертаємо суму
}

// Функція для обчислення суми побічної діагоналі
int sum_secondary_diagonal(int **array, size_t n) {
    int sum = 0; // Ініціалізуємо змінну для суми
    for (size_t i = 0; i < n; i++) { // Проходимо по побічній діагоналі
        sum += array[i][n - 1 - i]; // Додаємо елемент до суми
    }
    return sum; // Повертаємо суму
}