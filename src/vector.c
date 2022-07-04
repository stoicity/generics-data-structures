#include "vector.h"

vector_t _vector_create(size_t data_size, unsigned int size){
    vector_t obj;

    obj = malloc(sizeof(struct vector));
    
    if(!obj){
        return NULL;
    }

    obj->memory = malloc(data_size * size);
    obj->capacity = size;
    obj->size = 0;
    obj->data_size = data_size;

    return obj;
}

void vector_destroy(vector_t obj){
    // Deallocate struct vector_
    memset(obj->memory, 0, vector_data_size(obj) * vector_capacity(obj));
    free(obj->memory);

    memset(obj, 0, sizeof(struct vector));
    free(obj);
}

int vector_resize(vector_t obj){
    void *temp;
    unsigned int new_capacity;

    // Allocate new memory
    new_capacity = VECTOR_GROWTH_RATE * vector_capacity(obj);
    temp = malloc(new_capacity * vector_data_size(obj));

    if(!temp){
        return -1;
    }

    // Copying memory
    memset(temp, 0, new_capacity * vector_data_size(obj));
    memcpy(temp, obj->memory, vector_data_size(obj) * vector_capacity(obj));
    
    memset(obj->memory, 0, vector_data_size(obj) * vector_capacity(obj));
    free(obj->memory);
    
    obj->capacity = new_capacity;
    obj->memory = temp;

    return 0;
}

int vector_push(vector_t obj, void *data){
    if(vector_size(obj) >= vector_capacity(obj)){
        if(vector_resize(obj) < 0){
            return -1;
        }
    }

    memcpy((unsigned char*)obj->memory + vector_size(obj) * vector_data_size(obj), data, vector_data_size(obj));
    obj->size++;
    
    return 0;
}

int vector_set(vector_t obj, unsigned int index, void *data){
    if(index >= vector_capacity(obj)){
        return -1;
    }

    memcpy((unsigned char*)obj->memory + index * vector_data_size(obj), data, vector_data_size(obj));

    return 0;
}

int vector_get(vector_t obj, unsigned int index, void **data){
    void *return_data;

    if(index >= vector_capacity(obj)){
        return -1;
    }

    return_data = malloc(vector_data_size(obj));
    memcpy(return_data, (unsigned char*)obj->memory + index * vector_data_size(obj), vector_data_size(obj));
    *data = return_data;
    
    return 0;
}
