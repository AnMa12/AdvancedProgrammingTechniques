#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

struct Interval
{
    int strt, end;
};

int main()
{
    int n;

    vector<pair<int, int> > v;
    priority_queue<int,vector<int>,greater<int> > q;
    cin >> n;

    int start[n];
    int end[n];

    for(int j=0; j<n; j++)
        cin >> start[j];

    for(int j=0; j<n; j++)
    {
        cin >> end[j];
        end[j] = end[j] + start[j];
    }

    for(int j =0; j<n; j++)
        v.push_back(make_pair(start[j], end[j]));

    sort(v.begin(), v.end());
    q.push(v[0].second);
    int count = 1;

    for(int j =1; j<n; j++)
    {
        if(v[j].first<q.top())
            count++;
        else
            q.pop();
        q.push(v[j].second);
    }

    cout << count << endl ;


return 0;
}
