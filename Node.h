//
// Created by viniman on 10/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_NODE_H
#define AI_MAZE_SEARCH_ALGORITHMS_NODE_H


class Node
{
private:
    char directionVisited = 'N';
    char visitedBy = 'N';
    bool alreadyVisited = false;
    unsigned int heuristicValue;
    unsigned int distanceOrigin = 0;
    unsigned int sumHeurDist = 0;
    int id;
    int x;
    int y;
    Node* right = nullptr;
    Node* left = nullptr;
    Node* botton = nullptr;
    Node* top = nullptr;
    Node* father = nullptr;
    bool adicionadoLista = false;
    int profundidade =  0;
    int sucessores = 0;
public:
    explicit Node(int id);
    Node(int id, unsigned int heuristicValue);
    void setHeuristicValue(unsigned int heuristicValue);
    void setId(int id);
    void setX(int x);
    void setY(int y);
    Node *getRight() const;
    Node *getLeft() const;
    Node *getBotton() const;
    Node *getTop() const;
    Node *getFather() const;
    void setRight(Node *right);
    void setLeft(Node *left);
    void setBotton(Node *botton);
    void setTop(Node *top);
    void setFather(Node *father);
    Node* roomDirectionReturn(const char &op);
    char getDirectionVisited() const;
    char getVisitedBy() const;
    bool isVisited() const;
    void setVisited();
    void setNonVisited();
    void setDirectionVisited(char directionVisited);
    void setVisitedBy(char visitedBy);
    unsigned int getHeuristicValue() const;
    unsigned int getId() const;
    int getX() const;
    int getY() const;
    unsigned int getdistanceOrigin();
    void setdistanceOrigin(unsigned int distanceOrigin);
    unsigned int getsumHeurDist();
    void setsumHeurDist(unsigned int sumHeurDist);
    void adicionarNodeLista(){adicionadoLista = true;}
    void removerNodeLista(){adicionadoLista = false;}
    bool getAdicionadoNodeLista(){return adicionadoLista;}
    void setProfundidade(int profundidade){this->profundidade = profundidade;}
    int getProfundidade(){ return profundidade;}
    void setSucessores(){sucessores += 1;}
    int getSucessores(){return sucessores;}
    void zerarSucessores(){sucessores = 0;}


};


#endif //AI_MAZE_SEARCH_ALGORITHMS_NODE_H
