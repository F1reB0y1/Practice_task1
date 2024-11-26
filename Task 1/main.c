#include <stdio.h>      // Для вводу/виводу
#include <stdlib.h>     // Для роботи з пам'яттю
#include <string.h>     // Для роботи з рядками
#include "c_list.h"     // Підключаємо заголовочний файл

int main() {
    c_list *list = create_list(10); // Створюємо новий список з початковою ємністю 10

    // Додаємо цілі числа до списку
    int *num1 = malloc(sizeof(int)); // Виділяємо пам'ять для цілого числа
    *num1 = 42; // Присвоюємо значення
    append_list_item(list, num1, int_type); // Додаємо число до списку

    int *num2 = malloc(sizeof(int)); // Виділяємо пам'ять для другого цілого числа
    *num2 = 100; // Присвоюємо значення
    append_list_item(list, num2, int_type); // Додаємо число до списку

    // Додаємо дійсні числа до списку
    float *fnum = malloc(sizeof(float)); // Виділяємо пам'ять для дійсного числа
    *fnum = 3.14; // Присвоюємо значення
    append_list_item(list, fnum, float_type); // Додаємо дійсне число до списку

    // Додаємо рядок до списку
    char *str = malloc(20 * sizeof(char)); // Виділяємо пам'ять для рядка
    strcpy(str, "Hello, World!"); // Копіюємо рядок у виділену пам'ять
    append_list_item(list, str, string_type); // Додаємо рядок до списку

    print_list(list); // Виводимо елементи списку

    free_list(list); // Звільняємо пам'ять для списку

    return 0; // Повертаємо 0 для успішного завершення програми
}