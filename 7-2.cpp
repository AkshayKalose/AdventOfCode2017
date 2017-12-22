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

int get_total_weight(unordered_map<string, Node*>& nodes, const Node* root) {
    int total_weight = root->weight;
    for (const string& outgoing_name : root->outgoing) {
        total_weight += get_total_weight(nodes, nodes[outgoing_name]);
    }
    return total_weight;
}

size_t find_unique_index(vector<pair<string, int>>& total_weights) {
    unordered_map<int, size_t> frequency;
    for (const pair<string, size_t>& pair : total_weights) {
        frequency[pair.second]++;
    }
    int weight = numeric_limits<int>::max();
    size_t lowest_frequency = numeric_limits<size_t>::max();
    for (const pair<int, size_t>& pair : frequency) {
        if (pair.second < lowest_frequency) {
            lowest_frequency = pair.second;
            weight = pair.first;
        }
    }
    for (size_t i = 0; i < total_weights.size(); i++) {
        if (total_weights[i].second == weight) return i;
    }
    return -1;
}

bool find_unbalance(unordered_map<string, Node*>& nodes, const Node* root) {
    vector<pair<string, int>> total_weights;
    int total_weight = -1;
    bool unbalanced = false;
    for (const string& outgoing_name : root->outgoing) {
        Node* outgoing_node = nodes[outgoing_name];
        int outgoing_total_weight = get_total_weight(nodes, outgoing_node);
        total_weights.push_back(make_pair(outgoing_name, outgoing_total_weight));
        if (unbalanced == false && total_weight != -1 && total_weight != outgoing_total_weight) unbalanced = true;
        total_weight = outgoing_total_weight;
    }
    if (unbalanced) {
        size_t unique_index = find_unique_index(total_weights);
        Node *unique_node = nodes[total_weights[unique_index].first];

        if (!find_unbalance(nodes, unique_node)) {

            int other_node_weight;
            if (unique_index + 1 < total_weights.size()) {
                other_node_weight = total_weights[unique_index + 1].second;
            } else {
                other_node_weight = total_weights[unique_index - 1].second;
            }

            int change = other_node_weight - total_weights[unique_index].second;

            cout << unique_node->weight + change;
        }
        return true;
    } else {
        return false;
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

    cout << root->name << endl;

    find_unbalance(nodes, root);
}
