/*
  code created on:20/11/15
  This is the code for single source shortest path : Dijkstra Algorithms using Graph represented as Adjacency List.
*/
#include<iostream>
#include<list>
#include<vector>
#include<queue>
#define INF 10000005
using namespace std;
class Compare{
	public:
		bool operator ()(const pair<int,int> & p1,const pair<int,int> &p2){
			return p1.second > p2.second;
		}
};
class Graph{
	public :int v,e;
	vector<list<pair<int,int>>>g;
	vector<int>d;
	vector<int>p;
	Graph(int v,int e){
		this->v = v;
		this->e = e;
		g.resize(v+1);
	}
	void INITIALISE_SINGLE_SOURCE(Graph G,int src){
		d.resize(G.v+1,INF);
		p.resize(G.v+1,0);
		d[src]=0;
	}
	void dijkstra(Graph G,int src){
		INITIALISE_SINGLE_SOURCE(G,src);
		priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>heap;
		vector<bool>visited(G.v+1,false);
		heap.push(make_pair(src,0));
		while(!heap.empty()){
			pair<int,int> u = heap.top();
			heap.pop();
			if(visited[u.first]==false){
				visited[u.first]=true;
				for(list<pair<int,int>>::iterator v = G.g[u.first].begin();v!=G.g[u.first].end();v++){
					if(d[(*v).first] > d[u.first] + (*v).second){
						d[(*v).first] = d[u.first] + (*v).second;
						p[(*v).first] = u.first;
						heap.push(make_pair((*v).first,d[(*v).first]));
					}
				}
			}
		}
	}
	void printDist(){
		for(int i=1;i<=v;i++)
			cout<<i<<":"<<d[i]<<endl;
	}
};
int main(){
		int v,e,src,dest,wght;
	cout<<"Vertices and Edges:";
	cin >>v>>e;
	Graph G(v,e);
	for(int i=1;i<=G.e;i++){
		cin >>src>>dest>>wght;
		G.g[src].push_back(make_pair(dest,wght));
		G.g[dest].push_back(make_pair(src,wght));
	}
	G.dijkstra(G,1);
	G.printDist();
	return 0;
}
