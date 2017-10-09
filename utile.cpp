#include "utile.h"

#include <fstream>
#include <sstream>

using namespace std;


bool Utile::saveCSVFileByLine(const string nomFichier, vector<vector<vector<string>>> &datas)
{
    ifstream myfile;
    vector<vector<vector<string>>> rslt;
    string lineStr;
    myfile.open(nomFichier);

    if (!myfile.is_open())
    {
        cout << "Nom du fichier incorrect/Shadow build non decoche" << endl;
        return false;
    }

    while (getline(myfile, lineStr, '\n'))
    {
        lineStr.erase(std::remove(lineStr.begin(), lineStr.end(), '\r'), lineStr.end());

        if (lineStr.empty())
        {
            continue;
        }

        std::istringstream streamLine(lineStr);
        vector<vector<string>> lineTab;
        string elements;

        while (getline(streamLine, elements, ';'))
        {
            std::istringstream streamElement(elements);
            vector<string> elementTab;
            string element;

            while (getline(streamElement, element, '#'))
            {
                if (!element.empty())
                {
                    elementTab.push_back(element);
                }
            }
            lineTab.push_back(elementTab);
        }
        rslt.push_back(lineTab);
    }

    myfile.close();
    rslt.erase(rslt.begin());
    datas = rslt;

    return true;
}


