#include <iostream>
#include <string>

struct Node; // to be able to use abbreviation in line 5, note that it's just a declaration not a definition
using std::cout, std::cin, std::cerr;
using node_ptr = Node *;
namespace instructions
{
    std::string traverse = "traverse";
    std::string insert = "insert";
    std::string length = "length";
    std::string remove = "remove";
};
struct Node // actual definition of Node;
{
    int value;
    node_ptr left, right;
};

struct List
{
    size_t length;
    node_ptr start;
};

/*----------------Functions---------------------
 *Here you can find necessary methods(functions), yet simple, of using linked list.
 * I have tried my best so that pre-implemented functions, like make_node etc., be as simple as it can be.
 *
 * You should complete following functions:
 * insert
 * traverse
 */

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
    /*
     * This function will iterate through nodes in linked-list and
     * print their values
     */
}

void remove(struct List &list, int v)
{
    /*
     * Iterate through linked list:
     * removes all nodes which has value == v then removes it
     */
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

void insert(struct List &list, int value = 0)
{
    /*
     * Here you are instructed to implement insert function, which
     * traverses through the list and insert the value into the list.
     * This insertion should keep the list sorted, ascending.
     */
}

void deallocate(struct List &list)
{
    /*
     * It's important to release all the resources you have allocated
     * through the program. By calling this function, it traverses the linked list and
     * deallocates memory
     */
    node_ptr cur = list.start;
    while (cur)
    {
        node_ptr tmp = cur;
        cur = tmp->right;
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
