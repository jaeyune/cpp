#include "TimeHMS.h"

void TimeHMS::normalize() {
    int totalSec = hour * 3600 + min * 60 + sec;
    if (totalSec < 0) totalSec = 0;
    hour = totalSec / 3600;
    min = (totalSec % 3600) / 60;
    sec = totalSec % 60;
}

TimeHMS::TimeHMS(int h, int m, int s) : hour(h), min(m), sec(s) {
    normalize();
}

TimeHMS TimeHMS::operator+(const TimeHMS& t) const {
    return TimeHMS(hour + t.hour, min + t.min, sec + t.sec);
}

TimeHMS TimeHMS::operator-(const TimeHMS& t) const {
    int totalSec = int(*this) - int(t);
    return TimeHMS(0, 0, totalSec);
}

bool TimeHMS::operator==(const TimeHMS& t) const {
    return hour == t.hour && min == t.min && sec == t.sec;
}

TimeHMS& TimeHMS::operator++() {
    sec++;
    normalize();
    return *this;
}

TimeHMS TimeHMS::operator++(int) {
    TimeHMS temp = *this;
    ++(*this);
    return temp;
}

TimeHMS& TimeHMS::operator--() {
    sec--;
    normalize();
    return *this;
}

TimeHMS TimeHMS::operator--(int) {
    TimeHMS temp = *this;
    --(*this);
    return temp;
}

int TimeHMS::operator[](int idx) const {
    if (idx == 0) return hour;
    if (idx == 1) return min;
    if (idx == 2) return sec;
    throw out_of_range("Invalid index");
}

TimeHMS::operator int() const {
    return hour * 3600 + min * 60 + sec;
}

TimeHMS::operator double() const {
    return hour + min / 60.0 + sec / 3600.0;
}

TimeHMS TimeHMS::operator*(int k) const {
    return TimeHMS(0, 0, int(*this) * k);
}

ostream& operator<<(ostream& os, const TimeHMS& t) {
    os << setfill('0') << setw(2) << t.hour << ":"
       << setw(2) << t.min << ":" << setw(2) << t.sec;
    return os;
}

istream& operator>>(istream& is, TimeHMS& t) {
    char ch;
    is >> t.hour >> ch >> t.min >> ch >> t.sec;
    t.normalize();
    return is;
}
