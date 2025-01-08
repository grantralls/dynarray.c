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

int array_length(array_info* array) {
    (array - 1)->length;
}

void* push_back(void* array, int item) {
    array_info* arrayInfo = get_array_info(array);
    if(arrayInfo->item_size != sizeof(item)) {
	return array;
    }

    if(arrayInfo->length == arrayInfo->capacity) {
	size_t totalBytes = sizeof(array_info) + (arrayInfo->item_size * arrayInfo->capacity);
	array_info* new_array = realloc(arrayInfo, totalBytes * 2);
	arrayInfo = new_array;
	arrayInfo->capacity = arrayInfo->capacity * 2;
    }

    int* another_new_array = (int*)(arrayInfo + 1);
    another_new_array[arrayInfo->length] = item;
    arrayInfo->length++;
    return arrayInfo + 1;
}
