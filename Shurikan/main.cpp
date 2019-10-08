#include <iostream>
#include <string>

#include "Shurikan.h"

using namespace Shurikan;

int main()
{

    auto p = Analyzing::IPerformanceWatch::create(Analyzing::Units::SEC);

    p->start();

    auto l1 = p->lap();
    auto l2 = p->lap();
    auto l3 = p->lap();

    p->reset();

    return 0;
}
