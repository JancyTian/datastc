#include <bits/stdc++.h>
using namespace std;
typedef struct Node *node;
struct Node
{
    char ch;
    int weight;
    node left;
    node right;
    Node() : ch('\0'), weight(0), left(nullptr), right(nullptr) {}
};

struct cmp
{
    bool operator()(const node &a, const node &b)
    {
        return a->weight > b->weight;
    }
};

node buildtree(priority_queue<node, vector<node>, cmp> &htree)
{
    do
    {
        node n1 = htree.top();
        htree.pop();
        node n2 = htree.top();
        htree.pop();
        node root = new (struct Node);
        root->weight = n1->weight + n2->weight;
        root->left = n1;
        root->right = n2;
        htree.push(root);
    } while (htree.size() >= 2);

    return htree.top();
}

void encode(node root, string code, map<string, char> &codemap)
{
    if (root->left != nullptr)
    {
        code = code + "0";
        encode(root->left, code, codemap);
    }
    if (root->right != nullptr)
    {
        code = code + "1";
        encode(root->right, code, codemap);
    }
    if (root->right == nullptr && root->left == nullptr)
    {
        codemap[code] = root->ch;
    }
}

int main()
{
    int n;
    cin >> n;
    priority_queue<node, vector<node>, cmp> htree;
    for (int i = 0; i < n; i++)
    {
        auto tmp = new (Node);
        cin >> tmp->ch >> tmp->weight;
        htree.push(tmp);
    }
    node root = buildtree(htree);
    map<string, char> codemap;
    encode(root, "", codemap);
    string x;
    cin >> x;
    string tmp = "";
    for (auto p : codemap)
    {
        cout << p.first << p.second << endl;
    }
    for (char c : x)
    {
        tmp += c;
        if (codemap.count(tmp))
        {
            cout << codemap[tmp];
            tmp = "";
        }
    }
}