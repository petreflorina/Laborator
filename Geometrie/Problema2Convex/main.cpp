#include <iostream>
#include<math.h>

using namespace std;

struct Punct{
    float x,y;
};

bool verif(Punct a, Punct b, Punct c)
{
    int da, db, dc, dd;

    da = b.x - a.x;
    db = b.y - a.y;
    dc = c.x - b.x;
    dd = c.y - b.y;

    int product;
    product = da * dd - db * dc;

    if(product >= 0 || product <= 0) return true;
    return false;
}

float distanta(Punct a, Punct b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

float unghi(Punct a, Punct b, Punct c)
{
    float dab, dac, dbc, u;

    dab = distanta(a,b);
    dac = distanta(a,c);
    dbc = distanta(b,c);

    u = acos((dab * dab + dac * dac - dbc * dbc) / (2 * dab * dac));

    return ((u*180.0)/3.14159265) ;
}

int main()
{
    Punct a, b, c, d, x;
    cout << "Dati coordonatele punctelor.\n";

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    if(verif(a,b,c) && verif(b,c,d) && verif(c,d,a) && verif(d,a,b))
        cout << "Patrulaterul este covex.\n";

    cout << "Dati coordonatele punctului pe care vreti sa il testati.\n";
    cin >> x.x >> x.y;

    float s=0;

    s = unghi(x,a,b) + unghi(x,b,c) + unghi(x,c,d) + unghi(x,d,a);

    if (s == 360) cout << "Punctul este in patrulater.\n";
    else
        cout << " Punctul nu e in patrulater.\n";

    return 0;
}
