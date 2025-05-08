#include <iostream>
#include <cstring>
using namespace std;

class Sample {
    char* name;
    static int count;  // 정적 변수: Sample 객체 수

public:
    // 기본 생성자
    Sample() {
        name = nullptr;
        count++;
    }

    // 문자열을 인자로 받는 생성자
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }

    // 복사 생성자 (깊은 복사)
    Sample(const Sample& other) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
        count++;
    }

    // 소멸자
    ~Sample() {
        delete[] name;
        count--;
    }

    // 정적 함수: 객체 수 출력
    static void printCount() {
        cout << "Sample 객체 수: " << count << endl;
    }

    // 객체 이름 출력 함수
    void printName() const {
        if (name)
            cout << "이름: " << name << endl;
        else
            cout << "이름 없음" << endl;
    }
};

// 정적 변수 정의
int Sample::count = 0;

// 메인 함수
int main() {
    Sample a("sample");
    Sample::printCount();  // 1
    a.printName();         // sample

    Sample b(a);
    Sample::printCount();  // 2
    b.printName();         // sample

    return 0;
}
