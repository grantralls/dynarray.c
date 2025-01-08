#include <stdlib.h>
#include "dynarray.h"
#include <stdio.h>
#include <string.h>

void* construct_array(size_t capacity, size_t item_size) {
    array_info* my_ptr = malloc(sizeof(array_info) + item_size * capacity);
    if(my_ptr == NULL) {
	printf("crap");
    }
    my_ptr->capacity = capacity;
    my_ptr->item_size = item_size;
    my_ptr->length = 0;
    my_ptr->end_item = my_ptr + 1;
    return my_ptr + 1;
}

array_info* get_array_info(void* array) {
    return (array_info*)array - 1;
}

size_t array_length(void* array) {
    return get_array_info(array)->length;
}

void push_back(void* array, void* item) {
    array_info* arrayInfo = get_array_info(array);

    if(arrayInfo->length == arrayInfo->capacity) {
	size_t totalBytes = sizeof(array_info) + (arrayInfo->item_size * arrayInfo->capacity);
	array_info* arrayInfo = realloc(arrayInfo, totalBytes * 2);
	array = arrayInfo + 1;
	arrayInfo->capacity = arrayInfo->capacity * 2;
    }

    memcpy(array + (arrayInfo->length * arrayInfo->item_size), item, arrayInfo->item_size);
    arrayInfo->length++;
}
