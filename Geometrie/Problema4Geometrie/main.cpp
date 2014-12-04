#include <iostream>
#include<math.h>

using namespace std;
///prima data trbeuie sa calculez panta pentru ab si bc
///dupa care calculez panta mediatoarelor lui ab si bc
///aflu punctul de intersectie dintre mediatoare
///fac distanta de la centru la A = raza
///daca distanta de la centru la punctul meu <= raza, atunci e in centru / pe centru

struct Punct
{
    double x,y;
};

Punct coordonateMijloc(Punct a, Punct b)
{
    Punct m;

    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;

    return m;
}
double pantaDouaPuncte(Punct a, Punct b)
{
    return (b.y - a.y)/(b.x - a.x);
}

bool division(Punct a, Punct b)
{
    if(a.y == b.y) return false;
    return true;
}

double pantaMediatoare(Punct a, Punct b)
{
    if(a.x == b.x) return 0;
    double p = pantaDouaPuncte(a,b);
    return (-1/p);
}

Punct intersectiaMediatoarelor(Punct m, Punct n, double pm, double pn)
{
    Punct o;

    o.x = (m.y - (pm*m.x) - n.y + (pn*n.x))/(pn - pm);
    o.y = pm*(o.x - m.x) + m.y;

    return o;
}

double distanta(Punct a, Punct b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

///0 - in afara cercului
///1 - pe cerc
///2 - in interior
string pozitie(Punct a, Punct b, double r)
{
    if(distanta(a,b) == r)
    {
        //cout << "Distanta = " << distanta(a,b) << " si raza = " << r < "\n";
        return "Se afla pe cerc.";
    }
    else if(distanta(a,b) < r )
    {
        //cout << "Distanta = " << distanta(a,b) << " si raza = " << r < "\n";
        return "Se afla in interiorul cercului.";
    }

    return "Se afla in afara cercului.";
}

bool circumscriptibil(Punct a, Punct b, Punct c, Punct d)
{
    if(distanta(a,b) + distanta(c,d) == distanta(a,d) + distanta(b,c))
    {
        return true;
    }
    return false;
}

int main()
{
    Punct a,b,c,d,o,m,n,p;
    double raza;

    cout << "Dati coordonatele punctelor triunghiului.\n";
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;


    m = coordonateMijloc(a,b);
    n = coordonateMijloc(b,c);
    p = coordonateMijloc(a,c);

    Punct a1,b1,c1,d1;
    int div = 0;

    if(division(a,b))
    {
        a1 =a;
        b1 = b;
        div = 1;
        m = coordonateMijloc(a,b);
    }
    else if(division(b,c))
    {
        a1 = b;
        b1 = c;
        div = 2;
        m = coordonateMijloc(b,c);
    }
    else if(division(c,a))
    {
        a1 = c;
        b1 = a;
        div = 3;
        m = coordonateMijloc(c,a);
    }

    if(division(a,b) && div != 1)
    {
        c1 = a;
        d1 = b;
        n = coordonateMijloc(a,b);
    }
    else if(division(b,c) && div != 2)
    {
        c1 = b;
        d1 = c;
        n = coordonateMijloc(b,c);
    }
    else if(division(c,a) && div != 3)
    {
        c1 = c;
        d1 = a;
        n = coordonateMijloc(c,a);
    }
//    cout << "mijloace : " << m.x<< " "<<m.y<< " "<<n.x<<" "<<n.y<<"\n";
    o = intersectiaMediatoarelor(m,n,pantaMediatoare(a1,b1),pantaMediatoare(c1,d1));
    raza = distanta(a,o);

    cout << pozitie(d,o,raza) <<"\n\n";
    if(circumscriptibil(a,b,c,d)) cout << "Este circumscriptibil.";
    else cout <<"Nu este circumscriptibil.";

    return 0;
}
