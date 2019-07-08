#include <iostream>
#include <string>
#include <set>
#include <sstream>

#include "Maze.h"
#include "Utils.h"
#include "Backtracking.h"
#include "Depth.h"
#include "Greedy.h"
#include "AStar.h"

using namespace std;




int main(int argc, char** argv)
{
    string instanceFileName = "/home/igor/Documentos/ai-maze-search-algorithms/instances/instance10_10_2.in";
    Maze maze(instanceFileName);
    //Backtracking::backtrackingSearchAlgorithm(maze);
    //Depth::DepthSearchAlgorithm(maze);

    //Greedy::greedySearchAlgorithm(maze);

    AStar::ASearchAlgorithm(maze);

    return 0;
}