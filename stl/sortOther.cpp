// Sort one array according to other (using pairs)
#include <bits/stdc++.h>
using namespace std;

void sortChar(int a[], char b[], int n)
{
    pair<int, char> pa[n];

    for(int i=0;i<n;i++)
     pa[i] = {a[i], b[i]};

    sort(pa, pa+n);

    for(int i=0;i<n;i++)
     cout<<pa[i].second<<" ";
}

int main()
{
    int a[] = {10,9,1,8,2};
    char b[] = {'A', 'Z', 'f', 'K', 'L'};

    sortChar(a,b,5);

    return 0;
}
