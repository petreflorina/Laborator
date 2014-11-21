#include<iostream>
#include <cstddef>

#include<stddef.h>

using namespace std;

struct Point
{
    int x,y;
};

int testDet(Point a, Point b, Point c)
{
    return ((b.x * c.y + a.x + b.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y));

}

Point intersection ( double x1,double y1,double x2,double y2, double x3, double y3, double x4,double y4 )
{
    Point err;
    err.x = NULL;
    err.y = NULL;

    double d = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);

    if (d == 0) return err;

    double xi = ((x3-x4)*(x1*y2-y1*x2)-(x1-x2)*(x3*y4-y3*x4))/d;
    double yi = ((y3-y4)*(x1*y2-y1*x2)-(y1-y2)*(x3*y4-y3*x4))/d;

    if(x3 == x4)
    {
        if ( yi < min(y1,y2) || yi > max(y1,y2) )return err;
    }
    Point p;

    p.x = xi;
    p.y = yi;

    if (xi < min(x1,x2) || xi > max(x1,x2)) return err;
    if (xi < min(x3,x4) || xi > max(x3,x4)) return err;

    return p;
}

float distanta(Point a, Point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}


int main()
{
    Point p1, p2, q1, q2, err;
    err.x = NULL;
    err.y = NULL;

    cout << "Dati coordonatele capetelor primului segment: \n";
    cout << "x: ";
    cin >> p1.x;
    cout << "y: ";
    cin >> p1.y;
    cout << "x: ";
    cin >> q1.x;
    cout << "y: ";
    cin >> q1.y;


    cout << "Dati coordonatele capetelor celui de-al 2-lea segment: \n";
    cout << "x: ";
    cin >> p2.x;
    cout << "y: ";
    cin >> p2.y;
    cout << "x: ";
    cin >> q2.x;
    cout << "y: ";
    cin >> q2.y;

    cout << "Orientarea este " << testDet(p1, p2, q1) << " si " << testDet(p1, p2, q2) << "\n";
    if (testDet(p1, p2, q1) ==0 && testDet(p1, p2, q2) == 0 )
    {
        ///a b c d
        if(distanta(p1, q1)+distanta(p2,q2) < (distanta(p1, q2)))
        {
            cout << "Nu se intersecteaza.\n";
            return 0;
        }
        else
            ///c d a b
            if(distanta(p1, q1)+distanta(p2,q2) < (distanta(p2, q1)))
            {
                cout << "Nu se intersecteaza.\n";
                return 0;
            }
        abcd
        cdab
        acbd
        acdb
        cabd
        cadb
        a = p1;
        b = q1;
        c = p2;
        d = q2;
        else
            ///a c b d
            if(distanta(p1, p2) + distanta(p2,q1) == distanta(p1,q1))
                cout << "Se intersecteaza in segmentul de coordonate: "<< p2.x << " " << p2.y<<" "<< q1.x << " " << q1.y<<"\n";
            else
                ///c a b d
                if (distanta(p2, p1) + distanta(p1,q1) == distanta(p2,q1))
                    cout << "Se intersecteaza in segmentul de coordonate: "<< p1.x << " " << p1.y<<" "<< q1.x << " " << q1.y<<"\n";
                else
                ///c a d b
                    if()

    }
    else if (intersection(p1.x, p1.y, q1.x, q1.y, p2.x, p2.y, q2.x, q2.y).x != err.x && intersection(p1.x, p1.y, q1.x, q1.y, p2.x, p2.y, q2.x, q2.y).y != err.y)
    {
        cout << "Se intersecteaza in punctul de coordonate: x = ";
        cout << intersection(p1.x, p1.y, q1.x, q1.y, p2.x, p2.y, q2.x, q2.y).x << ", y = " << intersection(p1.x, p1.y, q1.x, q1.y, p2.x, p2.y, q2.x, q2.y).y;

    }
    else
        cout << "Nu se intersecteaza.\n";
}
