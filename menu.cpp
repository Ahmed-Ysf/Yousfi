#include "menu.h"
#include <fstream>
#include <algorithm>
#include <fstream>
#include <iomanip>


Menu::Menu(const string &_nom):nom(_nom), longueurMax(0)
{


    ifstream leFichier(nom);

    if(!leFichier.is_open())
    {
        cerr << "Erreur à l'ouverture du fichier !" << endl;
        nbOptions = 0;
        exception excep()
    }
    else
    {
        nbOptions = static_cast<int>(count(istreambuf_iterator<char>(leFichier), istreambuf_iterator<char>(), '\n'));
        leFichier.seekg(0, ios::beg);
        options = new string [nbOptions];
        size_t tailleOption;

        for(int i=0; i < nbOptions ; i++)
        {
            getline(leFichier,options[i]);
            tailleOption = options[i].length();
            if(tailleOption > longueurMax)
            {
                longueurMax = tailleOption;
            }
        }
    }

}


Menu::~Menu()
{
    delete [] options;
}


int Menu::afficher()
{
    int indice;
    int choix;
    system("clear");
    cout << "+" << setfill('-') << setw(5) << "+" << setfill('-') << setw(longueurMax+1) << "+" << endl;
    for(indice = 0; indice < nbOptions ; indice++)
    {
        cout << "|" << setfill(' ') << setw(4) << left << indice+1 << "|" << setfill(' ') << setw(longueurMax) << left << options[indice] << "|" <<  endl;
    }
    cout << "+" << setfill('-') << setw(5) << right << "+" << setfill('-') << setw(longueurMax+1) << "+" << endl;

    cout << endl;
    cout << "votre choix : ";
    if(!(cin>>choix))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        choix = -1;
    }

    return choix;

}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "Appuyer sur la touche Entrée pour continuer...";
    getline(cin,uneChaine);
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n' );
    system("clear");
}
