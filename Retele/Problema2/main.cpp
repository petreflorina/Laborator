#include <iostream>
#include<vector>
using namespace std;

void read(vector<int> &biti, int &length)
{

    string s = "1100111";

    length = s.size();

    for(int i=0; i<length; i++)
    {
        if(s[i] == '0')
        {
            biti.push_back(0);
        }
        else
        {
            biti.push_back(1);
        }
    }
}

bool isPowerOfTwo(int x)
{
    return (x & (x - 1)) == 0; //de exeplu pentru 4 vom avea 100 & 011 = 000
}

void addInVector(vector<int> &vect, vector<int> &biti, int length)
{
    int index = 1, indexBiti=0;

    while(length > 0)
    {
        if(isPowerOfTwo(index))
        {
            vect.push_back(0);
        }
        else if(!isPowerOfTwo(index))
        {
            vect.push_back(biti[indexBiti]);
            indexBiti++;

            length--;
        }
        index++;
    }

}

void addBitInKPosition(int pos,int length, vector<int>& biti)
{
    int copyPos = pos;

    if (isPowerOfTwo(pos+1))
    {
        while (pos < length)
        {
            for (int i=0; i<copyPos+1; i++)
            {
                if (pos < length)
                {
                    if(pos != copyPos)
                    {
                        biti[copyPos] += biti[pos];
                    }
                    pos++;

                }
                else
                {
                    break;
                }
            }
            pos += copyPos + 1;
        }
    }

    biti[copyPos] = biti[copyPos] % 2;
}

bool okCheck(vector<int> vect, vector<int>& eroare)
{
    bool error = true;

    for(int i=vect.size()-1; i>=0; i--)
    {
        if(isPowerOfTwo(i+1))
        {
            if(vect[i] != 0)
            {
                error = false;
                eroare.push_back(vect[i]);
            }
            else
            {
                eroare.push_back(vect[i]);
            }
        }
    }
    return error;
}

int powerOfTwo(int power)
{
    int m = 1;

    for(int i=1; i<power; i++)
    {
        m *= 2;
    }
    return m;
}


int changeBase(vector<int> eroare)
{
    int sum = 0;
    int power = eroare.size();

    for(int i=0; i<eroare.size(); i++)
    {
        sum += (eroare[i] *powerOfTwo(power));
        power--;
    }

    return sum;
}

void printVector(vector<int> vect)
{
    cout << "\n";

    for(int i=0; i<vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
}

void codificare(int &length, vector<int> & vect, vector<int> biti)
{
     addInVector(vect,biti,length);

    printVector(vect);

    for(int i=0; i<vect.size(); i++)
    {
        addBitInKPosition(i,vect.size(),vect);

    }

    printVector(vect);

}

void decodificare(vector<int> biti, vector<int>& eroare)
{
    for(int i=0; i<biti.size(); i++)
    {
        addBitInKPosition(i, biti.size(), biti);
    }

    printVector(biti);

    if(okCheck(biti, eroare))
    {
        cout << "\nNu exista erori.\n";
    }
    else
    {

        cout << "\nExista eroare.\n";
        printVector(eroare);
        cout << "\nPozitia este " << changeBase(eroare)<<".\n";
    }

}
int main()
{
    int length, r;
    vector<int> biti, vect, eroare;

    read(biti, length);

    cout << "Pentru codificare apasati 1, pentru decodificare apasati 2.\n";
    cin >> r;


    if (r == 1)
    {
      codificare(length, vect, biti);
    }
    else if (r==2)
    {
        decodificare(biti, eroare);
    }

return 0;
}
