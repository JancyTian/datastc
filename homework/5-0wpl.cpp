#include <bits/stdc++.h>
using namespace std;
void createminheap(vector<int> &htree, int n)
{
    int i = n / 2;
    for (; i > 0; --i)
    {
        int tmp = htree[i];
        int parent, child;
        parent = i;
        while (parent * 2 <= n)
        {
            child = parent * 2;
            if (child + 1 <= n && htree[child + 1] < htree[child])
            {
                ++child;
            }
            if (tmp <= htree[child])
            {
                break;
            }
            else
            {
                htree[parent] = htree[child];
                parent = child;
            }
        }
        htree[parent] = tmp;
    }
}
int erase(vector<int> &htree)
{
    int tmp = htree.back();
    htree.pop_back();
    int parent, child;
    parent = 1;
    int popped = htree[1];
    while (parent * 2 <= htree.size() - 1)
    {
        child = parent * 2;
        if (child + 1 <= htree.size() - 1 && htree[child + 1] < htree[child])
        {
            ++child;
        }
        if (tmp <= htree[child])
        {
            break;
        }
        else
        {
            htree[parent] = htree[child];
            parent = child;
        }
    }
    htree[parent] = tmp;
    return popped;
}

void add(vector<int> &htree, int x)
{
    htree.push_back(x);
    int i = htree.size() - 1;
    while (true)
    {
        if (x < htree[i / 2])
        {
            htree[i] = htree[i / 2];
            i = i / 2;
        }
        else
        {
            break;
        }
    }
    htree[i] = x;
}

void createhufftree(vector<int> &htree)
{
    // for (auto &ele : htree)
    // {
    //     cout << ele << endl;
    // }
    while (htree.size() > 2)
    {
        int x1 = erase(htree);
        for (auto &ele : htree)
        {
            cout << ele << " ";
        }
        cout << endl;
        int x2 = erase(htree);
        for (auto &ele : htree)
        {
            cout << ele << " ";
        }
        cout << endl;
        int x3 = x1 + x2;
        add(htree, x3);
        for (auto &ele : htree)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << htree[1] << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> htree(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> htree[i + 1];
    }
    htree[0] = -1;
    createminheap(htree, n);
    createhufftree(htree);
    return 0;
}