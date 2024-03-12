#include <iostream>
#include "Member.h"
#include "Polinom.h"


int main()
{
    Polinom a(4, 1);
    a.add(Member(5, 2));
    a.add(Member(3, 0));
    Polinom b(1, 0);
    b.add(Member(2, 1));

    Polinom c;
    c = a.diff();

    cout << a.calc(2);
}
