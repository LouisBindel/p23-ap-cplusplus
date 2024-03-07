#include <vector>
#include <iostream>

class personnage
{
public:
    int sante;
    int force;
    int experience;
    personnage(int x, int y, int z) : sante(x), force(y), experience(z) {}
};

class guerrier : public personnage
{

public:
    guerrier(int x, int y, int z) : personnage(x, y, z){};
};

class mage : public personnage
{
public:
    mage(int x, int y, int z) : personnage(x, y, z){};
};

class voleur : public personnage
{
public:
    voleur(int x, int y, int z) : personnage(x, y, z){};
};

class inventaire
{
    int taille;
    std::vector<char> liste_inventaire; // vecteur vide par défaut

    void ajout(char e)
    {
        if (liste_inventaire.size() < taille)
        {
            liste_inventaire.push_back(e);
        };
    }

    bool est_il_dans_inventaire(char e)
    {
        for (int k = 0; k < liste_inventaire.size(); k += 1)
        {
            if (liste_inventaire[k] == e)
            {
                return true;
            };
        };
        return false;
    }
};

class hisstoire
{
};

int main()
{
    int n;
    std::cout << "Quelle classe veux-tu être ? Ecris 1 pour guerrier, 2 pour mage, 3 pour voleur" << std::endl;
    std::cin >> n;
    if (n = 1)
    {
        guerrier perso(100, 0, 0);
    };
    if (n = 2)
    {
        mage perso(100, 0, 0);
    };
    if (n = 3)
    {
        voleur perso(100, 0, 0);
    };
}