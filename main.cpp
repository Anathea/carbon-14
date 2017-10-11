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

    for (vector<vector<string>> champs : csvTab)
    {
        vector<string> coordonnee_wgs84 = champs[0];

        vector<string> departement = champs[1];
        Value idDept;

        vector<string> commune = champs[2];
        Value idVille;

        vector<string> nom_du_site = champs[3];
        Value idSite;

        vector<string> date_debut = champs[4];

        vector<string> date_fin = champs[5];

        vector<string> periode_s = champs[6];

        vector<string> theme_s = champs[7];

        vector<string> type_d_intervention = champs[8];
        Value idType;

        map<string, Value> values;

        if (!departement.empty())
        {
            values["nomDepartement"] = Value(departement[0]);
            Entry departementEntry = departements.createEntryIfNotExist(values);
            idDept = departements.getEntryValue(departementEntry, "idDepartement");
        }

        values.clear();

        if (!commune.empty())
        {
            values["nomCommune"] = Value(commune[0]);

            if (idDept.getDataInt() >= 0)
            {
                values["idDepartement"] = idDept;
            }

            Entry villeEntry = villes.createEntryIfNotExist(values);
            idVille = villes.getEntryValue(villeEntry, "idVille");
        }

        values.clear();

        if (!type_d_intervention.empty())
        {
            values["typeIntervention"] = Value(type_d_intervention[0]);
            Entry typeEntry = typesIntervention.createEntryIfNotExist(values);
            idType = typesIntervention.getEntryValue(typeEntry, "idTypeIntervention");
        }

        values.clear();

        if (!nom_du_site.empty())
            values["nomSite"] = Value(nom_du_site[0]);

        if (!coordonnee_wgs84.empty())
            values["coordonnees"] = Value(coordonnee_wgs84[0]);

        if (idVille.getDataInt() >= 0)
            values["idVille"] = idVille;

        if (idType.getDataInt() >= 0)
            values["idTypeIntervention"] = idType;

        if (!date_debut.empty())
            values["dateDebut"] = Value(date_debut[0]);

        if (!date_fin.empty())
            values["dateFin"] = Value(date_fin[0]);

        if (!values.empty())
        {
            Entry siteEntry = sites.createEntryIfNotExist(values);
            idSite = sites.getEntryValue(siteEntry, "idSite");
        }

        if (!periode_s.empty())
        {
            for (auto element : periode_s)
            {
                values.clear();
                values["nomPeriode"] = Value(element);

                Entry periodeEntry = periodes.createEntryIfNotExist(values);
                Value idPeriode = periodes.getEntryValue(periodeEntry, "idPeriode");

                values.clear();

                if (idSite.getDataInt() >= 0)
                {
                    values["idSite"] = idSite;
                    values["idPeriode"] = idPeriode;

                    lienPeriodesSite.createEntryIfNotExist(values);
                }
            }
        }


        if (!theme_s.empty())
        {
            for (auto element : theme_s)
            {
                values.clear();
                values["nomTheme"] = Value(element);

                Entry themeEntry = themes.createEntryIfNotExist(values);
                Value idTheme = themes.getEntryValue(themeEntry, "idTheme");

                values.clear();

                if (idSite.getDataInt() >= 0)
                {
                    values["idSite"] = idSite;
                    values["idTheme"] = idTheme;

                    lienThemesSite.createEntryIfNotExist(values);
                }
            }
        }
    }

    bdd.addEntity(departements);
    bdd.addEntity(villes);
    bdd.addEntity(typesIntervention);
    bdd.addEntity(sites);
    bdd.addEntity(periodes);
    bdd.addEntity(lienPeriodesSite);
    bdd.addEntity(themes);
    bdd.addEntity(lienThemesSite);

    bdd.saveTables();

    return 0;
}
