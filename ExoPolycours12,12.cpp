#include <iostream>


struct stack
{
    int nb = 0;
    int size;
    char *tab; // data
    stack(int n) : nb(0), size(n), tab(new char[n])
    {
        if (size <= 0)
        {
            throw "Stop! pile de taille negative" /*pas possible d'avoir des piles de taille negative*/;
        };
    }; // constructeur
    stack(const stack &rs) : nb(rs.nb), size(rs.size), tab(new char[rs.size])
    {
        for (int i = 0; i < nb; i = i + 1)
        {
            tab[i] = rs.tab[i];
        };
    }; // constructeur de copie,  pour faire une copie sans que la modif de l'un modifie l'autre.
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
    void push(char c)
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
            throw "stop!";
        }
    }; // method
    char top()
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
            throw "il 'y a rien a top";
        }
    }; // method
    char pop()
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
            throw "il 'y a rien a pop";
        }
    }; // method
    bool isempty()
    {
        this->nb;
        this->size;
        this->tab;
        return nb == 0;
    }; // method
    bool isfull()
    {
        this->nb;
        this->size;
        this->tab;
        return nb == size;
    };                                       // method
    void print(std::ostream &os = std::cout) // os est par exemple égale à std::cout, cout est l'ostream qui affiche
    {
        this->nb;
        this->size;
        this->tab;
        for (int i = 0; i < nb; i = i + 1)
        {
            os << tab[i] << " ";
        }
        os << '\n' /*pour passer à la ligne*/;
    };                          // method
    ~stack() { delete[] tab; }; // destructeur
};

std::ostream &operator<<(std::ostream &os, stack &s)
{
    s.print(os);
    return os;
}; // le return os permet de faire std::cout<<S1<<S2 c'est à dire d'afficher les truc à la suite  car std::cout<<S1<<S2 = operator<<(operator<<(cout,S1),S2) et que si operator<< renvoie par de ostream ca marcherait pas

int main()
{
    stack s1(5);
    s1.push('l');
    s1.print();
    stack s2 = s1;
    s1.push('o');
    s1.print();
    s1.push('u');
    s1.push('i');
    s1.push('s');
    s2.push('w');
    std::cout << s2;
    std::cout << s1;
    s2 = s1;
    std::cout << s2;
    s2.print();
}
