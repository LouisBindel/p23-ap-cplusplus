#include "stack.h"
#include <stdexcept>
#include <iostream>

int main()
{
    stack s1(5);
    s1.push('l');
    s1.push('o');
    s1.push('u');
    s1.push('i');
    s1.push('s');
    s1.print();
    stack s2(23);
    s2 = s1;
    s2.pop();
    s2.print();
    try
    {
        stack s4(-1);
    }
    catch (const char *e)
    {
        std::cout << "catched !" << '\n';
    }
}
