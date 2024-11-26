#include <stdio.h>  // Підключаємо бібліотеку для вводу/виводу
#include <math.h>   // Підключаємо бібліотеку для математичних функцій

// Функція для обчислення квадратного кореня
double babylonian_sqrt(double number, double tolerance) {
    double guess = number / 2.0; // Початкове припущення (половина числа)
    int iterations = 1; // Лічильник ітерацій

    // Цикл, поки різниця між квадратом припущення і числом більша за допустиму похибку
    while (fabs(guess * guess - number) > tolerance) {
        guess = (guess + number / guess) / 2.0; // Оновлюємо припущення за формулою
        iterations++; // Збільшуємо лічильник ітерацій
    }

    // Виводимо кількість ітерацій
    printf("Number of iterations: %d\n", iterations);
    return guess; // Повертаємо обчислений квадратний корінь
}

int main() {
    double number; // Змінна для зберігання введеного числа
    double tolerance; // Змінна для зберігання допустимої похибки

    // Запитуємо у користувача число
    printf("Enter the number to find the square root of: ");
    scanf("%lf", &number); // Зчитуємо число з консолі

    // Запитуємо у користувача допустиму похибку
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance); // Зчитуємо похибку з консолі

    // Обчислюємо квадратний корінь і виводимо результат
    double result = babylonian_sqrt(number, tolerance); // Викликаємо функцію для обчислення
    printf("Approximate square root: %lf\n", result); // Виводимо обчислений квадратний корінь

    return 0; // Повертаємо 0 для успішного завершення програми
}