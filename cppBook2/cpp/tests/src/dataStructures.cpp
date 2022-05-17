#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Dynamic Arrays
    int n = 5;
    int array[n]; // Old way to do it.
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    for (auto &x : v)
        cout << x << endl;

    // Kind of initialisation:
    vector<int> a(8);
    vector<int> b(8, 2);

    v = {2, 4, 2, 5, 1};
    cout << v.back() << endl;
    v.pop_back();
    cout << v.back() << endl;

    // Iterators

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(v.begin(), v.end(), default_random_engine(seed));

    cout << *v.begin() << endl;

    vector<int> v1 = {2, 3, 3, 5, 7, 8, 8, 8};
    vector<int>::iterator x = lower_bound(v1.begin(), v1.end(), 5);
    vector<int>::iterator y = upper_bound(v1.begin(), v1.end(), 5);

    cout << (x - v1.begin()) << endl;
    cout << (y - v1.begin()) << endl;

    // Contains unique elements from the original vector
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());

    // Deque, Stack & Queues
    deque<int> d;
    d.push_back(5);
    d.push_back(2);
    d.push_front(10);
    d.pop_back();
    d.pop_front();

    stack<int> s;
    s.push(2);
    s.push(5);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    queue<int> q;
    q.push(2);
    q.push(5);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;

    // Set structures.
    // set -> balance bst & order maintained
    // unordered_set hashmap & no order

    // Unique elements for both!

    set<int> t;
    t.insert(3);
    t.insert(2);
    t.insert(5);

    cout << t.count(3) << endl;
    cout << t.count(4) << endl;

    t.erase(3);
    t.insert(4);

    cout << t.count(3) << endl;
    cout << t.count(4) << endl;

    t.insert(5);
    t.insert(5);
    t.insert(5);

    cout << t.count(5) << " = 0 or = 1." << endl;
    cout << t.size() << endl;
    for (auto x : t)
        cout << x << endl;

    auto it = t.find(10);
    if (it == t.end())
        cout << 10 << " found!" << endl;
    else
        cout << 10 << " not found" << endl;

    auto first = t.begin();
    auto second = t.end();

    cout << *first << " minimum in the set - " << *second << " maximum in the set." << endl;

    cout << *t.lower_bound(6) << endl;
    cout << *t.upper_bound(6) << endl;

    // Multiset is like a vector but the order is always kept.
    multiset<int> t1;
    t1.insert(5);
    t1.insert(5);
    t1.insert(5);

    cout << t1.count(5) << " >=1" << endl;

    t1.erase(5);
    cout << t1.count(5) << " ==0 - because it erases all copies." << endl;
    // If we want to erase only one value:

    t1.insert(5);
    t1.insert(5);
    t1.insert(5);

    t1.erase(t1.find(5));
    cout << t1.count(5) << endl;

    // Maps
    // map -> balance bst & order maintained
    // unordered_map hashmap & no order

    // Key value pair for both!

    map<string, int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;

    cout << m["banana"] << endl;
    cout << m["aybabtu"] << " = 0 -> because the key does not exist then it put automatically the value 0." << endl;

    if (m.count("aybabtu"))
    {
        cout << "Doing stuff if the key exists." << endl;
    }

    // Walking through the values of the map:
    for (auto x : m)
        cout << x.first << " " << x.second << endl;

    // Priority queues
    // Priority queues can be seen as a multiset: heap bst.
    // By default pq is max heap.

    priority_queue<int> q1;
    q1.push(3);
    q1.push(2);
    q1.push(100);
    q1.push(1);
    q1.push(9);

    cout << q1.top() << endl;
    q1.pop();
    cout << q1.top() << endl;
    q1.pop();
    cout << q1.top() << endl;
    q1.pop();

    // If we want min heap:
    // priority_queue<int, vector<int>, greater<int>> q2;

    // Policy-Based Sets -> from g++ compiler, here we use clang.
    /*
    #include <ext/pb_ds/assoc_containers.hpp>
        using namespace __gnu_pbds;

        typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

        indexed_set s3;
        s3.insert(3);
        s3.insert(4);
        s3.insert(9);

        auto h = s3.find_by_order(2);
        cout << *h << endl;
        cout << s3.order_of_key(7) << endl;
        cout << s3.order_of_key(6) << endl;
        cout << s3.order_of_key(8) << endl;
        */

    // Experiments:
    // Set vs. Sorting:
    /*
        Get the unique values in the vector unordered_set << set << sort.
    */

    // Map vs. Array
    /*
        Retrieving values by key: map<<unordered_map<<array.
    */

    // Multiset vs. Priority Queue
    /*
        Retrieving the min element of a vector and adding a new element: multiset<<priority_queue.
    */

    return 0;
}