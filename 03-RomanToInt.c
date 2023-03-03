//
// Created by prlpr on 26/02/2023.
//

#include <string.h>
#include "03-RomanToInt.h"

int romanToInt(char *s) {
    int value = 0;
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case 'M': {
                value += 1000;
                break;
            }
            case 'D': {
                value += 500;
                break;
            }
            case 'C': {
                if (i+1 < strlen(s) && (s[i + 1] == 'D' || s[i + 1] == 'M')) { value -= 100; }
                else { value += 100; }
                break;
            }
            case 'L': {
                value += 50;
                break;
            }
            case 'X': {
                if (i+1 < strlen(s) && (s[i + 1] == 'L' || s[i + 1] == 'C')) value -= 10;
                else value += 10;
                break;
            }
            case 'V': {
                value += 5;
                break;
            }
            case 'I': {
                if (i+1 < strlen(s) && (s[i + 1] == 'V' || s[i + 1] == 'X')) value -= 1;
                else value += 1;
                break;
            }
            default:
                break;
        }
    }
    return value;
}
