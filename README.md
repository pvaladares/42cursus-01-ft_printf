# 42cursus-00-ft_printf
Development repo for 42cursus' ft_printf project


# Man

<details>
  
<summary>STDARG(3)
</summary>

```man
STDARG(3)                BSD Library Functions Manual                STDARG(3)

NAME
     stdarg -- variable argument lists

SYNOPSIS
     #include <stdarg.h>

     void
     va_start(va_list ap, last);

     type
     va_arg(va_list ap, type);

     void
     va_copy(va_list dest, va_list src);

     void
     va_end(va_list ap);

DESCRIPTION
     A function may be called with a varying number of arguments of varying types.  The include file <stdarg.h> declares a type (va_list)
     and defines three macros for stepping through a list of arguments whose number and types are not known to the called function.

     The called function must declare an object of type va_list which is used by the macros va_start(), va_arg(), va_copy(), and
     va_end().

     The va_start() macro must be called first, and it initializes ap, which can be passed to va_arg() for each argument to be processed.
     Calling va_end() signals that there are no further arguments, and causes ap to be invalidated.  Note that each call to va_start()
     must be matched by a call to va_end(), from within the same function.

     The parameter last is the name of the last parameter before the variable argument list, i.e., the last parameter of which the call-
     ing function knows the type.

     Because the address of this parameter is used in the va_start() macro, it should not be declared as a register variable, or as a
     function or an array type.

     The va_arg() macro expands to an expression that has the type and value of the next argument in the call.  The parameter ap is the
     va_list ap initialized by va_start().  Each call to va_arg() modifies ap so that the next call returns the next argument.  The
     parameter type is a type name specified so that the type of a pointer to an object that has the specified type can be obtained sim-
     ply by adding a * to type.

     If there is no next argument, or if type is not compatible with the type of the actual next argument (as promoted according to the
     default argument promotions), random errors will occur.

     The first use of the va_arg() macro after that of the va_start() macro returns the argument after last.  Successive invocations
     return the values of the remaining arguments.

     The va_copy() macro copies the state of the variable argument list, src, previously initialized by va_start(), to the variable argu-
     ment list, dest, which must not have been previously initialized by va_start(), without an intervening call to va_end().  The state
     preserved in dest is equivalent to calling va_start() and va_arg() on dest in the same way as was used on src.  The copied variable
     argument list can subsequently be passed to va_arg(), and must finally be passed to va_end() when through with it.

     After a variable argument list is invalidated by va_end(), it can be reinitialized with va_start() or made a copy of another vari-
     able argument list with va_copy().
     
EXAMPLES
     The function foo takes a string of format characters and prints out the argument associated with each format character based on the
     type.

           void foo(char *fmt, ...)
           {
                   va_list ap, ap2;
                   int d;
                   char c, *s;

                   va_start(ap, fmt);
                   va_copy(ap2, ap);
                   while (*fmt)
                           switch(*fmt++) {
                           case 's':                       /* string */
                                   s = va_arg(ap, char *);
                                   printf("string %s\n", s);
                                   break;
                           case 'd':                       /* int */
                                   d = va_arg(ap, int);
                                   printf("int %d\n", d);
                                   break;
                           case 'c':                       /* char */
                                   /* Note: char is promoted to int. */
                                   c = va_arg(ap, int);
                                   printf("char %c\n", c);
                                   break;
                           }
                   va_end(ap);
                   ...
                   /* use ap2 to iterate over the arguments again */
                   ...
                   va_end(ap2);
           }

COMPATIBILITY
     These macros are not compatible with the historic macros they replace.  A backward compatible version can be found in the include
     file <varargs.h>.

STANDARDS
     The va_start(), va_arg(), va_copy(), and va_end() macros conform to ISO/IEC 9899:1999 (``ISO C99'').

BUGS
     Unlike the varargs macros, the stdarg macros do not permit programmers to code a function with no fixed arguments.  This problem
     generates work mainly when converting varargs code to stdarg code, but it also creates difficulties for variadic functions that wish
     to pass all of their arguments on to a function that takes a va_list argument, such as vfprintf(3).

BSD                            October 25, 2002                            BSD
```
</details>

  
  
# Resources
