#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> findmax(int n, vector<int> a);

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    auto result = findmax(n, a);

    cout << result[0] << endl;
    cout << result[1] << " " << result[2] << endl;
}

vector<int> findmax(int n, vector<int> a)
{
    vector<int> left(3), right(3);
    int middle = 0;
    int midp = n / 2;
    if (n > 1)
    {
        vector<int> b(a.begin(), a.begin() + midp);
        left = findmax(midp, b);
        vector<int> c(a.begin() + midp, a.end());
        right = findmax(n - midp, c);
    }

    if (n == 1)
    {
        vector<int> temp = {a[0], 0, 0};
        return temp;
    }

    int max_left_sum = a[midp - 1];
    int current_sum = a[midp - 1];
    int left_idx = midp - 1;

    for (int i = midp - 2; i >= 0; --i)
    {
        current_sum += a[i];
        if (current_sum > max_left_sum)
        {
            max_left_sum = current_sum;
            left_idx = i;
        }
    }

    int max_right_sum = a[midp];
    current_sum = a[midp];
    int right_idx = midp;
    for (int i = midp + 1; i < n; ++i)
    {
        current_sum += a[i];
        if (current_sum > max_right_sum)
        {
            max_right_sum = current_sum;
            right_idx = i;
        }
    }

    middle = max_left_sum + max_right_sum;
    if (middle > left[0] && middle > right[0])
    {
        vector<int> thi = {middle, left_idx, right_idx};
        return thi;
    }
    else if (left[0] > right[0])
    {
        return left;
    }
    return right;
}