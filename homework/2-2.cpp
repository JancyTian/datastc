#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1;
    cin >> num1;
    map<int, float, greater<int>> poly1;
    for (int i = 0; i < num1; i++)
    {
        int ex;
        float value;
        cin >> value >> ex;
        poly1[ex] = value;
    }
    int num2;
    cin >> num2;
    map<int, float, greater<int>> poly2;
    for (int i = 0; i < num2; i++)
    {
        int ex;
        float value;
        cin >> value >> ex;
        poly2[ex] = value;
    }
    map<int, float, greater<int>> result;
    auto it1 = poly1.begin();
    auto it2 = poly2.begin();
    while (it1 != poly1.end() && it2 != poly2.end())
    {
        if (it1->first > it2->first)
        {
            result[it1->first] = it1->second;
            it1++;
        }
        else if (it1->first == it2->first)
        {
            result[it1->first] = it1->second + it2->second;
            it1++;
            it2++;
        }
        else if (it1->first < it2->first)
        {
            result[it2->first] = it2->second;
            it2++;
        }
    }
    if (it1 != poly1.end())
    {
        while (it1 != poly1.end())
        {
            result[it1->first] = it1->second;
            it1++;
        }
    }
    else if (it2 != poly2.end())
    {
        while (it2 != poly2.end())
        {
            result[it2->first] = it2->second;
            it2++;
        }
    }
    cout << fixed << setprecision(2);
    for (const auto &pair : result)
    {
        cout << pair.second << " " << pair.first << endl;
    }
}