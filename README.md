Common Data Structures Generic Implemented in C

## How to build

cd build/ && make all

## Use examples

#### Vector Interface
```
/* Using generic dynamic array aka vector */
#include "vector.h"

int main(){
  /* Create vector for int type */
  vector v = vector_create(int);
  
  /* Append vector at the end */
  int i = 10
  vector_push(v, &i);
  
  /* Get vector value at the end */
  int *ip;
  vector_back(v, (void**)&ip);
  /* *ip= 10 */
  
  /* Set vector value at the index 1 */
  i = 20;
  vector_set(v, 1, &i);
  
  /* Get vector value at the index 1 */
  vector_get(v, 1, (void**)&ip));
  /* *ip = 20 */
}

```
