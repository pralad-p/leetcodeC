//
// Created by prlpr on 22/02/2023.
//

#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "01-TwoSum.h"
#include "02-Palindrome.h"
#include "03-RomanToInt.h"

#define AR_SIZE 4

char * longestCommonPrefix(char ** strs, int strsSize){
    int index = 0, j = 1;
    char* res = (char*)calloc(200,sizeof(char));
    while (strs[j][index] != '\0' || strs[0][index] != '\0') {
        while (j < strsSize) {
            if (strs[j][index] != strs[0][index]) {
                for (int i =0; i < index; i++) {
                    res[i] = strs[0][i];
                }
                return res;
            }
            ++j;
        }
        ++index;
        j = 1;
    }
    return res;
}

bool isValid(char * s){
    if (strlen(s) == 0 || strlen(s) == 1) return false;
    char *stack = calloc(1000,sizeof(char));
    int top = -1;
    for (int i = 0; i<strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' ) {stack[++top] = s[i];}
        else if (s[i] == ')' && stack[top] != '(') return false;
        else if (s[i] == '}' && stack[top] != '{') return false;
        else if (s[i] == ']' && stack[top] != '[') return false;
        else {top--;}
    }
    free(stack);
    return true;
}

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
    printf("%s",isValid("()"));
    return 0;
}
