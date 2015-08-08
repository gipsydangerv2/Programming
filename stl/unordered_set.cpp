                            /* Unordered set */
#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
int main(){
    unordered_set<string>myset={"red","green","blue"};
    unordered_set<string>::const_iterator itr= myset.find("red"); // O(1)
    if(itr!=myset.end())    // Important check
        cout << *itr<<endl;
    myset.insert("yellow"); // insertion also takes O(1) time
    vector<string>vec={"grey","orange"};
    myset.insert(vec.begin(),vec.end());

    // HashTable specific APIs
    cout <<"load_factor"<<myset.load_factor()<<endl;
    string x="red";
    cout <<x<<" is in bucket "<<myset.bucket(x)<<endl;
    cout <<"total bucket "<<myset.bucket_count()<<endl;


    return 0;
}
