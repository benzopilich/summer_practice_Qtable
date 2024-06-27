#include <QString>
#include <QTextStream>
using namespace std;
class Tab1
{
private:

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
};
