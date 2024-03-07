#include <vector>
#include <iostream>

class Element
{
public:
    int x;
    int y;
    Element(int i, int j) : x(i), y(j){};
    int abscisse() { return x; };
    int ordonnée() { return y; };
};

class Object : public Element
{
    Object(int i, int j) : Element(i, j){};
};

class Personnage : public Element
{
public:
    Personnage(int i, int j) : Element(i, j){};
    int abscisse() { return x; };
    int ordonnée() { return y; };
};

class Position // cette classe prend en compte les elements du vecteur position_des_elements, le vecteur qui liste les elements sur le plateau
{
public:
    int x;
    int y;
    char e;
    Position(int i, int j, char c) : x(i), y(j), e(c){};
    int abscisse() { return x; };
    int ordonnée() { return x; };
    char ecriture_case() { return e; };
};

char print_object(int i, int j, std::vector<Position> position_des_elements)
{
    for (int k = 0; k < position_des_elements.size(); k = k + 1)
    {
        if (position_des_elements[k].abscisse() == i and position_des_elements[k].ordonnée() == j)
        {
            return position_des_elements[k].ecriture_case();
        };
    }
    return '.';
};

void affichage(std::vector<Position> position_des_elements, int largeur, int hauteur)
{
    for (int j = 0; j < hauteur; j = j + 1)
    {
        for (int i = 0; i < largeur; i = i + 1)
        {
            std::cout << print_object(i, j, position_des_elements);
        }
        std::cout << '\n';
    };
};

int main()
{
    std::vector<Position> position_des_elements;
    std::cout << "Votre classe ? Tapez g pour guerrier, v pour voleur, m pour mage" << '\n';
    char e;
    std::cin >> e;
    if (e == 'g')
    {
        Personnage perso(0, 0);
        };

    for (int i = 0; i < 4; i = i + 1)
    {
        position_des_elements.push_back(Position(perso.abscisse(), perso.ordonnée(), 'H'));
        std::cout << "votre action" << '\n';
        char c;
        std::cin >> c;
        if (c == 'z')
        {
            std::cout << "on monte" << '\n';
            
        };
        if (c == 'q')
        {
            std::cout << "a gauche" << '\n'; /*a gauche*/
        };
        if (c == 'd')
        {
            std::cout << "a droite" << '\n'; /*a droit*/
        };
        if (c == 's')
        {
            std::cout << "on descend" << '\n'; /*on descend*/
        };
        affichage(position_des_elements, 5, 5);
    }
};