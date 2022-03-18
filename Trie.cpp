struct Trie {
    vector<Trie*>children;
    bool isEnd;
};
Trie* getTrieNode(){
    Trie* node=new Trie();
    for(int i=0;i<2;i++){
        node->children.push_back(NULL);
    }
    node->isEnd=false;
    return node;
}
void insert(Trie* root, int num){
    for(int i=31;i>=0;i--){
        int temp=0;
        if(num & (1<<i))temp=1;
        if(root->children[temp]==NULL){
            root->children[temp]= getTrieNode();
            root=root->children[temp];
        } else {
            root=root->children[temp];
        }
    }
    root->isEnd=true;
}
