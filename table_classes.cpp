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


class Tab1_help
{
public:
    vector<Tab1> T1;
    friend QTextStream& operator >>(QTextStream& in, Tab1_help& obj)
    {
        Tab1 t;
        while(!in.atEnd())
        {
            in>>t;
            obj.T1.push_back(t);
        }
        return in;
    }
    friend QTextStream& operator <<(QTextStream& out,Tab1_help& obj)
    {
        for(int i=0; i<obj.T1.size(); i++)
        {
            out<<obj.T1[i];
        }
        return out;
    }
    mySort()
    {
        sort(T1.begin(),T1.end(),[&](const Tab1& t1,const Tab1& t2){
            return t1.Month<t2.Month;
        });
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
    friend QTextStream& operator <<(QTextStream& out,Tab2& obj)
    {
        out<<obj.Name<<"\n"<<obj.Cost<<" "<<obj.Year<<"\n";
        return out;
    }
};

class Tab2_help
{
public:
    vector<Tab2> T2;
    friend QTextStream& operator >>(QTextStream& in, Tab2_help& obj)
    {
        Tab2 t;
        while(!in.atEnd())
        {
            in>>t;
            obj.T2.push_back(t);
        }
        return in;
    }
    friend QTextStream& operator <<(QTextStream& out,Tab2_help& obj)
    {
        for(int i=0; i<obj.T2.size(); i++)
        {
            out<<obj.T2[i];
        }
        return out;
    }
    mySort()
    {
        sort(T2.begin(),T2.end(),[&](const Tab2& t1,const Tab2& t2){
            return t1.Name<t2.Name;
        });
    }
};
