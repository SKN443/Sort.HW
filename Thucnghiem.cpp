#include <stdio.h>
#include <time.h>
#include <iomanip>
#include "QS.h"
#include "csort.h"
#include "heapsort.h"
#include "Mergesort.h"

#define For(i, a, b) for(int i = a; i <= b; i++)
#define Fod(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef double db;

const int N = 1e6 + 1e3;

int n;
db a[N], tmerge[10], tqs[10], tcsort[10], theap[10], b[N];

bool Check(db a[]) {
    for(int i = 0; i+1 < n; i++)
        if (a[i] > a[i+1]) return 0;
    return 1;
}

void Sort(int t) {
    clock_t Start, End;
    ///Quicksort
    For(i, 0, n-1) b[i] = a[i];
    Start = clock();
    Quicksort(b, 0, n-1);
    End = clock();
    if (!Check(b)) exit(0);

    tqs[t] = (db)(End-Start)/CLOCKS_PER_SEC*1000;

    ///csort
    For(i, 0, n-1) b[i] = a[i];
    Start = clock();
    Sortc(n, b);
    End = clock();
    if (!Check(b)) exit(0);

    tcsort[t] = (db)(End-Start)/CLOCKS_PER_SEC*1000;

    ///heapsort
    For(i, 0, n-1) b[i] = a[i];
    Start = clock();
    heapsort(n, b);
    End = clock();
    if (!Check(b)) exit(0);

    theap[t] = (db)(End-Start)/CLOCKS_PER_SEC*1000;

    ///Mergesort
    For(i, 0, n-1) b[i] = a[i];
    Start = clock();
    Mergesort(b, 0, n-1);
    End = clock();
    if (!Check(b)) exit(0);

    tmerge[t] = (db)(End-Start)/CLOCKS_PER_SEC*1000;
}

void Print() {
    int w = 12;
    cout <<setw(w) <<"Test case" <<setw(w) <<"Quicksort" <<setw(w) <<"Mergesort" <<setw(w) <<"Heapsort" <<setw(w) <<"stdSort" <<'\n';
    For(i, 0, 9) {
        cout <<setw(w) <<i+1 <<setw(w) <<tqs[i] <<setw(w) <<tmerge[i] <<setw(w) <<theap[i] <<setw(w) <<tcsort[i] <<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);

    For(t, 0, 9) {
        cin >>n;
        For(i, 0, n-1) cin >>a[i];
        Sort(t);
    }

    Print();
}
