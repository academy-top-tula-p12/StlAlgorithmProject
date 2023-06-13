#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

auto print = [](auto const remark, auto const& v)
{
    std::cout << remark;
    for (auto n : v)
        std::cout << n << ' ';
    std::cout << '\n';
};


void SortHeap(std::vector<int>& v)
{
    auto it = v.end();
    while (v.begin() != it)
    {
        std::make_heap(v.begin(), it);
        std::pop_heap(v.begin(), it--);
        //it++;
    }
}



int main()
{
    srand(time(nullptr));

    int size{ 10 };
    std::vector<int> v1;

    for (int i = 0; i < size; i++)
        v1.push_back(rand() % 100);

    std::for_each(v1.begin(), v1.end(), [](auto item) 
        { 
            std::cout << item << " ";
        });
    std::cout << "\n";
    
    std::cout << std::boolalpha << std::all_of(v1.begin(), v1.end(), [](auto item) 
        {
            return item > 10;
        }) << "\n";
    std::cout << std::boolalpha << std::any_of(v1.begin(), v1.end(), [](auto item)
        {
            return item < 10;
        }) << "\n";

    std::cout << std::count(v1.begin(), v1.end(), 5) << "\n";
    std::cout << std::count_if(v1.begin(), v1.end(), [](auto item) 
        {
            return item % 2 == 0;
        }) << "\n";


    std::vector<int> v2 { 1, 2, 3, 4, 5, 6, 7 };
    std::list<int> l2 { 1, 2 };

    auto result = std::mismatch(v2.begin(), v2.begin() + 1, l2.begin());
    std::cout << *result.first << " " << *result.second << "\n";

    auto it = std::find(v1.begin(), v1.end(), 90);
    if (it != v1.end())
        std::cout << *it << "\n";

    it = std::find_if_not(v1.begin(), v1.end(), [](auto item) 
        {
            return item > 20;
        });
    if (it != v1.end())
        std::cout << *it << "\n";

    //auto it2 = std::find_end(v2.begin(), v2.end(), l2.begin(), l2.end());
    auto it2 = std::search(v2.begin(), v2.end(), l2.begin(), l2.end());
    std::cout << std::distance(v2.begin(), it2) << "\n";

    std::vector<int> v3(6);

    std::for_each(v2.begin(), v2.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";

    std::move(v2.begin(), v2.begin() + 5, v3.begin());

    std::for_each(v3.begin(), v3.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";
    std::for_each(v2.begin(), v2.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";

    std::vector<int> v4(5);
    std::fill(v4.begin(), v4.begin() + 3, 10);
    std::for_each(v4.begin(), v4.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";

    std::transform(v2.begin(), v2.end(), v2.begin(), [](auto item)
        {
            return item * item;
        });
    std::for_each(v2.begin(), v2.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";

    std::vector<int> v5(10);
    std::generate(v5.begin(), v5.end(), []() { return rand() % 100; });
    std::for_each(v5.begin(), v5.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";

    std::vector<int> v {2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
    print("before sort:\t\t", v);

    // insertion sort
    for (auto i = v.begin(); i != v.end(); ++i)
        std::rotate(std::upper_bound(v.begin(), i, *i), i, i + 1);
    print("after sort:\t\t", v);

    // simple rotation to the left
    std::rotate(v.begin(), v.begin() + 3, v.end());
    print("simple rotate left:\t", v);

    // simple rotation to the right
    std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
    print("simple rotate right:\t", v);

    std::vector<int> v6 { 1, 8, 10, 4, 7, 6, 5, 2, 9, 3 };
    
    std::for_each(v6.begin(), v6.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";

    //auto it6 = std::partition(v6.begin(), v6.end(), [](auto item) { return item < 5; });

    SortHeap(v6);
    std::for_each(v6.begin(), v6.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    //std::cout << "\n" << *it6 << "\n";
    
}
