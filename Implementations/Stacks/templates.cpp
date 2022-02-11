#include<bits/stdc++.h>
using namespace std;
template <typename T>

class Pair
{
    T x;
    T y;
    public:
    void setx(T x)
    {
        this->x = x;
    }
    void sety(T y)
    {
        this->y = y;
    }

    T getx()
    {
        return x;
    }
    T gety()
    {
        return y;
    }
};

//if we need two different datatypes
template<typename A,typename B>

class pair2
{
    A x;
    B y;
    public:
        void setx(A x)
        {
            this->x = x;
        }
        void sety(B y)
        {
            this->y = y;
        }

        A getx()
        {
            return x;
        }
        B gety()
        {
            return y;
        }
};

int main()
{
        // freopen("i.txt", "r", stdin);
        // freopen("o.txt", "w", stdout);

        Pair<int> p1;
        p1.setx(5);
        p1.sety(6);

        cout << p1.getx() << " " << p1.gety() << endl;

        Pair<double> p2;
        p2.setx(7.9);
        p2.sety(6.3);

        cout << p2.getx() << " " << p2.gety() << endl;
//==================================================================
        pair2<int, double> po;
        po.setx(199);
        po.sety(32.1);

        cout << po.getx() << " " << po.gety() << endl;
//==================================================================
        pair2<pair2<int, int>, int> p3;

        p3.sety(55);
        pair2<int, int> p4;
        p4.setx(11);
        p4.sety(22);
        p3.setx(p4);

        cout << p3.getx().getx() << " " << p3.getx().gety() << " " << p3.gety() << endl;
}
