#include <stdio.h> // Підключаємо бібліотеку для вводу/виводу
#include <math.h>  // Підключаємо бібліотеку для математичних функцій
#include "bisection.h" // Підключаємо наш заголовок

int main() {
    double a_coeff, b_coeff; // Змінні для коефіцієнтів функцій
    double a = 0, b = M_PI; // Визначаємо початкові межі для пошуку (0 до π)
    double tolerance; // Змінна для зберігання допустимої похибки

    // Запитуємо у користувача коефіцієнти
    printf("Enter coefficient a for f(x) = a * sin(x): ");
    scanf("%lf", &a_coeff); // Зчитуємо коефіцієнт a

    printf("Enter coefficient b for g(x) = b * cos(x): ");
    scanf("%lf", &b_coeff); // Зчитуємо коефіцієнт b

    // Запитуємо у користувача допустиму похибку
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance); // Зчитуємо похибку з консолі

    // Викликаємо функцію для знаходження перетину
    double root = bisection(a, b, tolerance, a_coeff, b_coeff); // Знаходимо корінь
    printf("Intersection point: %lf\n", root); // Виводимо знайдений корінь

    return 0; // Повертаємо 0 для успішного завершення програми
}