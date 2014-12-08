#include<iostream>
#include <cstddef>

#include<stddef.h>
#include<math.h>

using namespace std;

struct Point
{
    double x,y;
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
    Point a, c, b, d, err;
    err.x = NULL;
    err.y = NULL;

    cout << "Dati coordonatele capetelor primului segment: \n";
    cout << "x: ";
    cin >> a.x;
    cout << "y: ";
    cin >> a.y;
    cout << "x: ";
    cin >> b.x;
    cout << "y: ";
    cin >> b.y;


    cout << "Dati coordonatele capetelor celui de-al 2-lea segment: \n";
    cout << "x: ";
    cin >> c.x;
    cout << "y: ";
    cin >> c.y;
    cout << "x: ";
    cin >> d.x;
    cout << "y: ";
    cin >> d.y;

    bool ok=false;
    // cout << "Orientarea este " << testDet(a, c, b) << " si " << testDet(a, c, d) << "\n";

    if (intersection(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y).x != err.x && intersection(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y).y != err.y)
    {
        cout << "0Se intersecteaza in punctul de coordonate: x = ";
        cout << intersection(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y).x << ", y = " << intersection(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y).y;
        ok = true;
        return 0;
    }
//    -ABCD
//    -ACBD
//    ACDB
//
//    -CABD
//    -CDAB
//    CADB

    if (testDet(a, c, b) == testDet(a, c, d))

    {
        ///a b  c d
        if(distanta(a, b)+ distanta(c,d) < (distanta(a, d)))
        {
            cout << "Nu se intersecteaza1.\n";
            return 0;
        }
        else
            ///c d a b
            if(distanta(a, b)+distanta(c,d) < (distanta(c, b)))
            {
                cout << "Nu se intersecteaza2.\n";
                return 0;
            }
            else
                ///a c b d
                if(distanta(a, c) + distanta(c,b) == distanta(a,b))
                {
                    cout << "3Se intersecteaza in segmentul de coordonate: "<< c.x << " " << c.y<<" "<< b.x << " " << b.y<<"\n";
                    return 0;
                }
                else
                    ///c a b d
                    if (distanta(c, a) + distanta(a,b) == distanta(c,b))
                    {
                        cout << "4Se intersecteaza in segmentul de coordonate: "<< a.x << " " << a.y<<" "<< b.x << " " << b.y<<"\n";
                        return 0;
                    }
                    else
                        ///c a d b
                        if(distanta(c,a) + distanta(a,d) == distanta(c,d))
                        {
                            cout << "5Se intersecteaza in segmentul de coordonate: "<< a.x << " " << a.y<<" "<< d.x << " " << d.y<<"\n";
                            return 0;
                        }
                        else
                            ///acdb

                            if(distanta(a,c) + distanta(c,d) == distanta(a,d))
                            {
                                cout << "6Se intersecteaza in segmentul de coordonate: "<< c.x << " " << c.y<<" "<< d.x << " " << d.y<<"\n";
                                return 0;
                            }
    }
    if (!ok) cout << "7Nu se intersecteaza.\n";
}
