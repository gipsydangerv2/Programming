#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>a;
    a.insert(10);
    a.insert(20);
    a.insert(30);   // takes 0(log n) time
    set<int>::iterator it;
    it = a.find(10); // takes o(log n) time
    pair<set<int>::iterator,bool>ret;
    ret = a.insert(10); // no element inserted
    if(ret.second==false)
        it=ret.first;
    a.erase(it);    // removes an item from set
    a.erase(10);    // same as above

    return 0;
}
