#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1;
    cin >> num1;
    map<int, int, greater<int>> poly1;
    for (int i = 0; i < num1; i++)
    {
        int ex;
        int value;
        cin >> value >> ex;
        poly1[ex] = value;
    }
    int num2;
    cin >> num2;
    map<int, int, greater<int>> poly2;
    for (int i = 0; i < num2; i++)
    {
        int ex;
        int value;
        cin >> value >> ex;
        poly2[ex] = value;
    }
    map<int, int, greater<int>> result;
    auto it1 = poly1.begin();
    auto it2 = poly2.begin();
    for (const auto &pair1 : poly1)
    {
        for (const auto &pair2 : poly2)
        {
            int tmpfirst = pair1.first + pair2.first;
            int tmpsecond = pair1.second * pair2.second;
            auto it = result.find(tmpfirst);
            if (it == result.end())
            {
                result[tmpfirst] = tmpsecond;
            }
            else
            {
                it->second += tmpsecond;
                if (it->second == 0)
                {
                    result.erase(it);
                }
            }
        }
    }
    bool is_first = true;
    for (const auto &pair : result)
    {
        if (!is_first)
        {
            cout << " ";
        }
        cout << pair.second << " " << pair.first;
        is_first = false;
    }
    cout << endl;
    return 0;
}