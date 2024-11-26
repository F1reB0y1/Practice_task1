#ifndef C_LIST_H  // Перевіряємо, чи не визначено C_LIST_H
#define C_LIST_H

#include <stddef.h>  // Для size_t

// Визначаємо типи даних для елементів списку
typedef enum {
    int_type,    // Для цілочисельних значень
    float_type,  // Для дійсних значень
    string_type  // Для рядкових значень
} list_data_type;

// Оголошуємо структуру для списку
typedef struct {
    void **items;            // Динамічний масив для зберігання елементів
    list_data_type *types;   // Масив для зберігання типів даних
    size_t size;             // Кількість елементів у списку
    size_t capacity;         // Потужність списку
} c_list;

// Функції для роботи зі списком
c_list* create_list(size_t initial_capacity); // Створення нового списку
int append_list_item(c_list *list, void *item, list_data_type type); // Додавання елемента до списку
void print_list(const c_list *list); // Вивід елементів списку
void free_list(c_list *list); // Звільнення пам'яті

#endif // C_LIST_H