#include "shape.hpp"

class Circle : public Shape
{
    int longueur; int largeur;

public:
    Circle(int x, int y, int longueu, int largeu, int color = 250) // par défaut color des Circle est à 250
        : Shape(x, y, color), // on appelle le constructeur de la classe de base Shape en lui passant les arguments
          longueur(longueu),largeur(largeu)

    {
    }
float area() const { return longueur*largeur; }
float perimetre() const { return 2*longueur+largeur; }

};

