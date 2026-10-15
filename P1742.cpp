#include<bits/stdc++.h>
#define N 114514
const double eps=0.000001;
using namespace std;
std::mt19937 rng(std::random_device{}());
bool is_equal(double A,double B){
    if(fabs(A-B)<=eps) return 1;
    return 0;
}
namespace geo{
    struct point{
        double x,y;
    };
    struct circle{
        point O;
        double r;
    };
    double dis(point A,point B){
        double dis2=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
        double res=sqrt(dis2);
        return res;
    }
    int point_in_circle(point P,circle C){//in:1,on:0,out:-1
        double dis_o=dis(P,C.O);
        if(is_equal(dis_o,C.r)) return 0;
        if(dis_o<C.r) return 1;
        else return -1;
    }
    circle O_for_point(int N_p,point Plist[])//N_p:1,2,3
    {
        if(N_p==1)
            return {Plist[0],0.0};
        else if(N_p==2){
            point reso={(Plist[0].x+Plist[1].x)/2.0,(Plist[0].y+Plist[1].y)/2.0};
            double resr=dis(Plist[0],Plist[1])/2.0;
            return {reso,resr};
        }else{
            point a=Plist[0],b=Plist[1],c=Plist[2];
            double a1, a2, b1, b2, c1, c2;
            point reso;
            a1 = 2 * (b.x - a.x), b1 = 2 * (b.y - a.y),
            c1 = b.x*b.x - a.x*a.x + b.y*b.y - a.y*a.y;
            a2 = 2 * (c.x - a.x), b2 = 2 * (c.y - a.y),
            c2 = c.x*c.x - a.x*a.x + c.y*c.y - a.y*a.y;
            if (is_equal(a1, 0)) {
                reso.y = c1 / b1;
                reso.x = (c2 - reso.y * b2) / a2;
            } else if (is_equal(b1, 0)) {
                reso.x = c1 / a1;
                reso.y = (c2 - reso.x * a2) / b2;
            } else {
                reso.x = (c2 * b1 - c1 * b2) / (a2 * b1 - a1 * b2);
                reso.y = (c2 * a1 - c1 * a2) / (b2 * a1 - b1 * a2);
            }
            double resr=dis(reso,a);
            return {reso,resr};
        }
    }
    circle SEC(int N_p,point Plist[]){//下标从1开始
       // point
        shuffle(Plist+1,Plist+1+N_p,rng);
        point p1[1]={Plist[1]};
        circle res=O_for_point(1,p1);
        for(int i=1;i<=N_p;i++)
        {
            if(point_in_circle(Plist[i],res)!=-1) continue;
            point p2[2]={Plist[1],Plist[i]};
            res=O_for_point(2,p2);
            for(int j=2;j<=i;j++){
                if(point_in_circle(Plist[j],res)!=-1) continue;
                point p2[2]={Plist[i],Plist[j]};
                res=O_for_point(2,p2);
                for(int k=1;k<=j;k++)
                {
                    if(point_in_circle(Plist[k],res)!=-1) continue;
                    point p3[3]={Plist[i],Plist[j],Plist[k]};
                    res=O_for_point(3,p3);
                }
            }
        }return res;
    }
   
}
geo::point P[N];

int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&P[i].x,&P[i].y);
    //shuffle(P+1,P+1+n,rng);
    geo::circle ans=geo::SEC(n,P);
    printf("%.14lf\n%.14lf %.14lf\n",ans.r,ans.O.x,ans.O.y);

}