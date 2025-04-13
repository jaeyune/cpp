// Mydic.h
#pragma once
#include "Wordpair.h"
#include <string>
using namespace std;

const int MAXWORDS = 100; // 최대 100개 단어 저장

// 나만의 단어장을 나타내는 클래스
class MyDic {
    WordPair words[MAXWORDS]; // 단어쌍 배열
    int nWords;               // 현재 저장된 단어 수

public:
    MyDic(); // 생성자

    // 단어 추가
    void add(string eng, string kor);

    // 파일에서 단어 목록 불러오기
    void load(string filename);

    // 현재 단어 목록을 파일에 저장
    void store(string filename);

    // 전체 단어 목록 출력
    void print();

    // 특정 인덱스의 영어 단어 반환
    string getEng(int id);

    // 특정 인덱스의 한글 뜻 반환
    string getKor(int id);
};