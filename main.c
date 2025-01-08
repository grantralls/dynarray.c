#include <stdlib.h>
#include <stdio.h>
#include "dynarray.h"

int main() {
    int* array = (int*)construct_array(15, sizeof(int));
    for(int i = 0; i < 100; i++) {
	array = (int*)push_back(array, 100 - i);
    }

    for(int i = 0; i < get_array_info(array)->length; i++) {
	printf("%d\n", array[i]);
    }

    free(get_array_info(array));
    
    return 0;
}
