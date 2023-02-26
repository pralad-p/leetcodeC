//
// Created by prlpr on 22/02/2023.
//

#include <stdio.h>
#include "utils.h"
#include "01-TwoSum.h"
#include "02-Palindrome.h"

#define AR_SIZE 4

void arrayBasedFramework() {
    //    Array* c = getRandomArray(AR_SIZE,LOWER_LIMIT,UPPER_LIMIT); // get random array
    Array c = getSpecifiedArray(AR_SIZE,2,7,11,15);
    int target = 9;
    // Before effects
    printf("Before run: \n");
    for (int i = 0; i < c.size; i++) printf(" %d ", c.value[i]);

    printf("\n");
    Array res = getEmptyArray(2);
    int *returnSize = calloc(1, sizeof(int));

    // Function to test
    res.value = twoSum(c.value,AR_SIZE,target,returnSize); // base function

    // After effects
    printf("After run: \n");
    for (int i = 0; i < c.size; i++) printf(" %d ", c.value[i]);

    // View results
    printf("\n=====> RESULTS <======\n");
    for (int i = 0; i < *returnSize; i++) {
        printf(" %d ", res.value[i]);
    }

    clearArray(c);
    free(returnSize);
}


int main() {
    int possible_value = 2222222;
    printf("%d has truth value: %s",possible_value,isPalindrome(possible_value) ? "true" : "false");

    return 0;
}
