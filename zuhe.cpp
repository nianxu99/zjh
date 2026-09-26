#include <bits/stdc++.h>
using namespace std;
class TriangleQuestion
{
private:
    int id;
    double a, b, c;
    string rightAns;
    string userAns;
public:
    TriangleQuestion(int id, double x, double y,double z)
    {
        this->id =id;
        this->a = x;
        this->b = y;
        this->c = z;
        RightAnswer();
    }
    void RightAnswer()
    {
        if(!isLegal())
            rightAns = "三角形不合法";
        else{
            rightAns = "类型:"+getType()+"\n周长:"+to_string(getPerimeter())+"\n面积:"+to_string(getArea());
        }
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
    void setUserAnswer(string ans)
    {
        userAns = ans;
    }
    int getId()
    {
        return id;
    }
    string getRightAnswer()
    {
        return rightAns;
    }
    string getUserAnswer()
    {
        return userAns;
    }
    double getA()
    {
        return a;
    }
    double getB()
    {
        return b;
    }
    double getC()
    {
        return c;
    }
    void setSide(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
        RightAnswer();
    }
    void showQuestion()
    {
        cout << "题目ID:" << id << endl;
        cout << "三角形三边：a=" << a << "  b=" << b << "  c=" << c << endl;
        cout << "正确答案:" << rightAns << endl;
        cout << "用户答案:" << userAns << endl;
    }
};
class QuestionBank
{
    private:
        string bankName;
        int count;
        vector<TriangleQuestion> quesList;
        double totalScore;
        double avgScore;
    public:
    QuestionBank(string name)
    {
        bankName = name;
        count = 0;
        totalScore = 0;
        avgScore = 0;
    }
    bool addQuestion(TriangleQuestion q)
    {
        if(count >= 100){
            cout << "题库已满！" << endl;
           return false; 
        }
        quesList[count++] = q;
        return true;
    }
    bool delQuestion(int delId)
    {
        int pos = -1;
        for(int i=0; i<count; i++){
            if(quesList[i].getId() == delId){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            cout << "找不到该编号题目！" << endl;
            return false;
        }
        for(int i=pos; i<count-1; i++){
            quesList[i] = quesList[i+1];
        }
        count--;
        return true;
    }
    void searchQuestion(int findId)
    {
        for(int i=0; i<count; i++){
            if(quesList[i].getId() == findId){
                quesList[i].showQuestion();
                return;
            }
        }
        cout << "没有找到这道题" << endl;
    }
    void inputUserAnswer(int qid,string ans)
    {
        for(int i=0; i<count; i++){
            if(quesList[i].getId() == qid){
                quesList[i].setUserAnswer(ans);
                return;
            }
        }
    }
    void setTotalScore(double s)
    {
        totalScore = s;
        if(count > 0) avgScore = totalScore / count;
    }
    void showBankInfo()
    {
        cout << "题库名称:" << bankName << endl;
        cout << "题目数量:" << count << endl;
        cout << "平均分:" << avgScore << endl;
        for(int i=0; i<count; i++){
            quesList[i].showQuestion();
        }
    }
};
int main (){
    QuestionBank bank("三角形几何题库");
    TriangleQuestion q1(1, 3, 4, 5);
    TriangleQuestion q2(2, 2, 2, 2);
    bank.addQuestion(q1);
    bank.addQuestion(q2);
    bank.inputUserAnswer(1, "类型:直角三角形\n周长:12.000000\n面积:6.000000");
    bank.inputUserAnswer(2, "类型:等边三角形\n周长:6.000000\n面积:1.732051");
    bank.setTotalScore(100);
    bank.showBankInfo();
    cout << "\n查询题目ID为1的题目：" << endl;
    bank.searchQuestion(1);
    cout << "\n删除题目ID为2的题目：" << endl;
    bank.delQuestion(2);
    bank.showBankInfo();
    return 0;
}