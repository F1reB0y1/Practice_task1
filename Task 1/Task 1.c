#include <stdio.h>  // Підключаємо бібліотеку для вводу/виводу
#include <string.h> // Підключаємо бібліотеку для роботи з рядками
#include <ctype.h>  // Підключаємо бібліотеку для роботи з символами

// Функція для розшифрування рядка, використовуючи шифр Цезаря
void decrypt_caesar(char *ciphertext, int key) {
    int i; // Змінна для циклу

    // Проходимо по кожному символу рядка
    for (i = 0; ciphertext[i] != '\0'; i++) {
        // Якщо символ - літера
        if (isalpha(ciphertext[i])) {
            char offset = isupper(ciphertext[i]) ? 'A' : 'a'; // Визначаємо, чи літера велика чи мала
            // Розшифровуємо символ, зменшуючи його ASCII-код на значення ключа
            ciphertext[i] = (ciphertext[i] - offset - key + 26) % 26 + offset; 
        }
    }
}

// Функція для оцінки складності алгоритму
void evaluate_complexity() {
    printf("Time complexity: O(n), where n is the length of the input string.\n"); // Виводимо часову складність
    printf("Space complexity: O(1), as we are using a constant amount of extra space.\n"); // Виводимо просторову складність
}

int main() {
    char ciphertext[100]; // Змінна для зберігання зашифрованого рядка
    int key; // Змінна для зберігання ключа

    // Запитуємо у користувача зашифрований рядок
    printf("Enter the encrypted string (up to 100 characters): ");
    fgets(ciphertext, sizeof(ciphertext), stdin); // Зчитуємо рядок з консолі

    // Запитуємо у користувача ключ
    printf("Enter the encryption key: ");
    scanf("%d", &key); // Зчитуємо ключ з консолі

    // Розшифровуємо рядок
    decrypt_caesar(ciphertext, key); // Викликаємо функцію для розшифровки

    // Виводимо розшифрований рядок
    printf("Decrypted string: %s\n", ciphertext); // Виводимо результат

    // Оцінюємо складність алгоритму
    evaluate_complexity(); // Викликаємо функцію для оцінки складності

    return 0; // Повертаємо 0 для успішного завершення програми
}