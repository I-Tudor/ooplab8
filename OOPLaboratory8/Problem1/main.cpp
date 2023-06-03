#include "ListIterator.h"
#include "IteratedList.h"
#include "ListIterator.h"
#include <string>
#include <iostream>

int main() {
    IteratedList<int> intList;
    intList.addToEnd(1);
    intList.addToEnd(2);
    intList.addToEnd(3);
    for (ListIterator<int> it = intList.first(); it.valid(); it.next()) {
        std::cout << it.getCurrent() << " ";
    }
    std::cout << std::endl;

    // Example with strings
    IteratedList<std::string> strList;
    strList.addToEnd("apple");
    strList.addToEnd("banana");
    strList.addToEnd("cherry");
    for (ListIterator<std::string> it = strList.first(); it.valid(); it.next()) {
        std::cout << it.getCurrent() << " ";
    }
    std::cout << std::endl;

    // Example with doubles
    IteratedList<double> dblList;
    dblList.addToEnd(1.1);
    dblList.addToEnd(2.6);
    dblList.addToEnd(3.7);
    for (ListIterator<double> it = dblList.first(); it.valid(); it.next()) {
        std::cout << it.getCurrent() << " ";
    }
    std::cout << std::endl;

    return 0;
}