#include <iostream>

using namespace std;

#include "graph.hpp"
#include "weisfeiler_lehman.hpp"


int main()
{
//    vector<UndirectedGraph::Edge> edges =
//    {
//        {0, 1}, {1, 2}, {2, 0}, {2, 1},
//        {3, 2}, {4, 5}, {5, 4}
//    };

    vector<UndirectedGraph::Edge> edges_g1 =
    {
        {0, 3}, {0, 4}, {1, 4}, {4, 2}, {2, 5}, {5, 1}, {1, 3}, {0, 5}, {2, 3}
    };


    vector<UndirectedGraph::Edge> edges_g2 =
    {
        {0, 3}, {0, 1}, {0, 5}, {5, 4}, {1, 2}, {4, 3}, {2, 3}, {2, 5}, {4, 1}
    };



    // 6 vértices no grafo
    UndirectedGraph g1(6);
    UndirectedGraph g2(6);

    for(auto edge : edges_g1)
    {
        g1.add_edge(edge);
    }

    for(auto edge : edges_g2)
    {
        g2.add_edge(edge);
    }

    std::cout << g1 << '\n';
    std::cout << g2 << '\n';

    std::cout << "Result: " <<
    wl_test(g1, g2) << '\n';

    return 0;

}
