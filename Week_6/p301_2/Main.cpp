// Main.cpp
#include <iostream>
#include "Mydic.h"

using namespace std;

int main() {
    MyDic myDictionary;

    myDictionary.add("apple", "사과");
    myDictionary.add("banana", "바나나");
    myDictionary.add("cherry", "체리");

    cout << "현재 등록된 단어들:" << endl;
    myDictionary.print();

    myDictionary.store("words.txt");

    MyDic newDictionary;
    newDictionary.load("words.txt");

    cout << "\n파일에서 다시 불러온 단어들:" << endl;
    newDictionary.print();

    return 0;
}