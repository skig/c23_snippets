#include <stdio.h>

/* C23 added two nice directives: elifdef and elifndef */
#ifdef FOO
#elifdef  BAR /* C23 elifdef  is equivalent to #elif defined()*/
#elifndef BAR /* C23 elifndef is equivalent to #elif !defined()*/
#endif

/* C23 introduced constexpr, but it can only be used for scalars. It can't be used for functions */
constexpr unsigned int foo = 0b01100110; /* C23 binary integer constant */

/* C23 typeof allows to declare an object with a type of another object */
typeof(foo) bar = 1'000'000; /* C23 digit separator improves readability */

int func_foo(void)
{
    return foo;
}

int main(void) {
    /* C23 added type inference using auto keyword */
    auto func_foo_ret = func_foo();

    switch(func_foo_ret)
    {
        case 0b01100110:
            /* C23 allows declaring variables after a label.
               It wasn't allowed in older versions of standard which was annoying */
            int a = bar;
            printf("%d\n", a);
            break;
        default:
            break;
    }

    return 0;
}