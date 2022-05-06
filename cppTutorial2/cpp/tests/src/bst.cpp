#include <cppTutorial2>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    std::shared_ptr<Tree<int>> bst = std::make_shared<BinarySearchTree<int>>();

    bst->insert(12);
    bst->insert(4);
    bst->insert(20);
    bst->insert(1);
    bst->insert(7);
    bst->insert(23);
    bst->insert(6);
    bst->insert(5);

    bst->traversal();
    cout << endl;

    bst->remove(12);

    bst->traversal();
    cout << endl;

    std::shared_ptr<Tree<Person>> bstPerson = std::make_shared<BinarySearchTree<Person>>();

    bstPerson->insert(Person("A", 27));
    bstPerson->insert(Person("K", 13));
    bstPerson->insert(Person("J", 67));
    bstPerson->insert(Person("M", 2));
    bstPerson->insert(Person("S", 11));

    bstPerson->traversal();
    cout << endl;

    return 0;
}