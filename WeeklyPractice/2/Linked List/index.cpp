#include <iostream>
#include <string>

struct Node;
using std::cout, std::cin, std::cerr;
using node_ptr = Node *;
namespace instructions
{
    std::string traverse = "traverse";
    std::string insert = "insert";
    std::string length = "length";
    std::string remove = "remove";
};

struct Node
{
    int value;
    node_ptr left, right;
};

struct List
{
    size_t length;
    node_ptr start;
};

node_ptr make_node(int value = 0, node_ptr left = nullptr, node_ptr right = nullptr)
{
    Node *tmp = new Node();
    tmp->right = right;
    tmp->left = left;
    tmp->value = value;
    return tmp;
}

void traverse(const struct List &list)
{
    if (!list.start)
    {
        cout << "The list is empty\n";
        return;
    }

    node_ptr cur = list.start;
    while (cur)
    {
        cout << cur->value;
        if (cur->right)
            cout << " ";
        cur = cur->right;
    }
    cout << "\n";
}

void insert(struct List &list, int value)
{
    node_ptr new_node = make_node(value);

    if (!list.start)
    {
        list.start = new_node;
        list.length = 1;
        return;
    }

    node_ptr cur = list.start;

    if (value < cur->value)
    {
        new_node->right = cur;
        cur->left = new_node;
        list.start = new_node;
        ++list.length;
        return;
    }

    while (cur->right && cur->right->value < value)
    {
        cur = cur->right;
    }

    new_node->right = cur->right;
    new_node->left = cur;

    if (cur->right)
        cur->right->left = new_node;

    cur->right = new_node;
    ++list.length;
}

void remove(struct List &list, int v)
{
    node_ptr cur = list.start;
    if (!cur)
        return;
    while (cur && cur->value == v)
    {
        node_ptr tmp = cur;
        cur = tmp->right;
        delete tmp;
        --list.length;
    }
    if (cur != list.start)
    {
        list.start = cur;
        if (cur)
            cur->left = nullptr;
        return;
    }
    while (cur && cur->value != v)
        cur = cur->right;
    node_ptr left_node = cur ? cur->left : nullptr;
    while (cur && cur->value == v)
    {
        node_ptr tmp = cur;
        cur = tmp->right;
        delete tmp;
        --list.length;
    }
    node_ptr right_node = cur;
    if (left_node)
        left_node->right = right_node;
    if (right_node)
        right_node->left = left_node;
}

void deallocate(struct List &list)
{
    node_ptr cur = list.start;
    while (cur)
    {
        node_ptr tmp = cur;
        cur = cur->right;
        delete tmp;
    }
    list.length = 0;
    list.start = nullptr;
}

int main()
{
    List list{0, nullptr};

    std::string instruction;
    int value;

    while (cin >> instruction)
    {
        if (instruction == instructions::traverse)
        {
            traverse(list);
        }
        else if (instruction == instructions::length)
        {
            cout << list.length << std::endl;
        }
        else
        {
            cin >> value;
            instruction == instructions::insert ? insert(list, value) : remove(list, value);
        }
    }
    deallocate(list);
}
