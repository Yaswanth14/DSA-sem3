#include <bits/stdc++.h>
using namespace std;

int mycmp(pair <int,int> p1, pair<int,int> p2)
{
    return p1.second>p2.second;
}

void printSortedByMarks(int roll[], int marks[], int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
        v.push_back({roll[i], marks[i]});
    
    sort(v.begin(), v.end(), mycmp);

    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second;
        cout<<endl;
    }

}

int main()
{
    int roll[] = {105,108,112,145};
    int marks[] = {90,20,80,45};

    printSortedByMarks(roll, marks, 4);

    return 0;
}

