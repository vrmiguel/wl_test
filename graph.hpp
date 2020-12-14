#ifndef __GRAPH_HPP
#define __GRAPH_HPP

#include <cstdint>
#include <vector>
#include <list>

typedef uint32_t u32;
typedef uint64_t u64;
#include <iostream>
#include <vector>
using namespace std;

//class Graph
//{
//    size_t m_vertices;
//    size_t m_edges;
//};

class UndirectedGraph
{
    size_t m_vertices;
    size_t m_edges;
    public:
    //!
    //! \brief adjacencies is the adjacency list
    //! that represents the graph.
    //!
    std::vector<std::vector<u32>> adjacencies;
    struct Edge
    {
        u32 src, dest;
        Edge (u32 _src, u32 _dest) : src(_src), dest(_dest) {}
    };

    UndirectedGraph(u64 number_of_vertices) : m_vertices(number_of_vertices), m_edges(0)
    {
        adjacencies.resize(number_of_vertices);
    }

    void add_edge(const Edge& edge)
    {
        m_edges++;
        adjacencies[edge.src].push_back(edge.dest);
        adjacencies[edge.dest].push_back(edge.src);
    }

    size_t vertices() const {
        return m_vertices;
    }

    size_t edges() const {
        return m_edges;
    }
};


ostream & operator << (ostream &out, const UndirectedGraph & graph)
{
    out << "Edges: " << graph.edges() << '\n';
    out << "Vertices: " << graph.vertices() << '\n';
    for (size_t i = 0; i < graph.vertices(); i++)
    {
        out << i << " --> ";

        for (int v : graph.adjacencies[i])
        {
            out << v << " ";
        }
        out << endl;
    }
    return out;
}

#endif // __GRAPH_HPP
