#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point
{
    double x, y;
    bool isInside;
};

double aria (Point A, Point B, Point C)
{
    double x = abs(((B.x*A.y + A.x*C.y + C.x*B.y) - (A.x*B.y + C.x*A.y + B.x*C.y))/2);
    return x;
}
double distanta (Point A, Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

///pe ce parte se afla punctul r fata de segmentul pq
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

///daca punctul M se afla in interiorul triubgiului abc

bool isInsideTriangle (Point A, Point B, Point C, Point M)
{
    double a = aria (A, B, C);
    double x = aria (A, B, M), y = aria (A, C, M), z = aria (B, C, M);
    double b = x+y+z;
    return (a == b);
}

int main()
{
    Point A, B, C, D;
    cout << "Dati coordonatele punctelor.\n";

    cin>>A.x>>A.y;
    cin>>B.x>>B.y;
    cin>>C.x>>C.y;
    cin>>D.x>>D.y;

    bool convexitate = doIntersect(A, C, B, D);

    if (convexitate == 1)
    {
        cout<<"E convex\n";
    }
    else
    {
        cout<<"Nu este convex\n";
    }

    Point M;
    cout<<"Coord lui M\nx = ";
    cin>>M.x;
    cout<<"y = ";
    cin>>M.y;

    if (convexitate == 1)
    {
        bool ok= false;
        if (isInsideTriangle(A, B, C, M) == 1) {ok = true; }
        if (isInsideTriangle(D, A, C, M) == 1) {ok = true; }
        cout<<(ok?"DA":"NU");
        return 0;
    }

    bool concavitate = false;
    A.isInside=B.isInside=C.isInside=D.isInside=false;

    if (isInsideTriangle(A, B, C, D) == 1) {concavitate = true; D.isInside = true;}
    if (isInsideTriangle(A, B, D, C) == 1) {concavitate = true; C.isInside = true;}
    if (isInsideTriangle(A, C, D, B) == 1) {concavitate = true; B.isInside = true;}
    if (isInsideTriangle(D, B, C, A) == 1) {concavitate = true; A.isInside = true;}


    if (concavitate == true)
    {
        if (D.isInside == 1)
        {
            cout<<(isInsideTriangle(A, B, C, M)?"DA":"NU");
            return 0;
        }
        if (A.isInside == 1)
        {
            cout<<(isInsideTriangle(D, B, C, M)?"DA":"NU");
            return 0;
        }
        if (B.isInside == 1)
        {
            cout<<(isInsideTriangle(A, D, C, M)?"DA":"NU");
            return 0;
        }
        if (C.isInside == 1)
        {
            cout<<(isInsideTriangle(A, B, D, M)?"DA":"NU");
            return 0;
        }
    }

    Point aux = A;
    A = D;
    D = aux;

    bool inter = false;
    if (esteInterior(A, B, C, M) == 1) {inter = true; }
    if (isInsideTriangle(D, A, C, M) == 1) {inter = true; }
    cout<<(inter?"DA":"NU");


    return 0;
}
