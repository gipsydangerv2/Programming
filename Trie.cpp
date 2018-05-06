# include<bits/stdc++.h>
using namespace std;
# define maxchild 26
struct tnode {
    struct tnode *child[maxchild];
    bool isLeaf;
    int priority;
};
struct tnode * newNode(){
    struct tnode * trie = (struct tnode*)malloc(sizeof(struct tnode));
    trie->isLeaf = false;
    trie->priority= 0;
    for(int i=0;i<maxchild;i++)
        trie->child[i]=NULL;
    return trie;
}
void insertWord(struct tnode *node,string str,int priority){
    struct tnode* temp = node;
    int len = str.length();
    for(int i=0;i<len;i++){
        int idx = str[i]-'a';
        if(temp->child[idx]==NULL){
            temp->child[idx]=newNode();
        }
        temp = temp->child[idx];
        temp->priority = max(priority,temp->priority);
    }
    temp->isLeaf = true;
    temp->priority = priority;
}
int hasWord(struct tnode * node,string s){
    int len = s.length();
    for(int i=0;i<len;i++){
        int idx = s[i]-'a';
        if(!node->child[idx])
            return 0;
        else{
            node = node->child[idx];
        }
    }
    return (node != NULL && node->isLeaf == true);
}
int prefixWithMaxPriority(struct tnode * node,string s){
    int maxp = -1;
    int len = s.length();
    for(int i=0;i<len;i++){
        int idx = s[i]-'a';
        if(!node->child[idx])
            return -1;
        else{
            node = node->child[idx];
        }
    }
    if(node != NULL){
        maxp = node->priority;
    }
    return maxp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    struct tnode * trie = newNode();
    int n,q,p;
    string str;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> str >> p;
        insertWord(trie,str,p);
    }
    for(int i=0;i<q;i++){
        cin >> str;
        cout << prefixWithMaxPriority(trie,str) << "\n";
    }
    
    return 0;
}
