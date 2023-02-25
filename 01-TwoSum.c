//
// Created by prlpr on 22/02/2023.
//

#include "01-TwoSum.h"

/* Make map-like data structure */
typedef struct mapNode {
    int key; //key
    int index; //value
    struct mapNode *next; // LL impl. for duplicate keys
} mapList;


int *twoSum(const int *nums, int numsSize, int target, int *returnSize) {
    /* Initialize map */
    mapList **map = calloc(numsSize, sizeof(mapList*));
    /* Set each of the map nodes to zero */
    for (int i = 0; i < numsSize; i++) {
        map[i] = NULL;
    }
    /* Go through each number in array */
    for (int i = 0; i < numsSize; i++) {
        /* I take the target removed value, and store it to a variable */
        int target_retained = target - nums[i];
        int sec_index = ((target_retained % numsSize) + numsSize) % numsSize;
        /* Check if this value exists in the map */
        for (mapList *iterNode = map[sec_index]; iterNode != NULL; iterNode = iterNode->next) {
            /* Look if target_retained already exists in this map */
            if (iterNode->key == target_retained) {
                /* Found it; and also found our solution */
                int *res = calloc(2, sizeof(int));
                res[0] = iterNode->index;
                res[1] = i;
                *returnSize = 2;
                /* Before returning our result, we need to clean up map memory */
                for (int j = 0; j < numsSize; j++) {
                    mapList *node = map[j];
                    while (node != NULL) {
                        mapList *next_ptr = node->next;
                        free(node);
                        node = next_ptr;
                    }
                }
                free(map);
                return res;
            }
        }

        /* Otherwise, add it to my map and continue */
        mapList *newNode = malloc(sizeof(mapList));
        newNode->key = nums[i];
        newNode->index = i;
        newNode->next = map[((nums[i] % numsSize) + numsSize) % numsSize];
        map[((nums[i] % numsSize) + numsSize) % numsSize] = newNode;
        /* newNode is freed either when a solution is found; or after this for-loop */
    }
    /* If solution not found; free and return NULL */
    for (int i = 0; i < numsSize; i++) {
        mapList *node = map[i];
        while (node != NULL) {
            mapList *next_ptr = node->next;
            free(node);
            node = next_ptr;
        }
    }
    free(map);
    *returnSize = 0;
    return NULL;
}