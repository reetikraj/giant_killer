class Solution {
public:
    struct Trie {
        vector<Trie*>children;
        int count;
    };
    Trie* getTrieNode(){
        Trie* node = new Trie();
        node->count=0;
        for(int i=0;i<2;i++){
            node->children.push_back(NULL);
        }
        return node;
    }
    void insert(Trie* root, int num){
        for(int i=14;i>=0;i--){
            int temp=0;
            if(num&(1<<i))temp=1;
            if(root->children[temp]==NULL){
                root->children[temp]=getTrieNode();
            }
            root=root->children[temp];
            root->count++;
        }
    }
    int countLesser(Trie* root, int num, int limit){
        int ans=0;
        for(int i=14;i>=0;i--){
            int numBit=0;
            int limitBit=0;
            if(num&(1<<i))numBit=1;
            if(limit&(1<<i))limitBit=1;
            if(limitBit==0){
                if(root->children[numBit]==NULL)return ans;
                root=root->children[numBit];
            } else {
                if(root->children[numBit])ans+=root->children[numBit]->count;
                if(root->children[!numBit]==NULL)return ans;
                root=root->children[!numBit];
            }
        }
        return ans;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size();
        Trie* root = getTrieNode();
        int ans=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            ans+=countLesser(root,num,high+1)-countLesser(root,num,low);
            insert(root,num);
        }
        return ans;
    }
};
