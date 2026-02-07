#include <bits/stdc++.h>
using namespace std;
typedef struct Node *ptr;
struct Node
{
    char data;
    ptr left;
    ptr right;
};
void create(int n, vector<ptr> &tree)
{

    for (int i = 0; i < n; i++)
    {
        tree[i] = new (struct Node);
        char l = 0;
        char r = 0;
        cin >> tree[i]->data >> l >> r;
        if (l != '-')
        {
            tree[i]->left = tree[l - '0'];
        }
        else
        {
            tree[i]->left = nullptr;
        }
        if (r != '-')
        {
            tree[i]->right = tree[r - '0'];
        }
        else
        {
            tree[i]->right = nullptr;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<ptr> tree1(n);
    vector<ptr> tree2(n);

    create(n, tree1);
    int m;
    cin >> m;
    create(m, tree2);
    if (n != m)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        auto it = find_if(tree2.begin(), tree2.end(), [=](ptr tmp)
                          { return tmp->data == tree1[i]->data; });
        // cout << (*it)->data << tree1[i]->data << endl;
        if (it == tree2.end())
        {
            cout << "No" << endl;
            return 0;
        }
        int cnt = 0;
        if (tree1[i]->left != nullptr && tree1[i]->right != nullptr && (*it)->left != nullptr && (*it)->right != nullptr)
        {
            if (((*it)->left)->data == (tree1[i]->left)->data && ((*it)->right)->data == (tree1[i]->right)->data)
            {
                ++cnt;
            }
            else if (((*it)->left)->data == (tree1[i]->right)->data && ((*it)->right)->data == (tree1[i]->left)->data)
            {
                ++cnt;
            }
        }
        else if (tree1[i]->left == nullptr && tree1[i]->right == nullptr && (*it)->left == nullptr && (*it)->right == nullptr)
        {
            cnt++;
        }
        else if ((tree1[i]->left == nullptr && (*it)->right == nullptr) && (*it)->left != nullptr && tree1[i]->right != nullptr)
        {
            if (((*it)->left)->data == (tree1[i]->right)->data)
            {
                cnt++;
            }
        }
        else if ((tree1[i]->right == nullptr && (*it)->left == nullptr) && (*it)->right != nullptr && tree1[i]->left != nullptr)
        {
            if (((*it)->right)->data == (tree1[i]->left)->data)
            {
                cnt++;
            }
        }
        // cout << cnt << endl;
        if (cnt != 1)
        {

            cout << "No" << endl;
            // return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}