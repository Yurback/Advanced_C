#include <stdio.h>
#include <stdlib.h>

#define PRINT_int(x) printf(#x " is %d\n", x)

#define PRINT_ld(x) printf(#x " is %ld\n", x)

#define PRINT_f(x) printf(#x " is %f\n", x)

#define PRINT_s(x) printf(#x " is %s\n", x)

#define PRINT_p(x) printf(#x " is %p\n", x)

#define MAX(a, b) (a) > (b) ? (a) : (a) == (b) ? 1 \
											   : (b)

#define MIN(a, b) (a) > (b) ? (b) : (a) == (b) ? 1 \
											   : (a)

#define UPTO(n) for (int i = 0; i < (n); i++)

#define SIZE_ARR(arr) sizeof(arr) / sizeof(arr[0])
// prefix in {order, reverse}
#define DECLARESORT(type)                                               \
	static int order##_##type##_compare(const void *a, const void *b)   \
	{                                                                   \
		const type aa = *(const type *)a;                               \
		const type bb = *(const type *)b;                               \
		return aa - bb;                                                 \
	}                                                                   \
	static int reverse##_##type##_compare(const void *a, const void *b) \
                                                                        \
	{                                                                   \
		const type *aa = a;                                             \
		const type *bb = b;                                             \
		return bb - aa;                                                 \
	}                                                                   \
	void order##_##type##_sort(type *a, int n)                          \
	{                                                                   \
		qsort(a, n, sizeof(type), order##_##type##_compare);            \
	}                                                                   \
	void reverse##_##type##_sort(type *a, int n)                        \
	{                                                                   \
		qsort(a, n, sizeof(type), reverse##_##type##_compare);          \
	}

DECLARESORT(int);

struct student
{
	int age;
	char *name;
	char *surname;
};
struct array
{
	int size;
	void *ptr;
};

int func_qsort(const void *p1, const void *p2)
{
	const struct student x = *(const struct student *)p1;
	const struct student y = *(const struct student *)p2;
	return x.age - y.age;
}

int func_sort(void *element)
{
	const struct student x = *(const struct student *)element;
	return (x.age > 0);
}

struct array filter_arr(struct student *base, size_t number, size_t width, int (*cb)(void *))
{
	int count = 0;
	struct student *control_set = calloc(number, width);
	for (int i = 0, j = 0; i < number; i++)
	{
		if (cb(base + i))
		{
			control_set[j] = *((struct student *)base + i);
			j++;
			count++;
		}
		else
		{
			continue;
		}
	}
	control_set = realloc(control_set, count * width);

	PRINT_int(count);
	PRINT_ld(sizeof(control_set));
	struct array new = {.size = count, .ptr = control_set};
	return new;
}

int main(void)
{
	char *name = "Yuriy";
	PRINT_s(name);
	float count = 10.23;
	PRINT_f(count);

	int arr[20] = {2, 11, 7, 2, 5, 11, 11};

	PRINT_int(MAX(arr[0], arr[1]));

	order_int_sort(arr, SIZE_ARR(arr));
	UPTO(10) // for(int i=0; i<SIZE_ARR(arr); i++)
	PRINT_int(arr[i]);

	reverse_int_sort(arr, 10);
	UPTO(10) // for(int i=0; i<SIZE_ARR(arr); i++)
	PRINT_int(arr[i]);

	struct student students[100] = {{.age = 30, .name = "Mike", .surname = "Krutov"}, {.age = 22, .name = "Tom", .surname = "Cap"}, {.age = 25, .name = "Scot", .surname = "Duck"}, {0}, {.age = 18, .name = "STIVE", .surname = "Moor"}};
	UPTO(5)
	PRINT_int(students[i].age);

	// qsort(students, 10, sizeof(students[0]), func_qsort);
	// UPTO(10)
	// PRINT_int(students[i].age);

	struct array filtred = filter_arr(students, SIZE_ARR(students), sizeof(struct student), func_sort);
	UPTO(filtred.size)
	PRINT_int((((struct student *)(filtred.ptr) + i)->age));

	return 0;
}
