#include <stdexcept>
#include <iostream>


struct stack
{
private:
    int nb = 0;
    int size;
    char *tab; // data

public:
    stack(int n) : nb(0), size(n) // constructeur
    {
        if (size <= 0)
        {
            throw std::invalid_argument("Erreur taille de la pile");
        }
        else
        {
            tab = new char[n];
        };
    }; 
    stack(const stack &rs) : nb(rs.nb), size(rs.size), tab(new char[rs.size]) // constructeur de copie,  pour faire une copie sans que la modif de l'un modifie l'autre.
    {
        for (int i = 0; i < nb; i = i + 1)
        {
            tab[i] = rs.tab[i];
        };
    }; 
    stack &operator=(const stack &rs)
    {
        if (this != &rs)
        {
            delete[] tab;
            nb = rs.nb;
            size = rs.size;
            tab = new char[rs.size];
            for (int i = 0; i < nb; i = i + 1)
            {
                tab[i] = rs.tab[i];
            };
        };
        return *this;
    };
    void push(char c) // method
    {
        this->nb;
        this->size;
        this->tab;
        if (nb < size)
        {
            tab[nb] = c;
            nb = nb + 1;
        }
        else
        {
            throw std::range_error("Pile pleine");
        }
    }; 
    char top() const // method
    {
        this->nb;
        this->size;
        this->tab;
        if (nb > 0)
        {
            return tab[nb - 1];
        }
        else
        {
            throw std::range_error("Pile vide");
        }
    }; 
    char pop() // method
    {
        this->nb;
        this->size;
        this->tab;
        if (nb > 0)
        {
            nb = nb - 1;
            return tab[nb];
        }
        else
        {
            throw std::range_error("Pile vide");
        }
    }; 
    bool isempty() const // method
    {
        this->nb;
        this->size;
        this->tab;
        return nb == 0;
    }; 
    bool isfull() const // method
    {
        this->nb;
        this->size;
        this->tab;
        return nb == size;
    }; 
    void print() const // method
    {
        this->nb;
        this->size;
        this->tab;
        std::cout << '[' << ' ';
        for (int i = 0; i < nb; i = i + 1)
        {
            std::cout << tab[i] << " ";
        }
        std::cout << ']' << '\n' /*pour passer à la ligne*/;
    };                          
    ~stack() { delete[] tab; }; // destructeur
};
