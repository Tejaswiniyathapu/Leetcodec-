typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEnd;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

TrieNode* trieNodeCreate() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = false;
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = trieNodeCreate();
    return trie;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* node = obj->root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!node->children[index])
            node->children[index] = trieNodeCreate();
        node = node->children[index];
    }
    node->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* node = obj->root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }
    return node->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* node = obj->root;
    for (int i = 0; prefix[i]; i++) {
        int index = prefix[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }
    return true;
}

void trieFreeNode(TrieNode* node) {
    for (int i = 0; i < 26; i++)
        if (node->children[i])
            trieFreeNode(node->children[i]);
    free(node);
}

void trieFree(Trie* obj) {
    trieFreeNode(obj->root);
    free(obj);
}



