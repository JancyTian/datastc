#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    int n;

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    ll maxsum = 0;
    ll thissum = 0;
    int fir = -1, last = -1, temp = 0;

    for (int i = 0; i < n; i++)
    {
        thissum += a[i];

        if (thissum < 0)
        {
            thissum = 0;
            temp = i + 1;
        }

        if (thissum > maxsum)
        {
            maxsum = thissum;
            last = i;
            fir = temp;
        }
    }

    cout << maxsum << endl;
    cout << fir << " " << last << endl;
}