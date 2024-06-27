#include <QString>
#include <QTextStream>
using namespace std;
class Tab1
{
public:
    QString Month;
    int Day;
    Tab1():Day(0){Month=nullptr;}
    Tab1(QString M,int D)
    {
        Month=M;
        Day=D;
    }
    friend QTextStream& operator >>(QTextStream& in,Tab1& obj)
    {
        obj.Month=in.readLine();
        in>>obj.Day;
        in.readLine();
        return in;
    }
    friend QTextStream& operator <<(QTextStream& out,Tab1& obj)
    {
        out<<obj.Month<<"\n"<<obj.Day<<"\n";
        return out;
    }
};

class Tab2
{
public:
    QString Name;
    double Cost;
    int Year;
    Tab2():Cost(0.0), Year(0){Name=nullptr;}
    Tab2(QString N, double C,int Y)
    {
        Name=N;
        Cost=C;
        Year=Y;
    }
    friend QTextStream& operator >>(QTextStream& in,Tab2& obj)
    {
        obj.Name=in.readLine();
        in>>obj.Cost;
        in>>obj.Year;
        in.readLine();
        return in;
    }
};
