#include <cstdlib>
using namespace std;

int random_between(int l, int h)
{
    // make sure l is less than h
    if (h < l) {
        int temp = h;
        h = l;
        l = temp;
    }

    // compute random integer between l and h inclusive
    return l + rand() % (h - l + 1);
}
