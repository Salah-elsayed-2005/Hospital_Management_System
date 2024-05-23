#ifndef SHORTEST_PATH_HOSPITAL_CITYGRAPH_H
#define SHORTEST_PATH_HOSPITAL_CITYGRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <utility>

using namespace std;

class CityGraph {
    vector<vector<pair<int,int>>> adj;

    unordered_map<int, int> estimates;
    unordered_map<int,int> precedence;


    void buildSampleGraph();

public:
    unordered_map<string, int> districts;
    unordered_map<int, string> streets;

    CityGraph();

    void buildSampleDistricts();
    void buildSampleStreets();
    void generateShortestPaths();
    pair<int, string> shortestPath(string);

};


#endif //SHORTEST_PATH_HOSPITAL_CITYGRAPH_H
