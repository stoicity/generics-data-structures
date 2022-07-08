#include "queue.h"

queue_t _queue_create(size_t data_size){
    queue_t obj;

    obj = malloc(sizeof(struct queue));

    if(!obj){
        return NULL;
    }

    obj->vector.memory = malloc(data_size * VECTOR_DEFAULT_CAP);
    obj->vector.size = 0;
    obj->vector.capacity = VECTOR_DEFAULT_CAP;
    obj->vector.data_size = data_size;
    obj->head = obj->tail = 0;

    return obj;
}

void queue_destroy(queue_t obj){
    vector_destroy((vector_t)obj);

    memset(obj, 0, sizeof(struct queue));
    free(obj);
}

int queue_enqueue(queue_t obj, void *data){
    unsigned int old_capacity = obj->vector.capacity;

    if(queue_full(obj)){
        if(vector_resize((vector_t)obj) < 0){
            return -1;
        }

        // Relocating elements
        if(obj->tail < obj->head){
            memcpy((unsigned char*)obj->vector.memory + obj->vector.data_size * old_capacity, obj->vector.memory, obj->tail * obj->vector.data_size);
            obj->tail = old_capacity;
        }
    }

    vector_set((vector_t)obj, obj->tail, data);

    if(obj->tail == obj->vector.capacity-1){
        obj->tail = 0;
    }else{
        obj->tail++;
    }

    return 0;
}
