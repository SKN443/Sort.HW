#include <iostream>
#include <algorithm>

using namespace std;

typedef double db;

void Quicksort(db a[], int l, int r) {
    if (l == r) return;
    db x = a[(r+l)>>1];
    int L = l, R = r;
    while(L < R) {
        while (a[L] < x) L++;
        while (a[R] > x) R--;
        if (L < R) swap(a[L], a[R]);
    }

    int vt;
    for(int i = l; i <= r; i++)
    if (a[i] == x) {
        vt = i;
        break;
    }

    if (vt-1 > l) Quicksort(a, l, vt-1);
    if (r > vt+1) Quicksort(a, vt+1, r);
}
