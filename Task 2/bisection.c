#include <stdio.h> // Підключаємо бібліотеку для вводу/виводу
#include <math.h>  // Підключаємо бібліотеку для математичних функцій
#include "bisection.h" // Підключаємо наш заголовок

// Функція для обчислення значення f(x) = a * sin(x) - b * cos(x)
double f(double x, double a_coeff, double b_coeff) {
    return a_coeff * sin(x) - b_coeff * cos(x); // Обчислюємо значення функції
}

// Функція для знаходження перетину двох функцій методом бісекції
double bisection(double a, double b, double tolerance, double a_coeff, double b_coeff) {
    double mid; // Змінна для зберігання середини відрізка

    // Цикл, поки відстань між a і b більша за допустиму похибку
    while ((b - a) >= tolerance) {
        mid = (a + b) / 2.0; // Обчислюємо середину відрізка

        // Якщо f(mid) дорівнює нулю, то ми знайшли корінь
        if (f(mid, a_coeff, b_coeff) == 0.0) {
            break; // Виходимо з циклу
        }

        // Визначаємо, в якій частині відрізка знаходиться корінь
        if (f(mid, a_coeff, b_coeff) * f(a, a_coeff, b_coeff) < 0) {
            b = mid; // Корінь знаходиться в лівій частині
        } else {
            a = mid; // Корінь знаходиться в правій частині
        }
    }

    return mid; // Повертаємо знайдений корінь
}