#include <bits/stdc++.h>
using namespace std;
typedef struct Node *ptr;
struct Node
{
    char data;
    ptr left;
    ptr right;
};

ptr create(int n, vector<ptr> &tree)
{
    for (int i = 0; i < n; ++i)
    {
        tree[i] = new (struct Node);
    }
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
    {
        char l = 0;
        char r = 0;
        cin >> tree[i]->data >> l >> r;
        if (l != '-')
        {
            tree[i]->left = tree[l - '0'];
            ++parent[l - '0'];
        }
        else
        {
            tree[i]->left = nullptr;
        }
        if (r != '-')
        {
            tree[i]->right = tree[r - '0'];
            ++parent[r - '0'];
        }
        else
        {
            tree[i]->right = nullptr;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (parent[j] == 0)
        {
            return tree[j];
        }
    }
    return nullptr;
}
int judge(ptr root1, ptr root2)
{
    if ((root1 != nullptr && root2 == nullptr || root1 == nullptr && root2 != nullptr) || root1 != nullptr && root2 != nullptr && root1->data != root2->data)
    {
        return 0;
    }
    if (root1 == nullptr && root2 == nullptr)
    {
        return 1;
    }
    // 这些情况是不用递归，直接可以返回的（肯定不对；一定对（到底了））
    return (judge(root1->left, root2->left) && judge(root1->right, root2->right) || judge(root1->right, root2->left) && judge(root1->left, root2->right));
    // 这些情况是需要递归解决的：根节点相等，要判断他们的左孩子右孩子。用复杂的嵌套判断来return
}

int main()
{
    int n;
    cin >> n;
    vector<ptr> tree1(n);
    vector<ptr> tree2(n);

    ptr root1 = create(n, tree1);
    int m;
    cin >> m;
    ptr root2 = create(m, tree2);
    if (n != m)
    {
        cout << "No" << endl;
        return 0;
    }
    int k = judge(root1, root2);
    if (k == 0)
    {

        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}