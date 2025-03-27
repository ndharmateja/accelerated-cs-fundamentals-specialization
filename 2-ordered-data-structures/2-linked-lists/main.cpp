#include <iostream>
#include <cassert>
#include "linked_list.h"

// Test structure to use with LinkedList<T*>
struct TestStruct
{
    int val;
    TestStruct(int v) : val(v) {}
    bool operator==(const TestStruct &other) const { return val == other.val; }
};

// Helper function to print pass/fail results
void assert_test(bool condition, const std::string &test_name)
{
    if (condition)
    {
        std::cout << "[PASS] " << test_name << "\n";
    }
    else
    {
        std::cerr << "[FAIL] " << test_name << "\n";
        std::exit(EXIT_FAILURE);
    }
}

void test_push_front()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;

    list.push_front(&a);
    assert_test(list.front() == &a, "Push front 1");

    list.push_front(&b);
    assert_test(list.front() == &b, "Push front 2");

    list.push_front(&c);
    assert_test(list.front() == &c, "Push front 3");

    assert_test(list.size() == 3, "Push front size check");
}

void test_push_back()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;

    list.push_back(&a);
    assert_test(list.back() == &a, "Push back 1");

    list.push_back(&b);
    assert_test(list.back() == &b, "Push back 2");

    list.push_back(&c);
    assert_test(list.back() == &c, "Push back 3");

    assert_test(list.size() == 3, "Push back size check");
}

void test_pop_front()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;

    list.push_front(&a);
    list.push_front(&b);
    list.push_front(&c);

    assert_test(list.pop_front() == &c, "Pop front 1");
    assert_test(list.pop_front() == &b, "Pop front 2");
    assert_test(list.pop_front() == &a, "Pop front 3");
    assert_test(list.is_empty(), "Pop front empty check");
}

void test_pop_back()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;

    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);

    assert_test(list.pop_back() == &c, "Pop back 1");
    assert_test(list.pop_back() == &b, "Pop back 2");
    assert_test(list.pop_back() == &a, "Pop back 3");
    assert_test(list.is_empty(), "Pop back empty check");
}

void test_contains()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30, d = 40;

    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);

    assert_test(list.contains(&a), "Contains a");
    assert_test(list.contains(&b), "Contains b");
    assert_test(list.contains(&c), "Contains c");
    assert_test(!list.contains(&d), "Does not contain d");
}

void test_remove()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;

    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);

    list.remove(&b);
    assert_test(!list.contains(&b), "Remove middle element");
    assert_test(list.size() == 2, "Size after remove");

    list.remove(&a);
    assert_test(!list.contains(&a), "Remove first element");

    list.remove(&c);
    assert_test(list.is_empty(), "Remove last element (empty check)");
}

void test_clear()
{
    LinkedList<int> list;
    int a = 10, b = 20, c = 30;

    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);

    list.clear();
    assert_test(list.is_empty(), "Clear list check");
}

void test_memory_safety()
{
    LinkedList<TestStruct> list;
    for (int i = 0; i < 1000; ++i)
    {
        list.push_back(new TestStruct(i));
    }

    for (int i = 0; i < 1000; ++i)
    {
        delete list.pop_front();
    }

    assert_test(list.is_empty(), "Memory safety test (all nodes deleted)");
}

void test_stress()
{
    LinkedList<int> list;
    int values[10000];

    for (int i = 0; i < 10000; i++)
    {
        values[i] = i;
        list.push_back(&values[i]);
    }

    assert_test(list.size() == 10000, "Stress test size");

    for (int i = 0; i < 5000; i++)
    {
        list.pop_front();
    }

    assert_test(list.size() == 5000, "Stress test after pops");
}

int main()
{
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_contains();
    test_remove();
    test_clear();
    test_memory_safety();
    test_stress();

    std::cout << "\n✅ All tests passed successfully!\n";
    return 0;
}
