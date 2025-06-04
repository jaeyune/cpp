#ifndef TIME_HMS_H
#define TIME_HMS_H

#include <iostream>
#include <iomanip>
using namespace std;

class TimeHMS {
    int hour, min, sec;

    void normalize();

public:
    TimeHMS(int h = 0, int m = 0, int s = 0);

    TimeHMS operator+(const TimeHMS& t) const;
    TimeHMS operator-(const TimeHMS& t) const;
    bool operator==(const TimeHMS& t) const;

    TimeHMS& operator++();    // 전위 증가
    TimeHMS operator++(int);  // 후위 증가
    TimeHMS& operator--();    // 전위 감소
    TimeHMS operator--(int);  // 후위 감소

    int operator[](int idx) const;

    operator int() const;
    operator double() const;

    TimeHMS operator*(int k) const;

    friend ostream& operator<<(ostream& os, const TimeHMS& t);
    friend istream& operator>>(istream& is, TimeHMS& t);
};

#endif
