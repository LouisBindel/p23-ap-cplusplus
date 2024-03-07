#include <vector>
#include <iostream>

class shape
{
    int x;
    int y;
    char color;

public:
    shape(int posx, int posy, char col = 'n') : x(posx), y(posy), color(col){};
    void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    };
    virtual float area()const { return 0; };
};

class circle : public shape
{
    int radius;

public:
    circle(int posx, int posy, int rad, char col = 'k') : radius(rad), shape(posx, posy, col){};
    float area() { return 3.14 * radius * radius; }
};
class rectangle : public shape
{
    int hauteur;
    int largeur;
};

int main()
{
    circle c(1, 20, 2);
    c.area();
    shape *s = &c;
    s->move(4, 5);
    std::cout << s->area() << std::endl;
    std::cout << c.area() << std::endl;
    std::cout << "cff" << std::endl;
    return 0;
};
