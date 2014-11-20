#include<iostream>
#include <cstddef>

#include<stddef.h>

using namespace std;

struct Point
{
    int x,y;
 };

Point intersection ( double x1,double y1,double x2,double y2, double x3, double y3, double x4,double y4 )
{
    Point err;
    err.x = NULL; err.y = NULL;

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

int main()
{
    Point p1, p2, q1, q2, err;
    err.x = NULL; err.y = NULL;

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

    if (intersection(p1.x, p1.y, q1.x, q1.y, p2.x, p2.y, q2.x, q2.y).x != err.x && intersection(p1.x, p1.y, q1.x, q1.y, p2.x, p2.y, q2.x, q2.y).y != err.y)
    {
        cout << "Se intersecteaza in punctul de coordonate: x = ";
        cout << intersection(p1.x, p1.y, q1.x, q1.y, p2.x, p2.y, q2.x, q2.y).x << ", y = " << intersection(p1.x, p1.y, q1.x, q1.y, p2.x, p2.y, q2.x, q2.y).y;

    }
    else
        cout << "Nu se intersecteaza.\n";
}
