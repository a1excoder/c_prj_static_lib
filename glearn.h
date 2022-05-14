#ifndef H_LEARN
#define H_LEARN

#include <inttypes.h>
#include <stdio.h>

#define NAME_SIZE 32

typedef struct {
	int64_t data;
} item;

struct array_int;

struct array_int* array_int_create(size_t size, char[NAME_SIZE]);
void array_int_destroy(struct array_int**);
item* array_int_at(struct array_int*, size_t);

struct array_interface {
	struct array_int* (*create) (size_t, char[NAME_SIZE]);
	void (*destroy) (struct array_int**);
	item* (*at) (struct array_int*, size_t);
} static const array = {
	array_int_create,
	array_int_destroy,
	array_int_at
};

#endif // H_LEARN
