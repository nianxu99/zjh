#ifndef SHAPEBANK_HPP
#define SHAPEBANK_HPP
#include <bits/stdc++.h>
using namespace std;
// 抽象类Shape，定义了计算面积和周长的接口
class Shape {
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual string getQuesStr() = 0;
    virtual ~Shape() {} //虚析构函数，确保派生类对象被正确销毁
};
// 派生类Triangle，继承自Shape，实现了计算三角形面积和周长的功能
class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }  // 构造函数，初始化三边长
    double getArea() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double getPerimeter() override {
        return a + b + c;
    }
    string getQuesStr() override {
        return "[三角形]三边长a= " + to_string(a) + ", b= " + to_string(b) + ", c= " + to_string(c);
    }
};
// 派生类Circle，继承自Shape，实现了计算圆形面积和周长的功能
class Circle : public Shape {
private:
    double r;
public:
    Circle(double r) {
        this->r = r;
    }
    double getArea() override {
        return 3.14 * r * r;
    }
    double getPerimeter() override {
        return 2 * 3.14 * r;
    }
    string getQuesStr() override {
        return "[圆形]半径= " + to_string(r);
    }
};
// 派生类Square，继承自Shape，实现了计算正方形面积和周长的功能
class Square : public Shape {
private:
    double a;
public:
    Square(double a) {
        this->a = a;
    }
    double getArea() override {
        return a * a;
    }
    double getPerimeter() override {
        return 4 * a;
    }
    string getQuesStr() override {
        return "[正方形]边长= " + to_string(a);
    }
};
// 派生类Rectangle，继承自Shape，实现了计算长方形面积和周长的功能
class Rectangle : public Shape {
private:
    double a, b;
public:
    Rectangle(double a, double b) {
        this->a = a;
        this->b = b;
    }
    double getArea() override {
        return a * b;   
    }
    double getPerimeter() override {
        return 2 * (a + b);
    }
    string getQuesStr() override {
        return "[长方形]长= " + to_string(a) + ", 宽= " + to_string(b);
    }
};
// 派生类Trapezoid，继承自Shape，实现了计算梯形面积和周长的功能
class Trapezoid : public Shape {
private:
    double a, b, h;
public:
    Trapezoid(double a, double b, double h) {
        this->a = a;
        this->b = b;
        this->h = h;
    }
    double getArea() override {
        return (a + b) * h / 2.0;
    }
    double getPerimeter() override {
        return a + b + 2 * sqrt(pow((b - a) / 2.0, 2) + h * h);
    }
    string getQuesStr() override {
        return "[梯形]上底= " + to_string(a) + ", 下底= " + to_string(b) + ", 高= " + to_string(h);
    }
};
#endif