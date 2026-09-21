#include<bits\stdc++.h>
using namespace std;
class Triangle
{
private:
    double a, b, c;
public:
    Triangle(double x = 0, double y = 0, double z = 0)
    {
        a = x;
        b = y;
        c = z;
    }
    void setSide(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
    }
    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }
    void show()
    {
        cout << "三角形三边：a=" << a << "  b=" << b << "  c=" << c << endl;
    }
    bool isLegal()
    {
        if(a>0 && b>0 && c>0
           && (a+b>c) && (a+c>b) && (b+c>a))
            return true;
        else
            return false;
    }
    double getPerimeter()
    {
        if(!isLegal())
            return 0;
        return a + b + c;
    }
    double getArea()
    {
        if(!isLegal())
            return 0;
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p-a) * (p-b) * (p-c));
    }

    string getType()
    {
        if(!isLegal())
            return "三角形不合法";
        if(a == b && b == c)
            return "等边三角形";
        else if(a==b || b==c || a==c)
            return "等腰三角形";
        else if((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))
            return "直角三角形";
        else
            return "普通三角形";
    }
};
