#ifndef WEISFEILER_LEHMAN_H
#define WEISFEILER_LEHMAN_H

#include "graph.hpp"
#include <algorithm>

static inline int multisethash(const std::vector<int> &V) {
    int hash = V.size();
    for(unsigned int i = 0; i < V.size(); i++) {
        hash ^= V[i] + 0x9e3779b9 + (hash >> 2);
    }
    return hash;
}

//!
//! \brief wl_test
//! \param g1 A graph
//! \param g2 Another graph
//! \return If the tests returns false, then both graphs are assuredly not isomorphic.
//! However, if the test returns true, then both graphs are not guaranteed to be isomorphic.
//!
bool wl_test (const UndirectedGraph& g1, const UndirectedGraph& g2)
{
    //! Both graphs must have the same number of vertices to be isomorphic
    if (g1.vertices() != g2.vertices())
    {
        return false;
    }

    //! Both graphs must have the same number of edges to be isomorphic
    if (g1.edges() != g2.edges())
    {
        return false;
    }

    //!
    //! \brief compressed_labels
    //!
    std::vector<int> compressed_labels_g1 (g1.vertices(), 1);
    std::vector <std::vector<int>> multisets1(g1.vertices());

    std::vector<int> compressed_labels_g2 (g1.vertices(), 1);
    std::vector <std::vector<int>> multisets2 (g1.vertices());

    // There will be 10 iterations of the algorithm
    for (int __i = 0; __i < 10; __i++)
    {
        // Updating multisets
        for (size_t i = 0; i < g1.vertices(); i++)
        {
            for (int v : g1.adjacencies[i])
            {
                multisets1[i].push_back(compressed_labels_g1[v]);
            }

            for (int v : g2.adjacencies[i])
            {
                multisets2[i].push_back(compressed_labels_g2[v]);
            }

            std::sort(multisets1[i].begin(), multisets1[i].end());
            std::sort(multisets2[i].begin(), multisets2[i].end());
        }

        // Creating new compressed labels by hashing vector
        for (size_t i = 0; i < g1.vertices(); i++)
        {
            compressed_labels_g1[i] = multisethash(multisets1[i]);
            compressed_labels_g2[i] = multisethash(multisets2[i]);
        }
    }

    std::vector<int> canonical_form_g1;
    std::vector<int> canonical_form_g2;

    for (std::vector<int> set : multisets1)
    {
        for (int val : set)
        {
            canonical_form_g1.push_back(val);
        }
    }

    for (std::vector<int> set : multisets2)
    {
        for (int val : set)
        {
            canonical_form_g2.push_back(val);
        }
    }

    std::sort(canonical_form_g1.begin(), canonical_form_g1.end());
    std::sort(canonical_form_g2.begin(), canonical_form_g2.end());

    return canonical_form_g1 == canonical_form_g2;
}

#endif // WEISFEILER_LEHMAN_H
