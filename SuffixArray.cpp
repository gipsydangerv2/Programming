#include <bits/stdc++.h>

using namespace std;
# define maxn 100001
string suffix[maxn];
struct ds{
    int index;
    int rank;
    int nextRank;
};
struct ds suffixes[maxn];
bool compare(const struct ds & s1,const struct ds &s2){
    if(s1.rank == s2.rank)
        return s1.nextRank < s2.nextRank;
    return s1.rank < s2.rank;
}
int main()
{
    string text = "banana";
    int n = text.size();
    for(int i=0;i<n;i++){
        string s = text.substr(i);
        suffix[i] = s;
        suffixes[i].index = i;
        suffixes[i].rank = s[0]-'a';
        suffixes[i].nextRank = (i+1<n?s[1]-'a':-1);
    }
    sort(suffixes,suffixes+n,compare);
    //cout << "----------------After sorting------------------\n";
    //cout << "-----index , string, rank, nextRank------------------\n";
    //for(int i=0;i<n;i++){
      //  cout << suffixes[i].index << " , " << suffixes[i].rank << " , " << suffixes[i].nextRank << "\n";
    //}
    for(int i=2;i<2*n;i*=2){
        int rank = 0;
        int prevRank = suffixes[0].rank;
        int prevNextRank = suffixes[0].nextRank;
        suffixes[0].rank = 0;
        string s = suffix[suffixes[0].index];
        if(i>= s.size())
            suffixes[0].nextRank = -1;
        int indices[n];
        indices[suffixes[0].index]=0;
        for(int j=1;j<n;j++){
            indices[suffixes[j].index]=j;
        }
        for(int j=1;j<n;j++){
            s = suffix[suffixes[j].index];
            if(prevRank==suffixes[j].rank && prevNextRank == suffixes[j].nextRank){
                suffixes[j].rank = rank;
                prevRank = suffixes[j].rank;
            }
            else{
                prevRank = suffixes[j].rank;
                suffixes[j].rank = ++rank;
            }
            prevNextRank = suffixes[j].nextRank;
            if(i>= s.size())
                suffixes[j].nextRank = -1;
            else{
                string sub = suffix[suffixes[j].index];
                sub = sub.substr(i);
                suffixes[j].nextRank = indices[sub.size()-1];
            }
        }
        //cout << "----------------Updated Ranks------------------\n";
        //cout << "-----index , string, rank, nextRank------------------\n";
        //for(int j=0;j<n;j++){
          //  cout << suffixes[j].index << " , " << suffixes[j].rank << " , " << suffixes[j].nextRank << "\n";
        //}
        sort(suffixes,suffixes+n,compare);
        //cout << "----------------After sorting------------------\n";
        //cout << "-----index , string, rank, nextRank------------------\n";
        //for(int j=0;j<n;j++){
          //  cout << suffixes[j].index << " , " << suffixes[j].rank << " , " << suffixes[j].nextRank << "\n";
        //}
        }
    for(int i=0;i<n;i++){
        cout << suffixes[i].index << " " << suffix[suffixes[i].index] << "\n";
    }
    return 0;
}
