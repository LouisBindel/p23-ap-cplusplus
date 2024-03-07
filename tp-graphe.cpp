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
    edge(float value = 0, vertex *cible) : poids(value), target(cible){};
    // vertex target() { return *target; };
    vertex cible() { return *target; };
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
        this->adjacants;
        adjacants.size();
    };
    int id() { return indice; };

    // int indice() { return indice; };
    edge arrete_k(int k)
    {
        this->adjacants;
        return adjacants[k];
    }
};

class graph
{
    friend class vertex;
    friend class edge;
    std::vector<vertex> sommets;

public:
    void add_vertex(int id) { sommets.push_back(vertex(id)); };
    void add_edge(int i, int j, float k)
    {
        sommets[i].add_edge(k, &sommets[j]);
    }
    int taille()
    {
        this->sommets;
        return sommets.size();
    };
    int parcour_profondeur()
    {
    }
    int aux_parcours_profondeur(int i, std::vector<bool>  *sommets_vus, std::vector<int> *resultat)
    {
        std::cout << i << std::endl;
        for (int k = 0; k < sommets[i].size(); k += 1)
        {
            vertex sommet_traite = sommets[i];
            edge arrete = sommet_traite.arrete_k(k);
            vertex sommet_arrive = arrete.cible();
            int indice_arrive = sommet_arrive.id();
            if (not (*sommets_vus)[indice_arrive])
            {
                (*sommets_vus)[indice_arrive] = true;
                (*resultat).push_back(indice_arrive);
                aux_parcours_profondeur(indice_arrive, sommets_vus, resultat);
            };
        };
    };

    std::vector<int> parcour_profondeur(int i)
    {
        this->sommets;
        std::vector<bool> sommets_vus;
        std::vector<int> resultats;
        const int n(sommets.size());
        for (int k = 0; k < n; k += 1)
        {
            sommets_vus.push_back(false);
        };
        // au debut on a vu aucun sommets
        sommets_vus[i]=true;
        aux_parcours_profondeur(i, &sommets_vus, &resultats);
        return resultats;
    };
};

