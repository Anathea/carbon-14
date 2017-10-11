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

    DB bdd;

    Entity departements("departements");
    departements.addProperty(Property("idDepartement", ValueType::integer, Value(0), true));
    departements.addProperty(Property("nomDepartement", ValueType::str));

    Entity villes("villes");
    villes.addProperty(Property("idVille", ValueType::integer, Value(0), true));
    villes.addProperty(Property("nomCommune", ValueType::str));
    villes.addProperty(Property("idDepartement", ValueType::integer));

    Entity typesIntervention("typesIntervention");
    typesIntervention.addProperty(Property("idTypeIntervention", ValueType::integer, Value(0), true));
    typesIntervention.addProperty(Property("typeIntervention", ValueType::str, Value("fouille")));

    Entity sites("sites"); // TODO
    sites.addProperty(Property("idSite", ValueType::integer, Value(0), true));
    sites.addProperty(Property("nomSite", ValueType::str));
    sites.addProperty(Property("coordonnees", ValueType::str));
    sites.addProperty(Property("idVille", ValueType::integer));
    sites.addProperty(Property("idTypeIntervention", ValueType::integer));
    sites.addProperty(Property("dateDebut", ValueType::str));
    sites.addProperty(Property("dateFin", ValueType::str));

    Entity periodes("periodes"); // TODO
    periodes.addProperty(Property("idPeriode", ValueType::integer, Value(0), true));
    periodes.addProperty(Property("nomPeriode", ValueType::str));

    Entity lienPeriodesSite("lienPeriodesSite");
    lienPeriodesSite.addProperty(Property("idSite", ValueType::integer));
    lienPeriodesSite.addProperty(Property("idPeriode", ValueType::integer));

    Entity themes("themes"); // TODO
    themes.addProperty(Property("idTheme", ValueType::integer, Value(0), true));
    themes.addProperty(Property("nomTheme", ValueType::str));

    Entity lienThemesSite("lienThemesSite"); // TODO
    lienThemesSite.addProperty(Property("idSite", ValueType::integer));
    lienThemesSite.addProperty(Property("idTheme", ValueType::integer));


    bdd.addEntity(departements);
    bdd.addEntity(villes);
    bdd.addEntity(typesIntervention);
    bdd.addEntity(sites);
    bdd.addEntity(periodes);
    bdd.addEntity(lienPeriodesSite);
    bdd.addEntity(themes);
    bdd.addEntity(lienThemesSite);


    return 0;
}
