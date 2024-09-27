#include <stdio.h>

int main() {
    unsigned int value, key, encrypted, decrypted;

    // Entering the value and key
    printf("Enter a value: ");
    scanf("%u", &value);

    printf("Enter a key (number of bits for XOR): ");
    scanf("%u", &key);

    // XOR encryption
    encrypted = value ^ key;

    // XOR decryption (repeated XOR with the same key returns the original value)
    decrypted = encrypted ^ key;

    // Results output
    printf("Original value (Decimal): %u\n", value);
    printf("Encrypted value (Decimal): %u\n", encrypted);
    printf("Decrypted value (Original): %u\n", decrypted);

    return 0;
}
