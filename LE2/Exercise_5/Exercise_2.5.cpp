
#include <iostream>

/*
§ Have a look at the following swap routines
• void swap(int &a, int &b) { int c=a; a=b; b=c; }
• void c_swap(int *a, int *b) { int c=*a; *a=*b; *b=c; }
§ Let the compiler compile the code but ask the compiler to stop at the assembly stage
$ gcc -S -o source.s source.cc § Compare the assembly code,
 what do you observe? § How do you interpret the difference(s)?
 */

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void c_swap(int *e, int *f) {
    int c = *e;
    *e = *f;
    *f = c;
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int *e = &c;
    int *f = &d;

    swap(a, b);
    c_swap(e, f);

}

/*
Answer:
- When the function swap() is called, the values of the
    variables a and b are exchanged because they are passed by reference.
- When you use pass-by-pointer, a copy of the pointer is passed to the function.
    If you modify the pointer inside the called function,
    you only modify the copy of the pointer, but the original pointer remains unmodified
    and still points to the original variable.
-The difference between pass-by-pointer and pass-by-value is that modifications
    made to arguments passed in by pointer in the called function have effect
    in the calling function, whereas modifications made to arguments passed in by value in the
    called function can not affect the calling function. Use pass-by-pointer if you want
    to modify the argument value in the calling function.
    Otherwise, use pass-by-value to pass arguments.
    */