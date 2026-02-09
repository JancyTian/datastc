#include <bits/stdc++.h>
using namespace std;
typedef struct Node *ptr;
struct Node
{
    int data;
    ptr left;
    ptr right;
    int height;
};

ptr insert2(ptr root, int x)
{
    if (root == nullptr)
    {
        root = new (struct Node);
        root->data = x;
        root->right = root->left = nullptr;
        return root;
    }
    if (x < root->data)
    {
        root->left = insert2(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = insert2(root->right, x);
    }
    return root;
}

bool sametree(ptr tree1, ptr tree2)
{
    if (tree1 == nullptr && tree2 == nullptr)
    {
        return true;
    }
    if (tree1 == nullptr && tree2 != nullptr || tree1 != nullptr && tree2 == nullptr)
    {
        return false;
    }
    if (tree1->data != tree2->data)
    {
        return false;
    }
    if (tree1->data == tree2->data)
    {
        return sametree(tree1->left, tree2->left) && sametree(tree1->right, tree2->right);
    }
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        int l;
        cin >> l;
        vector<ptr> tree(l + 1);
        for (int i = 0; i < l + 1; ++i)
        {
            tree[i] = nullptr;
            for (int j = 0; j < n; ++j)
            {
                int tmp;
                cin >> tmp;
                tree[i] = insert2(tree[i], tmp);
            }
        }
        int dif = true;
        for (int i = 0; i < l; i++)
        {
            if (!sametree(tree[0], tree[i + 1]))
            {
                dif = false;
            }
        }
        if (dif == true)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}