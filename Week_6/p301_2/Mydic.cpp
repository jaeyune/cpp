// Mydic.cpp
#include "Mydic.h"
#include <iostream>
#include <fstream>

using namespace std;

MyDic::MyDic() {
    nWords = 0;
}

void MyDic::add(string eng, string kor) {
    if (nWords < MAXWORDS) {
        words[nWords] = WordPair(eng, kor);
        nWords++;
    }
}

void MyDic::load(string filename) {
    ifstream fin(filename);
    string eng, kor;
    nWords = 0;
    while (fin >> eng >> kor) {
        add(eng, kor);
    }
    fin.close();
}

void MyDic::store(string filename) {
    ofstream fout(filename);
    for (int i = 0; i < nWords; i++) {
        fout << words[i].eng << " " << words[i].kor << endl;
    }
    fout.close();
}

void MyDic::print() const {
    for (int i = 0; i < nWords; i++) {
        cout << i << ": " << words[i].eng << " - " << words[i].kor << endl;
    }
}

string MyDic::getEng(int id) const {
    if (id >= 0 && id < nWords)
        return words[id].eng;
    return "";
}

string MyDic::getKor(int id) const {
    if (id >= 0 && id < nWords)
        return words[id].kor;
    return "";
}