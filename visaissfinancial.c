// visaissfinancial.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkCardLimits(const char* cardNumber) {
    // Simulate fetching card limit
    if (strcmp(cardNumber, "1234567890123456") == 0) {
        printf("Card limit is valid.");
    } else {
        printf("Card limit not found for this card number.");
    }
}

int main() {
    const char* cardNumber = "1234567890123456";
    checkCardLimits(cardNumber);
    return 0;
}