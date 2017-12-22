#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <regex>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

struct Node {
    string name;
    int weight;
    vector<string> incoming;
    vector<string> outgoing;
};

void insert_node(unordered_map<string, Node*>& nodes, const string& line) {
    smatch sm;
    regex_match(line, sm, regex("(\\w*) \\((\\d*)\\)(?: -> ([\\w, ]*))?"));

    Node* node;
    if (nodes.find(sm[1]) == nodes.end()) {
        node = new Node;
        nodes[sm[1]] = node;
    } else {
        node = nodes[sm[1]];
    }
    node->name = sm[1];
    node->weight = stoi(sm[2]);

    if (sm[3].length() != 0) {
        string outgoing(sm[3]);
        outgoing.erase(remove(outgoing.begin(), outgoing.end(), ','), outgoing.end());
        vector<string> outgoing_names;
        readvalues(outgoing, outgoing_names);
        for (const string& outgoing_name : outgoing_names) {
            node->outgoing.push_back(outgoing_name);
            Node* outgoing_node;
            if (nodes.find(outgoing_name) == nodes.end()) {
                outgoing_node = new Node;
                nodes[outgoing_name] = outgoing_node;
            } else {
                outgoing_node = nodes[outgoing_name];
            }
            outgoing_node->incoming.push_back(sm[1]);
        }
    }
}

int main() {
    vector<string> lines;
    readlines(lines);

    unordered_map<string, Node*> nodes;

    for (const string& line : lines) {
        insert_node(nodes, line);
    }

    Node *root = nodes.begin()->second;
    while (root->incoming.size() != 0) {
        root = nodes[root->incoming[0]];
    }

    cout << root->name;
}
