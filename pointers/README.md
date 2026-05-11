# Working with Pointers

```
int num = 10;
int *p = &num 

// * - used to differentiate the pointer variable from others
// & - will return the address
```

Can you update the value of x using a pointer variable?

```
int x = 5;
int *p = &x;
*p = 6;
```

## Pointer Arithmetic

Incrementing or decrementing pointer variables

```
int num[5] = [1,2,3,4,5];
int *p = &num 

// * - used to differentiate the pointer variable from others
// & - will return the address
```

## Pointer to Pointer or Double Pointer

```
int x = 5;
int *y = &x;
*y = 6;
cout << x << endl;
int **z = &y;
cout << **z << endl;
```