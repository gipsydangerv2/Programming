/*
*map
*
*
*/
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<char,int>mymap;
    mymap.insert(pair<char,int>('a',1));
    mymap.insert(make_pair('b',2));

    map<char,int>::iterator it = mymap.begin();
    mymap.insert(it,make_pair('c',3));
    mymap.insert(it,pair<char,int>('d',4));
    // search done using key
    it = mymap.find('a'); // takes o(log (n)) time

    for(it=mymap.begin();it!=mymap.end();it++){
        cout <<(*it).first<<" "<<(*it).second<<endl;
    }
    return 0;
}

