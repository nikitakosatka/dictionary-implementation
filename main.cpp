#include <iostream>
#include "dictionary/UnorderedDictionary.h"

using namespace std;

int main() {
    UnorderedDictionary<string, int> dict;

    dict.set("Ten", 10);
    dict.set("One", 1);

    cout << "Ten is in dict: " << dict.is_set("Ten") << endl;
    cout << "Two is in dict: " << dict.is_set("Two") << endl;
    cout << "Get One: " << dict.get("One") << endl;
//    cout << "Get Two: " << dict.get("Two") << endl;

    dict.remove("Ten");
    cout << "Ten is in dict: " << dict.is_set("Ten") << endl;


    return 0;
}