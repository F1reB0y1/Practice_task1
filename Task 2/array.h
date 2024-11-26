#ifndef ARRAY_H  // Перевіряємо, чи не визначено ARRAY_H
#define ARRAY_H

#include <stddef.h>  // Для size_t

// Функції для роботи з масивом
void fill_array(int **array, size_t n); // Функція для заповнення масиву випадковими числами
void print_array(int **array, size_t n); // Функція для виводу масиву
int sum_main_diagonal(int **array, size_t n); // Функція для обчислення суми головної діагоналі
int sum_secondary_diagonal(int **array, size_t n); // Функція для обчислення суми побічної діагоналі

#endif // ARRAY_H