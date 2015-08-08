// Disjoint_set 
// Find by Path Compression and Union by Rank
class Disjoint_set{
    unordered_map<char,char>parent;
    unordered_map<char,int>ranks;
public:
    Disjoint_set(){
        char universe []={'a','b','c','d','e'};
        for(char c : universe){
            parent[c]=c;
            ranks[c]=0;
        }
        parent['d']='b';
        ranks['b']++;
    }
    char FIND(char item){
        if(parent[item]==item)
            return item;
        else
            return parent[item]=FIND(parent[item]);
    }
    void UNION(char set_1,char set_2){
        if(ranks[set_1]<ranks[set_2])
            ranks[set_1]=set_2;
        else if(ranks[set_1]>ranks[set_2])
            ranks[set_2]=set_1;
        else{
            ranks[set_1]=set_2;
            ranks[set_2]++;
        }
    }

};
