//
// Created by prlpr on 22/02/2023.
//

#ifndef LEETCODEC_UTILS_H
#define LEETCODEC_UTILS_H


// External libraries
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

// Data structures
typedef struct Array {
    int* value;
    size_t size;
}Array;

// Local APIs
Array getRandomArray(size_t,int,int);
Array getSpecifiedArray(size_t,...);
Array getEmptyArray(size_t);
void clearArray(Array);





#endif //LEETCODEC_UTILS_H
