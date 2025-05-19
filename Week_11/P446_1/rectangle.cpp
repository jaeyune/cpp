#include <iostream>
using namespace std;

// Point 클래스 정의
class Point 
{
protected:
    int x, y;
public:
    Point(int xx, int yy) : x(xx), y(yy) { }

    void draw() 
    {
        cout << x << "," << y << "에 점을 그려라.\n";
    }
};

// Rectangle 클래스 정의 (Point 상속)
class Rectangle : public Point 
{
private:
    int width, height;
public:
    // 생성자: 멤버 초기화 리스트 사용
    Rectangle(int x1, int y1, int w, int h) : Point(x1, y1), width(w), height(h) { }

    // draw 함수 재정의
    void draw() 
    {
        cout << x << "," << y << "에 점을 그려라.\n";  // 원래 draw 내용 유지
        cout << width << " x " << height << " 사각형을 그려라.\n";
    }
};

int main() 
{
    Rectangle r(2, 3, 100, 200);
    r.draw();
    return 0;
}
