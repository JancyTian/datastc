#include <bits/stdc++.h>
using namespace std;

template <typename ElemType>
class LinkedList
{
public:
    struct ListNode
    {                    // 单链表的结点类型
        ElemType data_;  // 存储数据
        ListNode *next_; // 线性表中下一个元素的位置
    };
    using Position = ListNode *; // 指针即结点位置
    struct ListException         // 异常处理
    {
        std::string error_;
        explicit ListException(std::string s) : error_(std::move(std::move(s))) {};
    };
    LinkedList(); // 构造函数，初始化一个空的线性表
    LinkedList(const LinkedList &);
    LinkedList &operator=(const LinkedList &);
    ~LinkedList();                           // 析构函数,释放线性表占用的空间
    [[nodiscard]] int Length() const;        // 返回线性表中的元素个数，即表的长度
    [[nodiscard]] ElemType Get(int i) const; // 返回线性表中第i个元素的值
    void Insert(int i, ElemType x);          // 在线性表第i个位置上插入元素x
    void Remove(int i);                      // 从线性表中删除第i个元素
    void K_Reverse(int k);
    // 重载友元函数，用于输出链表内容
    template <typename T>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list);
    // 重载友元函数，用于从输入流读取数据到链表
    template <typename T>
    friend std::istream &operator>>(std::istream &is, LinkedList<T> &list);

private:
    Position head_; // 单链表头指针,指向空头结点
    Position tail_; // 额外添加尾指针
    int length_;    // 表长
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    LinkedList<int> mylist;
    int n, d;
    std::cin >> mylist;
    int k;
    std::cin >> k;
    try
    {
        mylist.K_Reverse(k);
        cout << mylist << endl;
    }
    catch (...)
    {
        cout << -10 << endl;
    }
    return 0;
}
#define p Position

void LinkedList<ElemType>::K_Reverse(int k)
{
    p preend = head_;
    p tmp = preend->next_;
    p first = tmp;
    p x = tmp->next_;
    int complete = length_ / k;
    int left = length_ % k;
    for (int i = 0; i < complete; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            x->next_ = tmp;
            tmp = x;
            x = x->next_;
        }
        first->next_ = x;
        preend->next_ = tmp;
        preend = tmp;
    }
    for (int j = 0; j < left; ++j)
    {
        x->next_ = tmp;
        tmp = x;
        x = x->next_;
    }
    first->next_ = x;
    preend->next_ = tmp;
    preend = tmp;
}