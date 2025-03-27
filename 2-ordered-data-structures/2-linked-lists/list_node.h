template <typename T>
class ListNode
{
public:
    T *data_;
    ListNode<T> *next_;
    ListNode(T *data, ListNode<T> *next = nullptr);
};

template <typename T>
ListNode<T>::ListNode(T *data, ListNode *next) : data_(data), next_(next) {}