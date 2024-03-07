#pragma once
#include <vector>
#include <iostream>

class vertex;

class edge
{
    friend class graph;
    friend class vertex;

public:
    float poids = 0.0;
    vertex *target = nullptr;

public:
    edge() = default;
    // vr: tu ne peux pas mettre une valeur par défaut à un  argument si tu n'en mets pas une aux suivants
    //    edge(float value = 0, vertex *cible) : poids(value), target(cible){}; // vr: pas besoin de ; ici
    edge(float value, vertex *cible) : poids(value), target(cible){}; // vr: pas besoin de ; ici
                                                                      // vertex target() { return *target; };

    // vr: tu dois retourner une référence pas un objet ! ne ne veut rien recopier
    // vertex cible() { return *target; };
    vertex &cible() { return *target; };
};

class vertex
{
    friend class graph;
    friend class edge;
    std::vector<edge> adjacants; // vecteur vide par défaut
    int indice;
    vertex(int indice) : indice(indice) {}

    void add_edge(float k, vertex *target)
    {
        adjacants.push_back(edge(k, target));
    }
    int size()
    {
        this->adjacants; // vr: à quoi sert cette ligne ?
                         // vr: tu as oublié le return
        // adjacants.size();
        return adjacants.size();
    };
    int id() { return indice; }; // vr: pas besoin de ; ici

    // int indice() { return indice; };
    // vr: ne recopie par l'objet de type edge: renvoie une référence
    edge &arrete_k(int k)
    {
        this->adjacants; // vr: à quoi sert cette ligne ?
        return adjacants[k];
    }
};

class graph
{
    friend class vertex;
    friend class edge;
    std::vector<vertex> sommets;

public:
    void add_vertex(int id) { sommets.push_back(vertex(id)); }; // vr: pas besoin de ; ici

    void add_edge(int i, int j, float k)
    {
        sommets[i].add_edge(k, &sommets[j]);
    }
    int taille()
    {
        this->sommets; // vr: à quoi sert cette ligne ?
        return sommets.size();
    };
    int parcour_profondeur()
    {
        // vr: si tu ne retournes rien c++ v faire un warning
        // il ne faut jamais laisser des warnings incompris quand on compile un code
    }

    // vr: cette méthode doit passer dans la classe vertex
    // tu peux donner le même nom à cette fonction: parcours_profondeur
    // c++ fera la différence parce que leurs arguments sont différents
    // vr: cette fonction ne retourne rien ?
    int aux_parcours_profondeur(int i, std::vector<bool> *sommets_vus, std::vector<int> *resultat)
    {
        // vr: mets le sommet dans sommets_vus
        // vr: mets le dans resultats
        std::cout << i << std::endl;
        for (int k = 0; k < sommets[i].size(); k += 1)
        {
            vertex &sommet_traite = sommets[i];       // vr: ne recopie pas l'objet de type vertex: renvoie une référence !!
            edge &arrete = sommet_traite.arrete_k(k); // vr: idem !!
            vertex &sommet_arrive = arrete.cible();   // vr: ne pas recopier c'est une référence

            std::cout << i << " " << arrete.poids << " " << sommet_arrive.id() << std::endl;

            int indice_arrive = sommet_arrive.id();
            if (not(*sommets_vus)[indice_arrive])
            {
                // vr: à faire dans le parcours_profondeur du sommet indice_arrive
                (*sommets_vus)[indice_arrive] = true;
                (*resultat).push_back(indice_arrive);
                aux_parcours_profondeur(indice_arrive, sommets_vus, resultat);
            }; // vr: pas besoin de ; ici
        };     // vr: pas besoin de ; ici
    };

    // vr: tu fais le parcours en profondeur à partir du sommet i
    // pas le parcours de tout le graphe
    std::vector<int> parcour_profondeur(int i)
    {
        this->sommets;                                        // vr: à quoi sert cette ligne ?
        std::vector<bool> sommets_vus(sommets.size(), false); // vr: crée directement un vecteur de taille n rempli de false
        std::vector<int> resultats;
        const int n(sommets.size()); // vr: utilise sommet.size() au lieu de n
        // vr: plus besoin de cette boucle
        // for (int k = 0; k < n; k += 1)
        // {
        //     sommets_vus.push_back(false);
        // } //v r: pas besoin de ; ici
        // au debut on a vu aucun sommets

        // vr: à faire dans la méthode d'après plutôt
        sommets_vus[i] = true;
        // vr: appelle ici parcours_profondeur sur le sommet i en lui passant les vecteurs sommets_vus et resultats
        aux_parcours_profondeur(i, &sommets_vus, &resultats);

        // vr: j'affiche juste pour voir ce que ça donne
        for (auto i : resultats)
        {
            std::cout << i << std::endl;
        }
        return resultats;
    } // vr: pas besoin de ; ici
};

int main()
{
    graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_edge(0, 1, 1.2);
    g.add_edge(0, 2, 5.8);
    g.add_edge(1, 2, 1.7);
    g.add_edge(2, 3, 1.3);
    g.add_edge(3, 0, 8.5);
    g.add_edge(3, 1, 17.5);
    g.add_edge(3, 2, 1.5);
    g.add_edge(2, 1, 9.5);
    g.parcour_profondeur(0);
    return 0;
}