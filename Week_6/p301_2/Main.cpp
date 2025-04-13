// Main.cpp
#include <iostream>
#include "Mydic.h"
using namespace std;

int main() {
    // 단어장 객체 생성
    MyDic myDictionary;

    // 단어 추가
    myDictionary.add("apple", "사과");
    myDictionary.add("banana", "바나나");
    myDictionary.add("cherry", "체리");

    // 단어 출력
    cout << "현재 등록된 단어들:\n";
    myDictionary.print();

    // 파일로 저장
    myDictionary.store("words.txt");

    // 새로운 객체로 파일에서 다시 불러오기
    MyDic newDictionary;
    newDictionary.load("words.txt");

    // 불러온 단어 출력
    cout << "\n파일에서 다시 불러온 단어들:\n";
    newDictionary.print();

    return 0;
}