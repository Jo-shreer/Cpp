
return: exits the function (main → program ends normally).

exit(): cleans up (flushes buffers, closes files).

_exit(): immediately terminates the program without cleanup.



  
int *p; // wild pointer


What is the difference between const char *p, char * const p, and const char * const p?
const char *p: pointer to constant data (data cannot change).
char * const p: constant pointer (address cannot change).
const char * const p: both data and pointer are constant.


What is segmentation vs paging?
Segmentation: memory divided into variable-length segments.
Paging: memory divided into fixed-size pages.


What is the difference between stack overflow and heap overflow?
Stack overflow: exceeding function call/stack memory (e.g., deep recursion).
Heap overflow: writing beyond dynamically allocated memory.


char *s = "hello"; 
s[0] = 'H'; // ❌ Undefined behavior

What is undefined behavior in C?
Behavior not specified by C standard → compiler free to do anything.
Examples:

Accessing out-of-bounds array.
Modifying a variable more than once between sequence points.
Using uninitialized variables.


What is memory map of a C program?
Text (code) segment → executable code.
Data segment → global/static variables.
Heap → dynamic allocation (malloc).
Stack → local variables, function calls.
