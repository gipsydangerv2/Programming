# include<bits/stdc++.h>
using namespace std;
# define ll long long
struct point{
    int x,y;
};
// used to check whether point r is present on segment pq.
bool pointOnLine(point p,point q,point r){
    bool xProjection = false;
    bool yProjection = false;
    // point r intersects with xProjection.
    if(r.x<=max(p.x,q.x) && r.x>=min(p.x,q.x))
        xProjection = true;
    // point r intersects with yProjection.
    if(r.y<=max(p.y,q.y) && r.y>=min(p.y,q.y))
        yProjection = true;
    if(xProjection && yProjection)
        return true;
    return false;
}
int orientation(point p1,point p2,point p3){
    //int slope1 = (p2.y-p1.y)/(p2.x-p1.x);
    //int slope2 = (p3.y-p2.y)/(p3.x-p2.x);
    // do slope1 - slope2
    int ans = (p2.y-p1.y)*(p3.x-p2.x) - (p3.y-p2.y)*(p2.x-p1.x);
    if(ans > 0) return 1;
    else if(ans < 0) return 2;
    else return 0;
}
bool checkForIntersection(point p1,point q1,point p2,point q2){

    // if orientation = 0. Means collinear.
    // if orientation = 1. Means clockwise.
    // if orientation = 2. Means counter clockwise.

    int orient1 = orientation(p1,q1,p2);
    int orient2 = orientation(p1,q1,q2);
    int orient3 = orientation(p2,q2,p1);
    int orient4 = orientation(p2,q2,q1);

    if(orient1 != orient2 && orient3 != orient4)
        return true;

    // special casess.
    if(orient1 == 0 && pointOnLine(p1,q1,p2))
        return true;
    if(orient2 == 0 && pointOnLine(p1,q1,q2))
        return true;
    if(orient3 == 0 && pointOnLine(p2,q2,p1))
        return true;
    if(orient4 == 0 && pointOnLine(p2,q2,q1))
        return true;
    return false;
}
int isPointInside(struct point polygon[],int n,struct point p){
    bool flag = 1;
    for(int i=1;i<n;i++){
        int orient = orientation(polygon[i-1],polygon[i],p);
        cout << orient << " : " << polygon[i-1].x <<","<<polygon[i-1].y <<"--"<< polygon[i].x <<","<<polygon[i].y <<"--"<< p.x <<","<<p.y <<endl;
        if(orient == 2)
            flag = 0;
    }
    return flag;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    struct point p1 = {1,1}, q1={10,1};
    struct point p2 = {1,2}, q2={10,2};

    //checkForIntersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    //checkForIntersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    //checkForIntersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    struct point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    struct point p = {20, 20};
    isPointInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

    p = {5, 5};
    isPointInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

    struct point polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
    p = {3, 3};
    n = sizeof(polygon2)/sizeof(polygon2[0]);
    isPointInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    p = {5, 1};
    isPointInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    p = {8, 1};
    isPointInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    struct point polygon3[] =  {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    p = {-1,10};
    n = sizeof(polygon3)/sizeof(polygon3[0]);
    isPointInside(polygon3, n, p)? cout << "Yes \n": cout << "No \n";
}
