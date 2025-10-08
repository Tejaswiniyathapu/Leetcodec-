class Solution {
private:
    unordered_map<Node*, Node*> visited; // original -> clone

    Node* cloneDFS(Node* node) {
        if (!node) return nullptr;
        if (visited.count(node)) return visited[node];

        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneDFS(neighbor));
        }

        return cloneNode;
    }

public:
    Node* cloneGraph(Node* node) {
        return cloneDFS(node);
    }
};
