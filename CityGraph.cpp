
#include "CityGraph.h"

void CityGraph::buildSampleGraph() {

    adj.push_back({{2, 5}, {4, 4}, {6, 6}});   // 0
    adj.push_back({{6, 3}, {7, 7}, {9, 2}});   // 1
    adj.push_back({{0, 5}, {7, 2}});                 // 2
    adj.push_back({{5, 4}, {8, 7}, {6, 4}});   // 3
    adj.push_back({{0, 4}, {7, 10}, {8, 3}});  // 4
    adj.push_back({{8, 3}, {3, 4}});                 // 5
    adj.push_back({{3, 4}, {0, 6}, {1, 3}});   // 6
    adj.push_back({{1, 7}, {2, 2}, {4, 10}});  // 7
    adj.push_back({{5, 3}, {3, 7}, {4, 3}});   // 8
    adj.push_back({{1, 2}});                               // 9
}

CityGraph::CityGraph() {
    buildSampleGraph();
    buildSampleDistricts();
    buildSampleStreets();
}


struct secondMinCompare {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2) {
        return p1.second > p2.second;
    }
};

void CityGraph::generateShortestPaths() {

    priority_queue<pair<int,int>, vector<pair<int,int>>, secondMinCompare> estimatesQ;

    estimatesQ.push({0, 0});
    estimates[0] = 0;
    precedence[0] = -1;

    for(int i = 1; i < adj.size(); i++){
        estimates[i] = INT_MAX;
    }

    while(!estimatesQ.empty()){
        int curr = estimatesQ.top().first;
        int curr_estimate = estimatesQ.top().second;
        estimatesQ.pop();

        if(curr_estimate > estimates[curr])
            continue;

        for(int i = 0; i < adj[curr].size(); i++){

            int neighbor = adj[curr][i].first;
            int distance = adj[curr][i].second;
            int new_estimate = estimates[curr] + distance;

            if(new_estimate < estimates[neighbor]){
                estimates[neighbor] = new_estimate;
                estimatesQ.push({neighbor, estimates[neighbor]});

                precedence[neighbor] = curr;
            }
        }
    }
}

void CityGraph::buildSampleDistricts() {
    districts["Riverside Hospital"] = 0;
    districts["Maple Grove Residences"] = 1;
    districts["Willow Heights"] = 2;
    districts["Sunset Pines Apartments"] = 3;
    districts["Cedar Ridge Villas"] = 4;
    districts["Lakeside Manor"] = 5;
    districts["Harbor View Estates"] = 6;
    districts["Oakwood Park Residences"] = 7;
    districts["Riverstone Apartments"] = 8;
    districts["Meadowlark Homes"] = 9;
}

void CityGraph::buildSampleStreets() {
    streets[02] =  "Community Way";
    streets[20] =  "Community Way";

    streets[04] =  "Metropolis Street";
    streets[40] =  "Metropolis Street";

    streets[06] =  "Boundary Boulevard";
    streets[60] =  "Boundary Boulevard";

    streets[47] =  "Mountain Ridge Road";
    streets[74] =  "Mountain Ridge Road";

    streets[27] =  "Elmwood Avenue";
    streets[72] =  "Elmwood Avenue";

    streets[17] =  "Cityscape Avenue";
    streets[71] =  "Cityscape Avenue";

    streets[19] =  "District Drive";
    streets[91] =  "District Drive";

    streets[16] =  "Orchid Lane";
    streets[61] =  "Orchid Lane";

    streets[48] =  "Rosewood Drive";
    streets[84] =  "Rosewood Drive";

    streets[38] =  "Springtime Lane";
    streets[83] =  "Springtime Lane";

    streets[58] =  "Lakeview Terrace";
    streets[85] =  "Lakeview Terrace";

    streets[35] =  "Aspen Avenue";
    streets[53] =  "Aspen Avenue";

    streets[36] =  "Pinehurst Street";
    streets[63] =  "Pinehurst Street";
}

pair<int, string> CityGraph::shortestPath(string destination_str) {

    int destination = districts[destination_str];

    stack<int> route_stk;
    for(int curr = destination; curr != 0; curr = precedence[curr]){
        route_stk.push(curr * 10 + precedence[curr]);
    }

    pair<int, string> eta_route;

    eta_route.first = estimates[destination];
    eta_route.second = "";

    while(!route_stk.empty()){
        eta_route.second += streets[route_stk.top()];
        eta_route.second += " > ";
        route_stk.pop();
    }
    eta_route.second.pop_back();
    eta_route.second.pop_back();
    eta_route.second.pop_back();

    return eta_route;
}
