#include <bits/stdc++.h>
using namespace std;
class matrix{
private:
    double n,m;
    double a[100][100];
public:
    friend istream &operator>>(istream &input, matrix &ma)
    {
        input>>ma.n>>ma.m;
        for(int i=0;i<ma.n;++i)
        {
            for(int j=0;j<ma.m;++j)
                input>>ma.a[i][j];
        }
        return input;
    }
    matrix operator+(const matrix&ma)
    {
        matrix ans;
        ans.n=this->n; ans.m=this->m;
        for(int i=0;i<this->n;++i)
        {
            for(int j=0;j<this->m;++j)
               {
              ans.a[i][j]=this->a[i][j]+ma.a[i][j];
            }
        }
        return ans;
    }
      matrix operator-(const matrix&ma)
    {   matrix ans;
        ans.n=this->n; ans.m=this->m;
        for(int i=0;i<this->n;++i)
        {
            for(int j=0;j<this->m;++j)
               {
              ans.a[i][j]=this->a[i][j]-ma.a[i][j];
            }
        }
        return ans;
    }
    matrix operator*(const matrix&ma)
    {
        matrix ans;
        ans.n=this->n; ans.m=this->m;
        for(int i=0;i<ans.n;++i)
        {
            for(int j=0;j<ans.m;++j)
               {
             double x=0;
             for (int h=0;h<ans.m;++h)
             {
                 x+=(this->a[i][h]*ma.a[h][j]);
             }
             ans.a[i][j]=x;
              }
        }
        return ans;
    }
    matrix operator*=(double var)
    {
        for(int i=0;i<this->n;++i)
        {
            for(int j=0;j<this->m;++j)
            {
                 this->a[i][j]*=var;
            }
        }
    }
    matrix transpose()
    {
        matrix ans;
        ans.n=this->n; ans.m=this->m;
        for(int i=0;i<this->m;++i)
        {
            for(int j=0;j<this->n;++j)
            {
                ans.a[j][i]=this->a[i][j];
            }
        }
        return ans;
    }
    matrix identical()
    {
        matrix ans;
        ans.n=this->n; ans.m=this->m;
        for(int i=0;i<this->m;++i)
        {
            for(int j=0;j<this->n;++j)
            {
                if(i==j)
                {
                    ans.a[i][j]=1;
                }
                else ans.a[i][j]=0;
            }
        }
        return ans;
    }
       int process(int *arr)
    {
        double x=arr[0]*arr[3];
        double y=arr[1]*arr[2];
        x-=y;
        return x;
    }
    int determinate()
    {
        int d=0;
        int arr[3][6];
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<6;++j)
                arr[i][j]=this->a[i][j%3];
        }   int x=3,i,z=0,j=0,res=0;
            for(int y=0;y<3;++y)
               {
                    x=3;i=0;
                    int multi=1;
                   while(x--)
                   {
                    multi*=arr[i++][j++];
                   }
                    res+=multi;
                   z+=1;
                   j=z;
               } z=2; j=z;
               for(int y=0;y<3;++y)
               {
                    x=3;i=0;
                    int multi=1;
                   while(x--)
                   {
                    multi*=arr[i++][j--];
                   }
                   res-=multi;
                   z+=1;
                   j=z;
               }
        return res;
    }
    matrix inverse()
    {
        matrix ans;
        ans.m=this->m;
        ans.n=this->n;
        for(int i=0; i<this->m; ++i)
        {
            for(int j=0; j<this->n; ++j)
            {
                int arr[4],in=0;
                for(int h=0; h<this->m; ++h)
                {
                    for(int f=0; f<this->n; ++f)
                    {
                        if(h!=i&&j!=f)
                        {
                            arr[in++]=this->a[h][f];
                        }

                    }
                }
               int ele= process(arr);
               ans.a[i][j]=ele;
            }
        }
      // now we will get obtained matrix
      for(int i=0;i<ans.n;++i)
      {
          for(int j=0;j<ans.m;++j)
          {
              if(i==j||(i==0&&j==2)||(i==2&&j==0))ans.a[i][j]*=1;
              else ans.a[i][j]*=(-1);
          }
      }
     // we will transpose the cofactor matrix
     ans=ans.transpose();
     // we will get determination of matrix
    double d=this->determinate();
   // cout<<ans;
    d=1/d;
    ans*=d;
    return ans;
    }
    friend ostream &operator<<(ostream&output ,matrix &ma)
    {
          for(int i=0;i<ma.n;++i)
        {
            for(int j=0;j<ma.m;++j)
                output<<ma.a[i][j]<<" ";
                output<<endl;
        }
    }

};
int main()
{
    matrix m1,m2;
    cin>>m1>>m2;
    cout<<"Addition \n";
    matrix m3=m1+m2;
    cout<<m3;
    cout<<"Subtraction \n";
    matrix m4=m1-m2;
    cout<<m4;
    cout<<"Multiplication\n";
    matrix m5=m3*m4;
    cout<<m5;
    cout<<"Multiplication( 10 ) \n";
    (m5*=10);
    cout<<m5;
    cout<<"Transpose \n";
    matrix m6= m5.transpose();
    cout<<m6;
    cout<<"Identical \n";
    matrix m7=m4.identical();
    cout<<m7;
    matrix m8=m1.inverse();
    cout<<"Inverse \n";
    cout<<m8;
    cout<<"Division m1/m6 \n";
    // inverse m6 then multiply it
    matrix m9=m8*m1;
    cout<<m9;
    cout<<"Determinant m5 \n";
    cout<<m5.determinate();
}
