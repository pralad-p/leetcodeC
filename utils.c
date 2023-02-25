//
// Created by prlpr on 23/02/2023.
//
#include "utils.h"

Array getRandomArray(size_t size,int lower,int upper) {
    Array arr;
    arr.size = size;
    arr.value = (int*) malloc(size * sizeof(int));
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        arr.value[i] = (rand() % (upper - lower + 1)) + lower;
    }
    return arr;
}

Array getSpecifiedArray(size_t size,...) {
    Array arr;
    arr.size = size;
    arr.value = (int*) malloc(size * sizeof(int));
    va_list args;
            va_start(args, size);
    for (size_t i = 0; i < size; i++) {
        arr.value[i] = va_arg(args, int);
    }
            va_end(args);
    return arr;
}

Array getEmptyArray(size_t size) {
    Array arr;
    arr.size = size;
    arr.value = (int*) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
        arr.value[i] = -1;
    }
    return arr;
}

void clearArray(Array array) {
    free (array.value);
}
