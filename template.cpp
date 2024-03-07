#include <iostream>
#pragma once
#include <stdexcept>

// le probleme de la classe stack dans le fichier ExoPolycours12,12.cpp c'est que ça def que des stack de char mais ca change rien si on met des int ou des char donc on va utiliser template, maintenant quand on creera une nouvelle stack on devra preciser sur quel type elle est def (comme pour les vecteurs), par exemple stack<char> pile(3);

template <typename T> // on peut aussi mettre temlate <class T>, ça change rien, onn peut aussi template pas seulement pour la classe mais pour des variables par exemples, on peut mettre également plusiseurs template, on peut mettre template <class T, int size> par exemple
struct stack
{
    //template <class U>
    //friend std::ostream &operator<<(std::ostream &os, stack<U> &s); //on pourra ainsi bien definir la fonction pour toutes les types en dehors de la definition de la classe

    int nb = 0;
    int size;
    char *T; // data
    stack(int n) : nb(0), size(n), tab(new T[n])
    {
        if (size <= 0)
        {
            throw "Stop! pile de taille negative" /*pas possible d'avoir des piles de taille negative*/;
        };
    }; // constructeur
    stack(const stack &rs) : nb(rs.nb), size(rs.size), tab(new T[rs.size])
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
            tab = new T[rs.size];
            for (int i = 0; i < nb; i = i + 1)
            {
                tab[i] = rs.tab[i];
            };
        };
        return *this;
    };
    void push(T c)
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
    }; // method

    ~stack() { delete[] tab; }; // destructeur
};

template <class U> std::ostream &operator<<(std::ostream &os, stack<class U> &s)
{
    s.print(os);
    return os;
};