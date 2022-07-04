#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <string.h>

#define VECTOR_GROWTH_RATE 2
#define VECTOR_DEFAULT_CAP 1

/* Define a struct for dynamic array. */
typedef struct vector {
    void *memory;
    unsigned int capacity;
    unsigned int size;
    size_t data_size;
} *vector_t;

#define vector_empty(obj) (obj->size == 0)
#define vector_capacity(obj) (obj->capacity)
#define vector_size(obj) (obj->size)
#define vector_data_size(obj) (obj->data_size)
#define vector_push(obj, data) {\
        vector_set(obj, vector_size(obj), data); \
        obj->size++; \
    }
#define vector_pop(obj) (obj->size--)
#define vector_clean(obj) (obj->size = 0)
#define vector_back(obj, data) vector_get(obj, vector_size(obj)-1, data)
#define vector_create(type) _vector_create(sizeof(type), VECTOR_DEFAULT_CAP)
vector_t _vector_create(size_t data_size, unsigned int length);
void vector_destroy(vector_t obj);
int vector_resize(vector_t obj);
int vector_set(vector_t obj, unsigned int index, void *data);
int vector_get(vector_t obj, unsigned int index, void **data);

#endif