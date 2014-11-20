#include <iostream>
#include<vector>

using namespace std;

int suma(vector<int> vect, int pos)
{
    int s=0, cpos = pos;

    if (pos != 0)
        while (pos < 10)
        {
            for(int i=0; i<cpos; i++)
            {
                if(pos < 10)
                {
                    s+=vect[pos];
                    pos++;
                }
                else
                    break;
            }
            for(int i=0; i<cpos; i++)
            {
                if(pos < 10)
                    pos++;
                else
                    break;
            }
        }
    return s;

}

int main()
{
    vector<int> vect;

    for(int i=0; i<10; i++)
    {
        vect.push_back(i);
        cout << vect[i] << "   ";
    }
    cout << "\n";
    for(int i=0; i<10; i++)
    {
        cout << suma(vect,i) << "   ";
    }

    return 0;
}
