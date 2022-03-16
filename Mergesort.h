#include <iostream>
#include <algorithm>

using namespace std;

typedef double db;

void Merge(db a[], const int &l, const int &r, const int &mid) {
    static vector<db> v((int)1e7);
    int i = l, j = mid+1, d = 0;
    while (i <= mid || j <= r) {
        if (i <= mid && j <= r) {
            if (a[i] <= a[j])
                v[d++] = a[i++];
            else if (a[j] <= a[i])
                v[d++] = a[j++];
        }
        else if (i <= mid)
            v[d++] = a[i++];
        else
            v[d++] = a[j++];
    }

    for(int id = 0; id < d; id++) a[id+l] = v[id];
//    cout <<"hi " <<l <<' ' <<r <<'\n';
//    for(int id = 0; id < d; id++) cout <<v[id] <<' '; cout <<'\n';
}

void Mergesort(db a[], int l, int r) {
//    cout <<l <<' ' <<r <<'\n';
//    for(int i = l; i <= r; i++) cout <<a[i] <<' '; cout <<'\n';
    if (l >= r) return;
    if (l+1 == r) {
        if (a[l] > a[r]) swap(a[l], a[r]);
        return;
    }

    int mid = (r+l) >>1;
    Mergesort(a, l, mid);
    Mergesort(a, mid+1, r);
    Merge(a, l, r, mid);
}

