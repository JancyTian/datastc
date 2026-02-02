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
    int sum = 0;
    int current = 0;
    int left = -1;
    int right = -1;
    for (int i = 0; i < n; i++)
    {
        current = a[i];
        for (int j = i + 1; j < n; j++)
        {
            current = current + a[j];
            if (current > sum)
            {
                sum = current;
                left = i;
                right = j;
            }
        }
    }

    cout << sum << endl;
    cout << left << " " << right << endl;
}
