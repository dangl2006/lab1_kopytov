#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

struct Pipe {
    string name = "";
    float length = 0.0;
    int diametr = 0;
    bool repair = false;
};

void check() {
    cout << "Error!" << endl;
    cout << "Write correct data" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct Pepe {
    string name = "";
    int ceh = 0;
    int rabceh = 0;
    bool working = false;
    string clstan = "";
};

void loadFromFile(Pipe& t, Pepe& c) {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "No saved data found\n";
        return;
    }


    file >> t.name >> t.length >> t.diametr >> t.repair;
    file >> c.name >> c.ceh >> c.rabceh >> c.working >> c.clstan;

    file.close();
    cout << "Data loaded!\n";
}


void saveToFile(Pipe& t, Pepe& c) {
    ofstream file("data.txt");
    if (file.is_open()) {      
        file << t.name << " " << t.length << " " << t.diametr << " " << t.repair << endl;
        file << c.name << " " << c.ceh << " " << c.rabceh << " " << c.working << " " << c.clstan;

        file.close();
        cout << "Data saved!\n";
    }
    else {
        cout << "Save error!\n";
    }
}

void Menu(Pipe& t, Pepe& c) {
    while (true) 
    {
        cout << "\n1. Pipe 2. Pepe 3. Show 4. Save 5. Load 6. Exit\n";
        int type;
        cin >> type;

        if (cin.fail() || type < 1 || type > 6) {
            check();
            continue;
        }

        switch (type) {
        case 1: {
            cout << "1.Name 2.Length 3.Diametr 4.Repair\n";
            int opt;
            cin >> opt;

            if (cin.fail() || opt < 1 || opt > 4) {
                check();
                break;
            }

            if (opt == 1) {
                cout << "Name: ";
                cin >> t.name;
            }
            else if (opt == 2) {
                cout << "Length: ";
                cin >> t.length;
                if (cin.fail() || t.length <= 0) check();
            }
            else if (opt == 3) {
                cout << "Diametr: ";
                cin >> t.diametr;
                if (cin.fail() || t.diametr <= 0) check();
            }
            else if (opt == 4) {
                cout << "Repair (1-yes, 0-no): ";
                int r;
                cin >> r;
                t.repair = (r == 1);
            }
            break;
        }

        case 2: {
            cout << "1.Name 2.Quantity 3.Working 4.Class 5.Status\n";
            int opt;
            cin >> opt;

            if (cin.fail() || opt < 1 || opt > 5) {
                check();
                break;
            }

            if (opt == 1) {
                cout << "Name: ";
                cin >> c.name;
            }
            else if (opt == 2) {
                cout << "Quantity: ";
                cin >> c.ceh;
                if (cin.fail() || c.ceh <= 0) check();
            }
            else if (opt == 3) {
                cout << "Working: ";
                cin >> c.rabceh;
                if (cin.fail() || c.rabceh < 0 || c.rabceh > c.ceh) check();
            }
            else if (opt == 4) {
                cout << "Class: ";
                cin >> c.clstan;
            }
            else if (opt == 5) {
                cout << "Working (1-yes, 0-no): ";
                int w;
                cin >> w;
                c.working = (w == 1);
            }
            break;
        }

        case 3:
            cout << "\n--- Pipe ---\n";
            cout << "Name: " << (t.name.empty() ? "No data" : t.name) << endl;
            cout << "Length: " << t.length << endl;
            cout << "Diametr: " << t.diametr << endl;
            cout << "Repair: " << (t.repair ? "Yes" : "No") << endl;

            cout << "\n--- Pepe ---\n";
            cout << "Name: " << (c.name.empty() ? "No data" : c.name) << endl;
            cout << "Quantity: " << c.ceh << endl;
            cout << "Working: " << c.rabceh << endl;
            cout << "Class: " << c.clstan << endl;
            cout << "Status: " << (c.working ? "Yes" : "No") << endl;
            break;

        case 4:
            saveToFile(t, c);
            break;

        case 5:
            loadFromFile(t, c);
            break;

        case 6:
            cout << "Bye!\n";
            return;
        }
    }
}

int main() {
    Pipe truba;
    Pepe ceh;
    Menu(truba, ceh);
    return 0;
}