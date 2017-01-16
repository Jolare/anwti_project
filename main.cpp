#include <iostream>
using namespace std;

class Gruess
{
public:
    Gruess()
    {
        cout << "Hallo!\n";
    }
    ~Gruess()
    {
        cout << "Adieu!\n";
    }
};

Gruess mygruess;

int main ()
{
    cout << "Beginn main()\n";
    {
        Gruess localGruess;
    }
    cout << "Ende main()\n";
}
