#include <iostream>
#include "utile.h"
#include "db.h"

using namespace std;

int main()
{
    vector<vector<vector<string>>> csvTab;
    if (!Utile::saveCSVFileByLine("res/archeo.csv", csvTab))
    {
        cout << "CSV to vector : not ok" << endl;
        return 0;
    }

    cout << "CSV to vector : ok" << endl;

    return 0;
}
