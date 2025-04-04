#include "linked_list.h"
#include <cassert>
#include <iostream>

void test_constructor()
{
    LinkedList<int> list;
    assert(list.is_empty());
    assert(list.size() == 0);
    std::cout << "test_constructor passed" << std::endl;
}

void test_push_front()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;
    list.push_front(&a);
    list.push_front(&b);
    list.push_front(&c);
    assert(*list.front() == 30);
    assert(*list.back() == 10);
    assert(list.size() == 3);
    std::cout << "test_push_front passed" << std::endl;
}

void test_push_back()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;
    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);
    assert(*list.front() == 10);
    assert(*list.back() == 30);
    assert(list.size() == 3);
    std::cout << "test_push_back passed" << std::endl;
}

void test_pop_front()
{
    LinkedList<int> list;
    int a = 10, b = 20;
    list.push_front(&a);
    list.push_front(&b);
    assert(*list.pop_front() == 20);
    assert(*list.pop_front() == 10);
    assert(list.is_empty());
    std::cout << "test_pop_front passed" << std::endl;
}

void test_pop_back()
{
    LinkedList<int> list;
    int a = 10, b = 20;
    list.push_back(&a);
    list.push_back(&b);
    assert(*list.pop_back() == 20);
    assert(*list.pop_back() == 10);
    assert(list.is_empty());
    std::cout << "test_pop_back passed" << std::endl;
}

void test_operator_index()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;
    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);
    assert(*list[0] == 10);
    assert(*list[1] == 20);
    assert(*list[2] == 30);
    try
    {
        list[3];
        assert(false);
    }
    catch (const std::runtime_error &)
    {
        assert(true);
    }
    std::cout << "test_operator_index passed" << std::endl;
}

void test_contains()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;
    list.push_back(&a);
    list.push_back(&b);
    assert(list.contains(&a));
    assert(list.contains(&b));
    assert(!list.contains(&c));
    std::cout << "test_contains passed" << std::endl;
}

void test_remove()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;
    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);
    list.remove(&b);
    assert(!list.contains(&b));
    assert(list.size() == 2);
    list.remove(&a);
    assert(!list.contains(&a));
    assert(list.size() == 1);
    std::cout << "test_remove passed" << std::endl;
}

void test_clear()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;
    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);
    list.clear();
    assert(list.is_empty());
    assert(list.size() == 0);
    std::cout << "test_clear passed" << std::endl;
}

void test_insert_at()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30, d = 40, e = 50, f = 60;

    list.push_back(&a);
    list.push_back(&c);
    list.push_back(&e);

    list.insert_at(0, &b);
    assert(*list[0] == b);

    list.insert_at(2, &d);
    assert(*list[2] == d);

    list.insert_at(4, &a);
    assert(*list[4] == a);

    assert(list.size() == 6);
    std::cout << "test_insert_at passed" << std::endl;
}

void test_remove_at()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30, d = 40;

    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);
    list.push_back(&d);

    assert(*list.remove_at(1) == b);
    assert(list.size() == 3);

    assert(*list.remove_at(0) == a);
    assert(list.size() == 2);

    assert(*list.remove_at(1) == d);
    assert(list.size() == 1);

    assert(*list.remove_at(0) == c);
    assert(list.is_empty());

    std::cout << "test_remove_at passed" << std::endl;
}

void test_stress()
{
    LinkedList<int> list;
    int values[1000];
    for (int i = 0; i < 1000; i++)
    {
        values[i] = i;
        list.push_back(&values[i]);
    }
    assert(list.size() == 1000);
    for (int i = 0; i < 500; i++)
    {
        list.remove_at(0);
    }
    assert(list.size() == 500);
    list.clear();
    assert(list.is_empty());
    std::cout << "test_stress passed" << std::endl;
}

int main()
{
    test_constructor();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_operator_index();
    test_contains();
    test_remove();
    test_clear();
    test_insert_at();
    test_remove_at();
    test_stress();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
