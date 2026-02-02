#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> findmax(const vector<int> &a, int left, int right);
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    auto result = findmax(a, 0, n - 1);

    cout << result[0] << endl;
    cout << result[1] << " " << result[2] << endl;
}

vector<int> findmax(const vector<int> &a, int left, int right)
{
    if (left == right)
    {
        vector<int> tmp = {a[left], left, right};
        return tmp;
    }

    int mid = (left + right) / 2;
    auto left_result = findmax(a, left, mid);
    auto right_result = findmax(a, mid + 1, right);

    int middle = 0;
    int left_sum_max = a[mid];
    int current_sum = a[mid];
    int left_index = mid;
    for (int i = mid - 1; i >= 0; --i)
    {
        current_sum += a[i];
        if (current_sum > left_sum_max)
        {
            left_sum_max = current_sum;
            left_index = i;
        }
    }
    int right_sum_max = a[mid + 1];
    current_sum = a[mid + 1];
    int right_index = mid + 1;
    for (int i = mid + 2; i < right; ++i)
    {
        current_sum += a[i];
        if (current_sum > right_sum_max)
        {
            right_sum_max = current_sum;
            right_index = i;
        }
    }

    middle = right_sum_max + left_sum_max;
    if (middle > left_result[0] && middle > right_result[0])
    {
        vector<int> tmp = {middle, left_index, right_index};
        return tmp;
    }
    else if (left_result[0] > right_result[0])
    {
        return left_result;
    }
    return right_result;
}