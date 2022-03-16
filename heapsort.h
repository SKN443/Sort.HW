#include <iostream>
#include <algorithm>

using namespace std;

typedef double db;

void heapsort(int n, db a[]) {
    make_heap(a, a+n);
    sort_heap(a, a+n);
}
