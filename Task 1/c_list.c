#include <stdio.h>      // Для вводу/виводу
#include <stdlib.h>     // Для роботи з пам'яттю
#include <string.h>     // Для роботи з рядками
#include "c_list.h"     // Підключаємо заголовочний файл

// Функція для створення нового списку
c_list* create_list(size_t initial_capacity) {
    c_list *list = malloc(sizeof(c_list)); // Виділяємо пам'ять для списку
    list->items = malloc(initial_capacity * sizeof(void*)); // Виділяємо пам'ять для масиву елементів
    list->types = malloc(initial_capacity * sizeof(list_data_type)); // Виділяємо пам'ять для масиву типів
    list->size = 0; // Ініціалізуємо кількість елементів
    list->capacity = initial_capacity; // Встановлюємо початкову ємність
    return list; // Повертаємо вказівник на новий список
}

// Функція для додавання елемента до списку
int append_list_item(c_list *list, void *item, list_data_type type) {
    if (list->size >= list->capacity) { // Якщо досягнуто максимальну ємність
        return -1; // Повертаємо -1, якщо список переповнений
    }
    list->items[list->size] = item; // Додаємо новий елемент до списку
    list->types[list->size] = type;  // Додаємо тип нового елемента
    list->size++; // Збільшуємо кількість елементів
    return list->size; // Повертаємо новий розмір списку
}

// Функція для виводу елементів списку
void print_list(const c_list *list) {
    printf("List size = %zu\n", list->size); // Виводимо кількість елементів у списку
    for (size_t i = 0; i < list->size; i++) { // Проходимо по всіх елементах списку
        if (list->types[i] == int_type) { // Якщо тип елемента - ціле число
            printf("%d ", *(int*)list->items[i]); // Виводимо ціле число
        } else if (list->types[i] == float_type) { // Якщо тип елемента - дійсне число
            printf("%.2f ", *(float*)list->items[i]); // Виводимо дійсне число
        } else if (list->types[i] == string_type) { // Якщо тип елемента - рядок
            printf("%s ", (char*)list->items[i]); // Виводимо рядок
        }
    }
    printf("\n"); // Виводимо новий рядок після списку
}

// Функція для звільнення пам'яті списку
void free_list(c_list *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->items[i]); // Звільняємо пам'ять для кожного елемента
    }
    free(list->items); // Звільняємо пам'ять для масиву елементів
    free(list->types); // Звільняємо пам'ять для масиву типів
    free(list); // Звільняємо пам'ять для самого списку
}