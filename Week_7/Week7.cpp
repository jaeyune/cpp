//a = 1 + 2i, b = 3 + 4i, c = ?
#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }

    // [3] 멤버 함수 (void, 참조 전달)
    void add(const Complex& other, Complex& result) const {
        result.real = real + other.real;
        result.imag = imag + other.imag;
    }

    // [4] 멤버 함수 (return, 참조 전달)
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // [5] 연산자 오버로딩
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

// [1] 일반 함수 (void, 참조 전달)
void add(const Complex& a, const Complex& b, Complex& result) {
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
}

// [2] 일반 함수 (return, 값 전달)
Complex add(Complex a, Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c;

    cout << "a = "; a.print();
    cout << "b = "; b.print();

    cout << "----- 덧셈 결과 -----" << endl;

    // [1] 일반 함수 (void, 참조 전달)
    add(a, b, c);
    cout << "[1] 일반 함수 (void, 참조): ";
    c.print();

    // [2] 일반 함수 (return, 값 전달)
    c = add(a, b);
    cout << "[2] 일반 함수 (return, 값): ";
    c.print();

    // [3] 멤버 함수 (void, 참조 전달)
    a.add(b, c);
    cout << "[3] 멤버 함수 (void, 참조): ";
    c.print();

    // [4] 멤버 함수 (return, 참조 전달)
    c = a.add(b);
    cout << "[4] 멤버 함수 (return, 참조): ";
    c.print();

    // [5] 연산자 오버로딩
    c = a + b;
    cout << "[5] 연산자 오버로딩: ";
    c.print();

    return 0;
}
