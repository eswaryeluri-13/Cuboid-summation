#include <iostream>
using namespace std;

//our 3D Fenwick tree
long long F[107][107][107];
long long a[107][107][107];
int n;

//Add to element on position (x,y,z) value val

void update(int x, int y, int z,long long v) {
    int i=0;
	for(int i=x; i<=n; i+=i&-i){
        //cout<<i<<endl;
		for(int j=y; j<=n; j+=j&-j){
            for(int k=z;k<=n;k+=k&-k){
                F[i][j][k]+=v;
                //cout<<F[i][j][k]<<endl;
            }
		}

		//cout<<i<<endl;
	}
}

//get sum of cube (0,0,0,x,y,z)

long long get(int x, int y,int z) {
	long long cub=0;
	int i=0;
	for(int i=x; i>0; i-=i&-i){
		for(int j=y; j>0; j-=j&-j){
			for(int k=z; k>0 ; k-=k&-k){
                cub+=F[i][j][k];
			}
	        }
    //cout<<i<<endl;
    }
    //cout<<cub<<endl;
	return cub;
}

//get sum of cube (x1,y1,x2,y2)

long long getcube(int x1, int y1, int z1, int x2, int y2,int z2) {
	return get(x2,y2,z2)-get(x2,y1-1,z2)-get(x1-1,y2,z2)+get(x1-1,y1-1,z2)-(get(x2,y2,z1-1)-get(x2,y1-1,z1-1)-get(x1-1,y2,z1-1)+get(x1-1,y1-1,z1-1));
}

int main() {
    int t;
    int m,i,j,k,x1,x2,y1,y2,z1,z2;
    cin>>t;
    long long num;
    string s;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                for(k=0;k<=n;k++)
                {
                    F[i][j][k]=0;
                    a[i][j][k]=0;
                }
            }
        }

        for(i=0;i<m;i++)
        {
            cin>>s;
            if(s=="UPDATE")
            {
                cin>>x1>>y1>>z1>>num;
                update(x1,y1,z1,num-a[x1][y1][z1]);
                a[x1][y1][z1]=num;
            }
            else
            {
                cin>>x1>>y1>>z1>>x2>>y2>>z2;
                cout<<getcube(x1,y1,z1,x2,y2,z2)<<endl;
            }
        }
    }
	return 0;
}



