#include <iostream>
#include <string>
#include <limits>
#include <fstream> // добавляем для работы с файлами

using namespace std;

struct Pipe {
    string name;
    float length;
    int diametr;
    bool repair;
};

void check() {
    cout << "Error!" << endl;
    cout << "Write correct data" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct Pepe {
    string name;
    int ceh;
    int rabceh;
    bool working;
    string clstan;
};

void saveToFile(Pipe t, Pepe c) {
    ofstream file("data.txt"); // создаем файл для записи
    if (file.is_open()) {
        file << "Pipe parameters:\n";
        file << "Name: " << t.name << "\n";
        file << "Length: " << t.length << "\n";
        file << "Diameter: " << t.diametr << "\n";
        file << "On repair: " << t.repair << "\n\n";

        file << "Pepe parameters:\n";
        file << "Name: " << c.name << "\n";
        file << "Quantity: " << c.ceh << "\n";
        file << "Working: " << c.rabceh << "\n";
        file << "Classification: " << c.clstan << "\n";
        file << "Is working: " << c.working << "\n";

        file.close();
        cout << "Data saved to file 'data.txt'\n";
    }
    else {
        cout << "Error: cannot open file!\n";
    }
}

void Menu(Pipe t, Pepe c) {
    while (1)
    {
        cout << "Choose one:\n1. Pipe\n2. Pepe\n3. Show All\n4. Save to file\n"; // добавляем пункт 4
        int type;
        cin >> type;
        if (cin.fail() || type > 4 || type < 1) { // меняем на 4
            check();
        }
        switch (type)
        {
        case 1:
            cout << "\nChoose option:\n1. Add Pipe\n2. Pipe length\n3. Pipe diametr\n4. Repair\n";
            int option;
            cin >> option;
            if (cin.fail() || option > 4 || option < 1) {
                check();
            }
            switch (option)
            {
            case 1:
                cout << "Enter Pipe name: ";
                cin >> t.name;
                break;
            case 2:
                cout << "Enter pipe length (km): ";
                cin >> t.length;
                if (cin.fail() || t.length <= 0) {
                    check();
                }
                break;
            case 3:
                cout << "Enter pipe diametr (mm): ";
                cin >> t.diametr;
                if (cin.fail() || t.diametr <= 0) {
                    check();
                }
                break;
            case 4:
                cout << "Is pipe on repair (0-no, 1-yes)?\n";
                int trig;
                cin >> trig;
                if (cin.fail() || (trig != 0 && trig != 1)) {
                    check();
                }
                else {
                    t.repair = (trig == 1); // сохраняем значение
                }
                break;
            }
            break;
        case 2:
            cout << "Choose option:\n1. Add Pepe\n2. Quantity of Pepe\n3. Quantity working\n4. Classification\n5. Is Pepe working?\n";
            int option2;
            cin >> option2;
            switch (option2)
            {
            case 1:
                cout << "Enter Pepe name: ";
                cin >> c.name;
                break;
            case 2:
                cout << "Quantity of Pepe: ";
                cin >> c.ceh;
                if (cin.fail() || c.ceh <= 0) {
                    check();
                }
                break;
            case 3:
                cout << "Quantity working: ";
                cin >> c.rabceh;
                if (cin.fail() || c.rabceh < 0 || c.rabceh > c.ceh) {
                    check();
                }
                break;
            case 4:
                cout << "Classification: ";
                cin >> c.clstan;
                break;
            case 5:
                cout << "Is Pepe working? (1-yes,0-no)";
                int trig1;
                cin >> trig1;
                if (cin.fail() || (trig1 != 0 && trig1 != 1)) {
                    check();
                }
                else {
                    c.working = (trig1 == 1);
                }
                break;
            }
            break;
        case 3:
            cout << "\nPipe parameters: \n" << "Name: " << t.name << "\nLength: " << t.length << "\nDiametr: " << t.diametr << "\nOn repair: " << t.repair;
            cout << "\nPepe parameters: \n" << "Name: " << c.name << "\nQuantity: " << c.ceh << "\nOn working: " << c.rabceh << "\nClassification: " << c.clstan << "\nWorking: " << c.working;
            break;
        case 4:
            saveToFile(t, c); 
            break;
        }
    }
}

int main()
{
    Pipe truba;
    Pepe ceh;
    truba.name = "Uchastok 1";
    cout << truba.name;
    Menu(truba, ceh);
    return 0;
}