#include <stdlib.h>

typedef struct {
    size_t item_size;
    size_t capacity;
    size_t length;
    void* end_item;
} array_info;

void* construct_array(size_t capacity, size_t item_size);
array_info* get_array_info(void* array);
void* push_back(void* array, int item);
int array_length(array_info* array);
