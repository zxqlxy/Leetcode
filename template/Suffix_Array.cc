// 《后缀数组——处理字符串的有力工具》by 2009IOI 罗穗骞

#include <iostream>
#include <string>

#define maxn  10

using namespace std;

// ************** 倍增算法 **************

int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
/* n is len of string, m is range of character 
* r is the string, result store in ra
*/
void da(int *r,int *sa,int n,int m)
{
    int wa[maxn],wb[maxn],wv[maxn],ws[maxn];

    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}

int main()
{
    int n = 10;
    int r[] = {4,2,3,2,3,1,7,10,9,10};
    int sa[10];
    int m = 11;
    da(r, sa, n, m);
    for (int i = 0; i < n; i++)
        cout << sa[i] << ":" << r[sa[i]] << " ";
    return 0;
}

// ************** DC3算法 ************** 
