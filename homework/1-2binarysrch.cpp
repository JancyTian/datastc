#include <iostream>
#include <vector>
using namespace std;
#define NotFound -1

typedef int ElemSet;
typedef int Position;

Position BinarySearch(const vector<ElemSet> &array, ElemSet x);

int main()
{
    int n;
    ElemSet x;

    cin >> n;
    vector<ElemSet> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cin >> x;
    cout << BinarySearch(array, x) << endl;
    return 0;
}
/* 你的代码将被嵌在这里 */

Position BinarySearch(const vector<ElemSet> &array, ElemSet x)
{
    int size = (int)array.size();
    int left = 0;
    int right = size - 1;
    for (int i = 0; left <= right; ++i)
    {
        int mid = (left + right) / 2;
        if (array[mid] == x)
        {
            return mid;
        }

        if (array[mid] > x)
        {
            right = mid - 1;
        }

        if (array[mid] < x)
        {
            left = mid + 1;
        }
    }

    return -1;
}
