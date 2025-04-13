// Mydic.cpp
#include "Mydic.h"
#include <iostream>
#include <fstream>
using namespace std;

// 생성자: 단어 개수를 0으로 초기화
MyDic::MyDic() {
    nWords = 0;
}

// 영어 단어와 뜻을 단어장에 추가
void MyDic::add(string eng, string kor) {
    if (nWords < MAXWORDS) {
        words[nWords].eng = eng;
        words[nWords].kor = kor;
        nWords++;
    }
}

// 모든 단어를 화면에 출력
void MyDic::print() {
    for (int i = 0; i < nWords; i++) {
        cout << i << ": " << words[i].eng << " - " << words[i].kor << endl;
    }
}

// 특정 인덱스의 영어 단어 반환
string MyDic::getEng(int id) {
    if (id >= 0 && id < nWords)
        return words[id].eng;
    return "";
}

// 특정 인덱스의 한글 뜻 반환
string MyDic::getKor(int id) {
    if (id >= 0 && id < nWords)
        return words[id].kor;
    return "";
}

// 단어들을 파일에 저장 (한 줄에 영어 + 공백 + 한글)
void MyDic::store(string filename) {
    ofstream fout(filename);
    for (int i = 0; i < nWords; i++) {
        fout << words[i].eng << " " << words[i].kor << endl;
    }
    fout.close();
}

// 파일에서 단어들을 불러오기
void MyDic::load(string filename) {
    ifstream fin(filename);
    nWords = 0;
    while (fin >> words[nWords].eng >> words[nWords].kor) {
        nWords++;
    }
    fin.close();
}