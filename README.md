# push_swap
push_swap is an algorithm project at school 42. sort a given list of numbers with the smallest number of operations that are predefined and using only two stacks

set of instruction :

  * sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
  * sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
  * ss : sa and sb at the same time.
  * pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
  * pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
  * ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
  * rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  * rr : ra and rb at the same time.
  * rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

## Compiling and running
run ```make```. Execute pushswap with the list of number you want : ```./push_swap 4 8 5 1 2 3```

for checker : ```./push_swap 4 8 5 1 2 3 | ./checker 4 8 5 1 2 3```
