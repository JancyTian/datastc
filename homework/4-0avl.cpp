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

int newheight(ptr root)
{
    if (root == nullptr)
    {
        root->height = 0;
        return 0;
    }
    root->height = 1 + max(newheight(root->left), newheight(root->right));
    return root->height;
}

int offset(ptr root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr)
    {
        return -root->right->height;
    }
    if (root->right == nullptr)
    {
        return root->left->height;
    }
    return root->left->height - root->right->height;
}
ptr ll(ptr root)
{
    ptr tmp = root->left;
    ptr root0 = new (struct Node);
    root0->left = tmp->right;
    root0->right = root->right;
    root0->data = root->data;
    root->data = tmp->data;
    root->right = root0;
    root->left = tmp->left;
    delete (tmp);
    return root;
}

ptr rr(ptr root)
{
    ptr tmp = root->right;
    ptr root0 = new (struct Node);
    root0->left = root->left;
    root0->right = tmp->left;
    root0->data = tmp->data;
    root->data = tmp->data;
    root->left = root0;
    root->right = tmp->right;
    delete (tmp);
    return root;
}
ptr adjust(ptr root)
{
    if (offset(root) == 2)
    {
        if (offset(root->left) == 1)
        {
            // ll
            ll(root);
        }
        else if (offset(root->left) == -1)
        {
            rr(root->left);
            ll(root);
            //
        }
        else
            root->left = adjust(root->left);
    }
    if (offset(root) == -2)
    {
        if (offset(root->right) == 1)
        {
            ll(root->right);
            rr(root);
            //
        }
        else if (offset(root->right) == -1)
        {
            rr(root);
            // rr
        }
        else
            root->right = adjust(root->right);
    }
    return root;
}

ptr add(ptr root, int x)
{
    if (root == nullptr)
    {
        root = new (struct Node);
        return root;
    }
    else if (root->data > x)
    {
        root->left = add(root->left, x);
    }
    else if (root->data < x)
    {
        root->right = add(root->right, x);
    }

    newheight(root);

    adjust(root);

    newheight(root);

    return root;
}
ptr findmax(ptr root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->right == nullptr)
    {
        return root;
    }
    return findmax(root->right);
}
ptr erase(ptr root, int x)
{
    if (root == nullptr)
    {
        return root;
    }
    if (x < root->data)
    {
        root->left = erase(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = erase(root->left, x);
    }
    else
    {
        if (root->right != nullptr && root->left != nullptr)
        {
            ptr tmp = findmax(root);
            root->data = tmp->data;
            erase(tmp, tmp->data);
        }
        else if (root->left == nullptr)
        {
            ptr tmp = root;
            root = root->right;
            delete (tmp);
        }
        else if (root->right == nullptr)
        {
            ptr tmp = root;
            root = root->left;
            delete (tmp);
        }
    }
    return root;
}