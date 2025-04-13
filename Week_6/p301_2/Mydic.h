// Mydic.h
#ifndef MYDIC_H
#define MYDIC_H

#include <string>
#include "Wordpair.h"

const int MAXWORDS = 100;

class MyDic {
    WordPair words[MAXWORDS]; // 단어 저장 배열
    int nWords;               // 현재 저장된 단어 수

public:
    MyDic();  // 생성자

    void add(std::string eng, std::string kor);
    void load(std::string filename);
    void store(std::string filename);
    void print() const;
    std::string getEng(int id) const;
    std::string getKor(int id) const;
};

#endif