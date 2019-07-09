//
// Created by viniman on 07/06/19.
//

// https://stackoverflow.com/questions/15160889/how-can-i-make-an-unordered-set-of-pairs-of-integers-in-c
// https://stackoverflow.com/questions/53796118/alternative-to-find-for-determining-whether-an-unordered-set-contains-a-key

#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include "Utils.h"
#include "Maze.h"

using namespace std;

Maze Utils::instanceReader(const string &instancePathName)
{

}

/**
 * Mazes generated with a depth-first search have a low branching factor and contain many long corridors,
 * because the algorithm explores as far as possible along each branch before backtracking. [Wikipedia]
 * @param m
 * @param n
 * @return
 */
Maze * Utils::mazeGenerator(unsigned int m, unsigned int n)
{
    srand (time(NULL));
    //vector<char> operations = {'L', 'R', 'T', 'B'};
    Maze* maze = new Maze(m, n, true);
    // Criacao com nenhuma porta, como se tivesse parede entre todos
    Maze* mazeGenerated = new Maze(m, n, false);

    stack<Node*> stackRooms;
    Node *currentCell = maze->getRoom(0);
    currentCell->setVisited();
    mazeGenerated->setOrigin(currentCell->getId());

    unsigned int countVisited = 1;

    while (countVisited < maze->getNumRooms())
    {
        if (!currentCell->getRight()->isVisited() || !currentCell->getLeft()->isVisited() ||
            !currentCell->getTop()->isVisited() || !currentCell->getBotton()->isVisited())
        {

            vector<char> notVisited;
            if (currentCell->getRight() && !currentCell->getRight()->isVisited())
                notVisited.push_back('R');
            if (currentCell->getLeft() && !currentCell->getLeft()->isVisited())
                notVisited.push_back('L');
            if (currentCell->getTop() && !currentCell->getTop()->isVisited())
                notVisited.push_back('T');
            if (currentCell->getBotton() && !currentCell->getBotton()->isVisited())
                notVisited.push_back('B');

            unsigned long ranPos = rand() % notVisited.size();
            Node *choosenCell = currentCell->roomDirectionReturn(notVisited[ranPos]);

            stackRooms.push(currentCell);

            mazeGenerated->addDoor(currentCell->getId(), choosenCell->getId());

            currentCell = choosenCell;
            currentCell->setVisited();
            ++countVisited;
        }
        else if (!stackRooms.empty())
        {

            currentCell = stackRooms.top();
            stackRooms.pop();
        }
    }
    mazeGenerated->setDestination((m*n)-1);
    cout << "Labirinto gerado" << endl;
    delete maze;
    return mazeGenerated;
}

///long long int ???
bool Utils::emptyRoom(unsigned long long int& iterator, unsigned long long int& room, unsigned int& m, unsigned int& n, unsigned int& r){
    if(r - room + 1 == n * m - iterator)
        return false;
    else
        return rand() % 100 < ((double) r/(m*n)) * 100 - 5;
}

/*
namespace std {
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };

}
*/

//auto hash = [](const std::pair<int, int>& p){ return p.first * 31 + p.second; };
//std::unordered_set<std::pair<int, int>, decltype(hash)> u_edge_(8, hash);

void Utils::newGenerator(unsigned int m, unsigned int n, unsigned int roomsWithDoor)
{
    unsigned long long int * M = nullptr, room = 1, origin = 0, destination = 0;

    stringstream fileString;
    fstream file;

    srand(time(NULL));

    M = new unsigned long long int[m * n];

    for(unsigned long long int i = 0; i < m * n; ++i){
        if(room > roomsWithDoor || emptyRoom(i, room, m, n, roomsWithDoor))
            M[i] = 0;
        else {
            if(room == 1)
                origin = i;
            else if(room == roomsWithDoor)
                destination = i;

            M[i] = room++;
        }
    }

    fileString << "instance_" << m << "_" << n << "_" << roomsWithDoor << "_" << origin << "_" << destination  << ".in";
    file.open(fileString.str(), fstream::out);

    file << m << " " << n << " " << roomsWithDoor << " " << M[origin] << " " << M[destination] << "\n";




    ///////////////////////////////////////////////////////////////////////////////
    long long int rooms = roomsWithDoor,  currentPosition, i = 0, j = 0;

    //inputFile >> m >> n >> rooms >> origin >> destination;
    auto hash = [](const std::pair<int, int>& p){ return p.first * 31 + p.second; };
    std::unordered_set<std::pair<int, int>, decltype(hash)> set(8, hash);

    //unordered_set <pair<int,int>> set;

    vector<long long int> matrix(m * n, 0);

    for(i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            matrix[i * n + j] = M[i * n + j];

    for(i = 0; i < m; ++i){
        for(j = 0; j < n; ++j){
            currentPosition = i * n + j;
            if(!matrix[currentPosition])
                continue;
            if(j != n - 1 && matrix[currentPosition + 1] && !set.count(make_pair(currentPosition + 1, currentPosition)) && !set.count(make_pair(currentPosition, currentPosition + 1)))
            {
                file << matrix[currentPosition] << " " << matrix[currentPosition + 1] << endl;//maze->addDoor(matrix[currentPosition], matrix[currentPosition + 1], 'R');
                set.insert(make_pair(currentPosition, currentPosition + 1));
            }
            if(j != 0 && matrix[currentPosition - 1] && !set.count(make_pair(currentPosition - 1, currentPosition)) && !set.count(make_pair(currentPosition, currentPosition - 1)))
            {
                file << matrix[currentPosition] << " " << matrix[currentPosition - 1] << endl;//maze->addDoor(matrix[currentPosition], matrix[currentPosition - 1], 'L');
                set.insert(make_pair(currentPosition, currentPosition - 1));
            }
            if(i != m - 1 && matrix[currentPosition + n] && !set.count(make_pair(currentPosition + n, currentPosition)) && !set.count(make_pair(currentPosition, currentPosition + n)))
            {
                file << matrix[currentPosition] << " " << matrix[currentPosition + n] << endl;//maze->addDoor(matrix[currentPosition], matrix[currentPosition + n], 'B');
                set.insert(make_pair(currentPosition, currentPosition + n));
            }
            if(i != 0 && matrix[currentPosition - n] && !set.count(make_pair(currentPosition - n, currentPosition)) && !set.count(make_pair(currentPosition, currentPosition - n)))
            {
                file << matrix[currentPosition] << " " << matrix[currentPosition - n] << endl;//maze->addDoor(matrix[currentPosition], matrix[currentPosition - n], 'T');
                set.insert(make_pair(currentPosition, currentPosition - n));
            }
        }
    }



    ///////////////////////////////////////////////////////////////////////////////


   /*

    for(long long int i = 0; i < m; ++i){
        for(long long int j = 0; j < n; ++j){
            file << M[i * n + j] << " ";
        }
        file << "\n";
    }

    for(long long int i = 0; i < m; ++i){
        for(long long int j = 0; j < n; ++j){
            if(M[i * n + j])
                file << M[i * n + j] << " " << getManhattanDistance(i, j, destination) << "\n";
        }
    }*/

    file.close();
}