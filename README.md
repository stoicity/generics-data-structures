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
  v.push(v, &i);
  
  /* Get vector value at the end */
  int *ip;
  v.back(v, (void**)&ip);
  /* *ip= 10 */
  
  /* Set vector value at the index 0 */
  i = 20;
  v.set(v, 0, &i);
  
  /* Get vector value at the index 1 */
  v.get(v, 1, (void**)&ip));
  /* *ip = 20 */
}

```
