//
// Created by prlpr on 26/02/2023.
//

#include "02-Palindrome.h"

int reverse(int number) {
    int reversed = 0;
    while (number > 0) {
        int val = number % 10;
        reversed = reversed * 10 + val;
        number/= 10;
    }
    return reversed;
}

bool isPalindrome(int x) {
    // A negative number can never be a palindrome (pesky dash)
    if (x < 0) {
        return false;
    }
    if (x == 0) {
        return true;
    }
    // Now where's that reversing algorithm that involved modulo?
    int nDigits = 0, temp = x;
    while (temp > 0) {
        nDigits++;
        temp /= 10;
    }
    int orig = x;
    if (nDigits > 6) {
        int f_split,s_split;
        int split = nDigits/2;
        if (nDigits % 2 == 0) {
            f_split = s_split = split;
        }
        else {
            f_split = split + 1;
            s_split = split;
        }
        int second_part = orig % (int)pow(10,s_split);
        int first_part = orig / (int)pow(10,f_split);
        return second_part == reverse(first_part) ? true : false;
        }
    return orig == reverse(orig) ? true : false;
}