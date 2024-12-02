#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Graph data structures
map<string, vector<string>> adj; // Adjacency list
map<string, ll> clr_mask, clr_id; // Bitmask for reachable colors and IDs for colors
map<string, string> curr_open;   // Tracks currently "open" paths for colors

ll total_switches = 0; // Tracks the number of path switches

// DFS1: Compute bitmask for reachable colors from each node
ll computeMask(string &node) {
    ll current_mask = clr_id.count(node) ? (1LL << clr_id[node]) : 0; // If the node is a color, set its bit
    for (string &child : adj[node]) {
        current_mask |= computeMask(child); // Merge bitmask from child nodes
    }
    clr_mask[node] = current_mask; // Store the computed bitmask
    return current_mask;
}

// DFS2: Route each ball and count the number of path switches
void routeBall(string &node, int bit) {
    if (clr_id[node] == bit) {  // If the current node matches the color bit
        curr_open[node] = node; // Mark it as opened
        return;
    }
    for (string &child : adj[node]) {
        if (clr_mask[child] >> bit & 1) {  // Check if the child has the desired color
            if (curr_open[node] != child) total_switches++, curr_open[node] = child; // Switch path if needed
            routeBall(child, bit); // Recur into the child
            return;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    cin.ignore(); // Ignore newline after the number

    // Read the graph structure
    while (n--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> nodes((istream_iterator<string>(ss)), istream_iterator<string>());
        string parent = nodes[0];
        nodes.erase(nodes.begin());
        adj[parent] = nodes; // Add parent and its children to the graph
    }

    // Assign unique IDs to colors
    ll color_id = 0;
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> colors((istream_iterator<string>(ss)), istream_iterator<string>());

    for (auto &clr : colors) {
        if (!clr_id.count(clr)) clr_id[clr] = ++color_id;
    }

    // Start DFS from the "source" node
    string source = "source";
    computeMask(source);

    // Route each ball
    for (auto &color : colors) {
        routeBall(source, clr_id[color]);
    }
    cout << total_switches << endl;
    return 0;
}
