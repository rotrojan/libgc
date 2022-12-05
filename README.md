# libgc
## A simplistic and minimalist garbage collector library suitable for 42 students (and others).

Have you ever been tired of keeping track of all the allocated chunks of memory in your C code to avoid leaks in your projects ? **libgc** is yet another attempt to implement a garbage collector algorithm. This one is not the most performant nor the most memory efficient, but it will get the job done using a simple chained linked list.

### Provided functions
```
void			*gc_malloc(size_t size);
```
Use it as a replacement of your usual malloc.
```
void			gc_free(void **garbage_to_free);
```
Use it as a replacement of free: free the pointer pointed by _garbage_to_free_ and set it to NULL.
```
void			gc_free_all(void);
```
Use it to free everything that you allocated on the heap since the start of your program.
```
void			gc_exit(int status, char *message);
```
Exit your program with a call to _gc_free_all()_. The exit status of your program is set to _status_. If _status_ is equal to EXIT_SUCCESS, the _message_ string will be displayed on STDOUT, followed by a newline. Else, the string "Error :" will be prepend to your _message_ on STDERR followed, also followed by a newline (if allowed, you should use _strerror()_ here).

A huge thank to [lucocozz](https://www.github.com/lucocozz) for his review, help and participation to the code.

This library is far from beeing flawless. Do not hesitate to report bugs, typos or possible improvements.
