// Wordpair.h
#ifndef WORDPAIR_H
#define WORDPAIR_H

#include <string>

struct WordPair {
    std::string eng;
    std::string kor;

    WordPair() {}
    WordPair(std::string e, std::string k) : eng(e), kor(k) {}
};

#endif
