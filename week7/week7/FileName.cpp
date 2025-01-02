#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <string>


void drawGraph(const std::vector<int>& nodes, const std::vector<std::pair<int, int>>& edges) {
    Agraph_t* g = agopen((char*)"DirectedGraph", Agdirected, nullptr);

    // Map to store nodes
    std::map<int, Agnode_t*> graphNodes;

    // Add nodes to the graph
    for (const auto& node : nodes) {
        std::string label = std::to_string(node);
        graphNodes[node] = agnode(g, (char*)label.c_str(), 1);
    }

    // Add edges to the graph
    for (const auto& edge : edges) {
        std::string labelU = std::to_string(edge.first);
        std::string labelV = std::to_string(edge.second);
        agedge(g, graphNodes[edge.first], graphNodes[edge.second], nullptr, 1);
    }

    // Output the graph to a DOT file
    FILE* output = fopen("graph.dot", "w");
    agwrite(g, output);
    fclose(output);

    // Free memory used by the graph
    agclose(g);

    std::cout << "Graph saved to 'graph.dot'. You can visualize it using Graphviz." << std::endl;
}

int main() {
    // Define nodes and edges
    std::vector<int> nodes = { 1, 2, 3, 4, 5 };
    std::vector<std::pair<int, int>> edges = {
        {1, 2}, {1, 3}, {1, 4},
        {2, 1}, {2, 3}, {2, 5},
        {3, 1}, {3, 2}, {3, 4}, {3, 5},
        {4, 2},
        {5, 1}, {5, 3}
    };

    // Draw the graph
    drawGraph(nodes, edges);

    return 0;
}
