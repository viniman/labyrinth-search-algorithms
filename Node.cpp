//
// Created by viniman on 10/06/19.
//

#include "Node.h"


Node::Node(int id, unsigned int heuristicValue)
{
    this->id = id;
    this->heuristicValue = heuristicValue;


}

Node* Node::roomDirectionReturn(const char &op)
{
    switch (op)
    {
        case 'L':
            return left;
        case 'B':
            return botton;
        case 'R':
            return right;
        case 'T':
            return top;
        default:
            return nullptr;
    }
}

Node *Node::getRight() const
{
    return right;
}

Node *Node::getLeft() const
{
    return left;
}

Node *Node::getBotton() const
{
    return botton;
}

Node *Node::getTop() const
{
    return top;
}

Node *Node::getFather() const
{
    return father;
}

void Node::setFather(Node *father)
{
    this->father = father;
}

void Node::setRight(Node *right)
{
    Node::right = right;
}

char Node::getDirectionVisited() const
{
    return directionVisited;
}

void Node::setVisited()
{
    Node::alreadyVisited = true;
}

void Node::setNonVisited()
{
    Node::alreadyVisited = false;
}

char Node::getVisitedBy() const
{
    return visitedBy;
}

bool Node::isVisited() const
{
    if(this)
        return alreadyVisited;
    return true;
}

void Node::setDirectionVisited(char directionVisited)
{
    Node::directionVisited = directionVisited;
}

void Node::setVisitedBy(char visitedBy)
{
    Node::visitedBy = visitedBy;
}

void Node::setLeft(Node *left)
{
    Node::left = left;
}

void Node::setBotton(Node *botton)
{
    Node::botton = botton;
}

void Node::setTop(Node *top)
{
    Node::top = top;
}

void Node::setHeuristicValue(unsigned int heuristicValue)
{
    Node::heuristicValue = heuristicValue;
}

unsigned int Node::getHeuristicValue() const
{
    return heuristicValue;
}

unsigned int Node::getId() const
{
    return id;
}

int Node::getX() const
{
    return x;
}

int Node::getY() const
{
    return y;
}

void Node::setId(int id)
{
    Node::id = id;
}

void Node::setX(int x)
{
    Node::x = x;
}

void Node::setY(int y)
{
    Node::y = y;
}

Node::Node(int id)
{
    Node::id = id;
}

unsigned int Node::getdistanceOrigin()
{
    return distanceOrigin;
}

void Node::setdistanceOrigin(unsigned int distanceOrigin)
{

    this->distanceOrigin = distanceOrigin;

}

unsigned int Node::getsumHeurDist()
{

    return sumHeurDist;
}

void Node::setsumHeurDist(unsigned int sumHeurDist)
{

    this->sumHeurDist = sumHeurDist;

}