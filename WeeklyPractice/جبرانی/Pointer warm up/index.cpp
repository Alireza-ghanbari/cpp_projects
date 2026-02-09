#include <iostream>

void increment(int *value)
{
    if (value != nullptr)
    {
        *value = *value + 1;
    }
}

int main()
{
    int *pNumber = new int;
    *pNumber = 5;
    std::cout << *pNumber << std::endl;

    std::cout << *pNumber << std::endl;
    increment(pNumber);
    std::cout << *pNumber << std::endl;

    delete pNumber;
    pNumber = nullptr;

    int *pEmpty = nullptr;
    if (pEmpty != nullptr)
    {
        std::cout << *pEmpty << std::endl;
    }

    int *arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}