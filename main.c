#include <stdlib.h>
#include <stdio.h>
#include "dynarray.h"

int main() {
    int* array = (int*)construct_array(15, sizeof(int));
    for(int i = 0; i < 100; i++) {
	int value = 100 - i;
	push_back(array, &value);
    }

    for(int i = 0; i < get_array_info(array)->length; i++) {
	printf("%d\n", array[i]);
    }
    free(get_array_info(array));

    return 0;
}
