#include "ShapeBank.hpp"
#include <bits/stdc++.h>
#define NOGDI
#include <windows.h>
using namespace std;
// Question类，表示一道题目，包括题目形状、正确答案、用户答案和是否正确的标志
class Question{
public:
    Shape* shape;
    double ansArea, ansPerimeter;
    double userArea, userPerimeter;
    bool isCorrect;
    Question(Shape* shape) {
        this->shape = shape;
        ansArea = shape->getArea();
        ansPerimeter = shape->getPerimeter();
        userArea = 0;
        userPerimeter = 0;
        isCorrect = false;
    }
    ~Question() {
        delete shape;
    }
    void showQuestion() {  // 显示题目并获取用户答案
        cout << shape->getQuesStr() << endl;
        cout << "请输入你算出的面积和周长的答案：" << endl;
        cin >>userArea >> userPerimeter;
        if (abs(userArea - ansArea) < 0.1 && abs(userPerimeter - ansPerimeter) < 0.1) {
            isCorrect = true;
            cout << "恭喜你，回答正确！" << endl;
        } else {
            isCorrect = false;
            cout << "很遗憾，回答错误！" << endl;
            cout << "正确答案为：面积= " << ansArea << ", 周长= " << ansPerimeter << endl;
        }
    }
    void review(){
        cout << shape->getQuesStr() << endl;
        cout << "你的答案：面积= " << userArea << ", 周长= " << userPerimeter << endl;
        cout << "正确答案：面积= " << ansArea << ", 周长= " << ansPerimeter << endl;
        if (isCorrect) {
            cout << "你回答正确！" << endl;
        } else {
            cout << "你回答错误！" << endl;
        }
    }
};
// ShapeBank类，表示题库，包括题目列表和总分
class ShapeBank {
private:
    vector<Question*> questions;// 题目列表
    int totalScore;// 总分
public:
    ShapeBank() {totalScore = 0;}
    ~ShapeBank() {
        for (auto q : questions) {
            delete q;
        }
    }
    void createRandomQuestions(){   // 随机生成一道题目
        int type = rand() % 5;
        Shape* s = nullptr;
        double val;
        switch (type) {  // 根据随机类型创建不同形状的题目
            case 0: {
                double a = rand() % 10 + 1;
                double b = rand() % 10 + 1;
                double c = rand() % 10 + 1;
                s = new Triangle(a, b, c);
                break;
            }
            case 1:
                val = rand() % 10 + 1;
                s = new Circle(val);
                break;
            case 2:
                val = rand() % 10 + 1;
                s = new Square(val);
                break;
            case 3: {
                double a = rand() % 10 + 1;
                double b = rand() % 10 + 1;
                s = new Rectangle(a, b);
                break;
            }
            case 4: {
                double a1 = rand() % 10 + 1;
                double b1 = rand() % 10 + 1;
                double h = rand() % 10 + 1;
                s = new Trapezoid(a1, b1, h);
                break;
            }
            case 5: {
                double a = rand() % 10 + 1;
                double b = rand() % 10 + 1;
                s = new Ellipse(a, b);
                break;
            }
        }
        Question* q = new Question(s);// 创建题目对象并加入题目列表
        questions.push_back(q);
    }
    void startExam(int num){
        cout << "答题开始！请回答以下问题：" << endl;
        for (int i = 0; i < num; i++) {
            cout << "第" << i + 1 << "题：" << endl;
            createRandomQuestions();
            questions.back()->showQuestion();
            if (questions.back()->isCorrect) {
                totalScore += 10;
            }
        }
        cout << "答题结束！你的总分为：" << totalScore << endl;
    }
    void reviewExam(){
        cout << "答题回顾：" << endl;
        for (int i = 0; i < questions.size(); i++) {
            cout << "第" << i + 1 << "题：" << endl;
            questions[i]->review();
        }
    }
};
int  main(){
    SetConsoleOutputCP(65001); 
    srand(time(0));
    ShapeBank bank;
    int num;
    cout << "请输入你想要答题的题目数量：" << endl;
    cin >> num;
    bank.startExam(num);
    bank.reviewExam();
    return 0;
}