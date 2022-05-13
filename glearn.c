#include <malloc.h>
#include <inttypes.h>

#include "glearn.h"

struct array_int {
	char name[NAME_SIZE];
	int64_t *array;
	size_t size;
};


static char *strcpy_s(char *destptr, size_t buff_size, const char *srcptr) {

	for (size_t i = 0; i < buff_size; i++) {
		if (i == buff_size-1) {
			destptr[i] = '\0';
			break;
		}
		destptr[i] = srcptr[i];
	}

	return destptr;
}


inline static
_Bool check_size(size_t full_sz, size_t i) {
	return i >= full_sz ? 1 : 0;
}



struct array_int* array_int_create(size_t size, char name[NAME_SIZE]) {
	struct array_int* arr_res = (struct array_int*)malloc(sizeof(struct array_int));
	if (NULL == arr_res) return NULL;

	int64_t *array = (int64_t*)malloc(sizeof(int64_t) * size);
	if (NULL == array) {
		free(arr_res);
		return NULL;
	}

	for (size_t i = 0; i < size; i++) {
		*(array + i) = i * i + 2;
	}

	arr_res->array = array;
	arr_res->size = size;
	strcpy_s(arr_res->name, NAME_SIZE, name);
	return arr_res;
}


void array_int_destroy(struct array_int** arr) {
	free((*arr)->array);
	printf("%s) array is free\n", (*arr)->name);
	free(*arr);
	puts("and struct is free");
}


item* array_int_at(struct array_int* arr, size_t i) {
	if (check_size(arr->size, i)) return NULL;
	return &(item){.data = arr->array[i]};
}