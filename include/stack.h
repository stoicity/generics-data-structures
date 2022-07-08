#ifndef STACK_H
#define STACK_H

#include "vector.h"

/* Use vector as stack */
typedef vector_t stack_t;

#define stack_empty(obj) vector_empty(obj)
#define stack_create(type) vector_create(type)
#define stack_clean(obj) vector_clean(obj)
#define stack_destroy(obj) vector_destroy(obj)
#define stack_push(obj, data) vector_push(obj, data)
#define stack_pop(obj) vector_pop(obj)
#define stack_top(obj, data) vector_back(obj, data)
#define stack_size(obj) vector_size(obj)

#endif
