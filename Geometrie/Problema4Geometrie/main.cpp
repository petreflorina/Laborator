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

double pantaMediatoare(Punct a, Punct b)
{
    double p = pantaDouaPuncte(a,b);
    return (-1/p);
}

Punct intersectiaMediatoarelor(Punct m, Punct n, double pn, double pm)
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
    Punct a,b,c,d,o,m,n;
    double raza;

    cout << "Dati coordonatele punctelor triunghiului.\n";
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    m = coordonateMijloc(a,b);
    n = coordonateMijloc(b,c);

//    cout << "mijloace : " << m.x<< " "<<m.y<< " "<<n.x<<" "<<n.y<<"\n";

    o = intersectiaMediatoarelor(m,n,pantaMediatoare(b,c), pantaMediatoare(a,b));
  //  cout << o.x <<" "<< o.y << " <- coordonte punct intersectie\n";
    raza = distanta(a,o);

    cout << pozitie(d,o,raza) <<"\n\n";
    if(circumscriptibil(a,b,c,d)) cout << "Este circumscriptibil.";
        else cout <<"Nu este circumscriptibil.";

    return 0;
}
