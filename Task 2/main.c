#include <stdio.h>      // Для вводу/виводу
#include <stdlib.h>     // Для роботи з пам'яттю
#include <time.h>       // Для генерації випадкових чисел
#include "array.h"      // Підключаємо заголовочний файл

int main() {
    size_t n; // Змінна для розміру масиву
    printf("Enter the size of the array (N): "); // Запитуємо розмір масиву
    scanf("%zu", &n); // Зчитуємо розмір масиву

    // Виділяємо пам'ять для 2D масиву
    int **array = malloc(n * sizeof(int*)); // Виділяємо пам'ять для рядків
    for (size_t i = 0; i < n; i++) {
        array[i] = malloc(n * sizeof(int)); // Виділяємо пам'ять для стовпців
    }

    srand(time(NULL)); // Ініціалізуємо генератор випадкових чисел
    fill_array(array, n); // Заповнюємо масив випадковими числами
    printf("Generated 2D array:\n");
    print_array(array, n); // Виводимо масив

    // Обчислюємо суми діагоналей
    int main_diagonal_sum = sum_main_diagonal(array, n);
    int secondary_diagonal_sum = sum_secondary_diagonal(array, n);

    // Виводимо результати
    printf("Sum of the main diagonal: %d\n", main_diagonal_sum);
    printf("Sum of the secondary diagonal: %d\n", secondary_diagonal_sum);

    // Звільняємо пам'ять
    for (size_t i = 0; i < n; i++) {
        free(array[i]); // Звільняємо пам'ять для кожного рядка
    }
    free(array); // Звільняємо пам'ять для масиву рядків

    return 0; // Повертаємо 0 для успішного завершення програми
}