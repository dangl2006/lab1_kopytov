#include <iostream>
#include <string>
using namespace std;

struct Pipe {
    string name;
    float lengh;
    int diametr;
    bool repear;
};

struct Pepe {
    string name;
    int ceh;
    int rabceh;
    string clstan;
};

void Menu(Pipe t) {
    while (1)
    {
        cout << "\nChoose option:\n1. Add Pipe\n2. Add Pepe\n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Insert Pipe name: ";
            cin >> t.name;
            break;
        case 3:
            cout << "Pipe name: " << t.name;
        }
    }
}

int main()
{
    Pipe truba;
    truba.name = "Uchastok 1";
    cout << truba.name;
    Menu(truba);
}