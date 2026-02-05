#include <bits/stdc++.h>
using namespace std;
typedef struct Node *ptr;
struct Node
{
    int data;
    ptr left;
    ptr right;
};

ptr createTree(int n)
{
    if (n <= 0)
    {
        return nullptr;
    }
    ptr root = new struct Node;
    ptr child1 = new struct Node;
    ptr child2 = new struct Node;
    child2->left = nullptr;
    child2->right = nullptr;
    child1->left = nullptr;
    child1->right = nullptr;
    root->left = child1;
    root->right = child2;
    cin >> child1->data >> child2->data >> root->data;
    return root;
}

void forerec(ptr root)
{
    if (root != nullptr)
    {
        cout << root->data << endl;
        forerec(root->left);
        forerec(root->right);
    }
}

void midrec(ptr root)
{
    if (root != nullptr)
    {
        midrec(root->left);
        cout << root->data << endl;
        midrec(root->right);
    }
}
void backrec(ptr root)
{
    if (root != nullptr)
    {
        backrec(root->left);
        backrec(root->right);
        cout << root->data << endl;
    }
}
void midstack(ptr root)
{
    stack<ptr> stk;
    ptr current = root;
    while (current != nullptr || !stk.empty())
    {
        while (current)
        {
            stk.push(current);
            current = current->left;
        }
        current = stk.top();
        stk.pop();
        cout << current->data << endl;
        current = current->right;
    }
}
void forestack(ptr root)
{
    ptr current = root;
    stack<ptr> stk;
    while (current != nullptr || !stk.empty())
    {
        while (current)
        {
            stk.push(current);
            cout << current->data << endl;
            current = current->left;
        }
        current = stk.top();
        stk.pop();
        current = current->right;
    }
}
void backstack(ptr root)
{
    stack<ptr> stk;
    ptr current = root;
    ptr prev = nullptr;
    while (!stk.empty() || current != nullptr)
    {
        while (current != nullptr)
        {
            stk.push(current);
            current = current->left;
        }
        ptr top = stk.top(); // 引入top
        if (top->right == nullptr || top->right == prev)
        {
            cout << top->data << endl;
            stk.pop();
            prev = top;
        }
        else
        {
            current = top->right;
        }
    }
}
int main()
{
    auto tree = createTree(3);
    backstack(tree);
    return 0;
}