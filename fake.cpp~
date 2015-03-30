#include<iostream>
using namespace std;
class point{
    public:
    long long int x,y;
    point(int xp=0,int yp=0):x(xp),y(yp){}
    point(point& rhs):x(rhs.x),y(rhs.y){}
    point& operator=(point& rhs){
        x=rhs.x;
        y=rhs.y;
        return *this;
    }
    friend point operator+(point& l,point& r){
        return point(l.x+r.x,l.y+r.y);
    }
    bool operator==(point& right){
        return x==right.x&&y==right.y;
    }
    friend point operator-(point& l,point& r){
        return point(l.x-r.x,l.y-r.y);
    }
    ostream& operator<<(std::ostream& os,point& p){
        os<<p.x<<" "<<p.y<<endl;
    }    
    
};

int main(){
    unsigned long int test,n,i,sqx,sqy,sq;
    point *pts,left,right,up,down;
    while(test--){
        cin>>n;
        pts=new point[n];
        cin>>pts[0].x>>pts[0].y;
        up=down=left=right=pts[0];
        for(i=1;i<n;i++){
            cin>>pts[i].x>>pts[i].y;
            if(left.x>pts[i].x) left=pts;
            else if(right.x<pts[i].x) right=pts;
            if(up.y<pts[i].y) up=pts;
            else if(down.y>pts[i].y) down=pts;
        }
        cout<<"left "<<left<<" right "<<right<<" up "<<up<<" down "<<down;
        sqx=left.x<0?right.x-left.x:right.x+left.x;
        sqy=down.y<0?up.y-down.y:up.y+down.y;
        while(sqx!=sqy){
            if(sqx<sqy) {
                sqx++;
                right.x++;
            }
            else {
                sqy++;
                up.y++;
            }
       }
       
        }
         
        
            
            
            
            
            
            
            
            
        
            
            
