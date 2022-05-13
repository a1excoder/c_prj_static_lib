#include <stdio.h>
#include "glearn.h"

int main(int argc, char const *argv[])
{
	struct array_int *a = array.create(10, "first data");
	if (NULL == a) return 1;
	item *res = array.at(a, 3);
	if (NULL == res) return 2;

	printf("3 is %ld\n", res->data);
	array.destroy(&a);
	return 0;
}