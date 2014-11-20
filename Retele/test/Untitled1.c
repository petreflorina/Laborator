#include <iostream>
#include<vector>

using namespace std;

int suma(vector<int> vect, int pos)
{
    int s=0, cpos = pos;

    while (pos < 10)
    {
        cout << "pozitia este " << pos << "\n";
        for(int i=0; i<cpos; i++)
        {
            s+=vect[pos];
            pos++;
        }

        cout << "pozitia2 este " << pos << "\n";
        for(int i=0; i<cpos-1; i++)
        {
            pos++;
        }

        cout << "pozitia3 este " << pos << "\n";
    }
    return s;

}

int main()
{
    vector<int> vect;

    for(int i=0; i<10; i++)
    {
        vect.push_back(i);
        cout << vect[i] << " ";
    }
    cout << "\n";
    for(int i=0; i<10; i++)
    {
        cout << suma(vect,i) << " ";
    }

    return 0;
}
