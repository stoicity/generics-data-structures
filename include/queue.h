#ifndef QUEUE_H
#define QUEUE_H

#include <math.h>

#include "vector.h"

typedef struct queue {
    struct vector vector;
    unsigned int head;
    unsigned int tail;
} *queue_t;

#define queue_size(obj) (abs(obj->head-obj->tail))
#define queue_full(obj) (obj->head == obj->tail+1 || obj->head == 0 && obj->tail == obj->vector.capacity-1)
#define queue_empty(obj) (obj->head == obj->tail)
#define queue_create(type) _queue_create(sizeof(type))
#define queue_clean(obj) (obj->head = obj->tail = 0)
#define queue_dequeue(obj) { \
        if(obj->head == obj->vector.capacity-1){ \
            obj->head = 0; \
        }else{ \
            obj->head++; \
        } \
    }
#define queue_head(obj, data) (vector_get((vector_t)obj, obj->head, data))
#define queue_tail(obj, data) (vector_get((vector_t)obj, obj->tail-1, data))
queue_t _queue_create(size_t data_size);
void queue_destroy(queue_t obj);
int queue_enqueue(queue_t obj, void *data);

#endif