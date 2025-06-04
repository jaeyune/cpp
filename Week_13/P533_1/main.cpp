#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 45), t3;

    t3 = t1 + t2;
    cout << "t1 + t2 = " << t3 << endl;

    t3 = t2 - t1;
    cout << "t2 - t1 = " << t3 << endl;

    cout << "t1 == t1 ? " << (t1 == t1 ? "true" : "false") << endl;

    cout << "++t1 = " << ++t1 << endl;
    cout << "--t1 = " << --t1 << endl;

    cout << "t1++ = " << t1++ << endl;
    cout << "t1-- = " << t1-- << endl;

    cout << "t1[0] = " << t1[0] << ", t1[1] = " << t1[1] << ", t1[2] = " << t1[2] << endl;

    cout << "int(t1) = " << int(t1) << "초" << endl;
    cout << "double(t1) = " << double(t1) << "시간" << endl;

    cout << "t1 * 2 = " << (t1 * 2) << endl;

    TimeHMS t_input;
    cout << "시간을 입력하세요 (hh:mm:ss): ";
    cin >> t_input;
    cout << "입력된 시간: " << t_input << endl;

    return 0;
}
