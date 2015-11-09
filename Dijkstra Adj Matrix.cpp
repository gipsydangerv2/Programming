/*
This is the code for single source shortest path : Dijkstra Algorithms using Adjacency Matrix
Dijkstra is a greedy algorithm.

Code credits :Ankit Kumar
Made on : 9-11-2015
*/
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
int v,e;
vector<int>dist,parent;
class compare{
	public:
		bool operator()(const pair<int,int> &vert1, const pair<int,int> &vert2){
			return vert1.second < vert2.second;
		}
};
void initialise(int src){
	dist.resize(v);
	parent.resize(v);
	for(int i=0;i<v;i++){ dist[i]=INT_MAX; parent[i]=-1;}
	dist[src]=0;
}
void dijkstra(vector<vector<int>>graph,int src){
	initialise(src);
	// uses to make min heap with the help of priority queue
	// here in priority queue we have to make the compare class
	// priority_queue<int,vector<int>,greater<int>>pq;
	// Here greater<int> is a functor.
	// template<class T> using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
	// use it like min_heap<int> my_heap;
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
	pq.push(make_pair(src,0));
	while(!pq.empty()){
		pair<int,int>p = pq.top();
		int vert = p.first;
		pq.pop();
		for(int i=0;i<v;i++){
			if(graph[vert][i]!=INT_MAX){
				if(dist[i]>dist[vert] + graph[vert][i]){
					dist[i] = dist[vert] + graph[vert][i];
					parent[i] = vert;
					pq.push(make_pair(i,dist[i]));
				}
			}
		}
	}
}
int main(){
	int src,dest,wght;
	cout<<"Vertex and edges:";
	cin >>v>>e;
	vector<vector<int>> graph(v,vector<int>(v,INT_MAX));
	for(int i=0;i<e;i++){
		cin >>src>>dest>>wght;
		graph[src][dest] =wght;
	}
	cout<<"source node:";
	cin >>src;
	dijkstra(graph,src);
	for(int i=0;i<v;i++) cout<<dist[i]<<endl;
	return 0;
}
