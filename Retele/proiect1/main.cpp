#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include<vector>
#include<algorithm>
#include<windows.h>
using namespace std;

void addInVector(ifstream &in, vector<string> & v)
{
    while(!in.eof())
    {
        string s;

        in >> s;
        if(s.length() == 17)
        {
            //          cout << s <<"\n";
            v.push_back(s);

        }
    }
}
bool contains(vector<string> c, vector<string> v, vector<string>::iterator it, string target)
{

    it = find(v.begin(), v.end(), target);
    if (it != v.end())
        return true;

    else
        return false;
}

void rezolvare(vector<string> retea, vector<string> mac, ofstream & out)
{
    vector<string>::iterator it;
    for(int i=0; i<retea.size(); i++)
    {

        if (!contains(retea, mac, it, retea[i]))
            //daca mac.txt nu contine un element din retea, il adaug
        {
            //          cout<<"\nmac bagat in mac.txt"<< retea[i];
            out<<retea[i]<<"\n";
        }
    }

    for(int i=0; i<mac.size(); i++)
    {
        //  cout<<"\nsds--34";
        if(!contains( mac,retea, it, mac[i]))
        {
            cout<<mac[i]<<'\n';
        }
    }

}

int main()
{
    bool repeat = true;
    vector<string> mac, retea;

    int T;
    cout <<"Dati numarul de minute:";
    cin >> T;
    T *= 1000*60;


    while (1)
    {
        ifstream f("mac.txt");
        ifstream r("retea.txt");

        system("arp -a > retea.txt");

        addInVector(f,mac); // adaug in f adresele din mac
        addInVector(r,retea); // adaug in r adresele mac din retea

        f.close();
        ofstream out("mac.txt", ios::app);

        rezolvare(retea,mac,out);

        r.close();
        out.close();
        cout << "\n";
        Sleep(T);
    }
    return 0;
}
