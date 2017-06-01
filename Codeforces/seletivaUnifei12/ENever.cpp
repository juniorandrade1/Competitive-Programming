#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second

pair<ll,ll>ans;

int vixe(ll x)
{
    int ret=0;
    while(x)
    {
        ret+=x%2;
        x/=2;
    }
    return ret==1;
}

ll f(ll a, ll n)
{
    n+=a;
    return ((a+n)*(n-a+1))/2LL;
}

void solve(ll x)
{
    if(x==1LL)
        return;
    if(x==2LL)
        return;
    if(x%2LL==1LL)
    {
        ans.F=1;
        ans.S=(x/2);
        return;
    }
    if(vixe(x))
    {
        return;
    }
    
    ll lol=2*(sqrt(x)+1);
    for(register ll i=min(x, lol); i>=1 && ans.F==INF; i--)
    {
        ll lo=0, hi=INF;
        while(abs(lo-hi)>1)
        {
            ll mid=(lo+hi)/2LL;
            if(f(i, mid)>x)
                hi=mid;
            else
                lo=mid;
        }
        if(f(i, lo)==x)
        {
            if(lo<ans.F)
            {
                ans.F=lo;
                ans.S=i;
            }
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    int tt;
    scanf("%d", &tt);
    for(register int t=0; t<tt; t++)
    {
        ll x;
        scanf("%lld", &x);
        x=abs(x);
        ans=mp(INF,INF);
        solve(x);

        ll fst = ans.S - 1;
        ll scd = ans.F + ans.S;
        ll tot = (scd * (scd + 1)) / 2LL;
        tot -= ((fst * (fst + 1)) / 2LL); 
        if(tot != x)
        {
            printf("IMPOSSIVEL\n");
        }
        else
        {
            printf("%lld = ", x);
            bool spc=false;
            for(register ll y=ans.S; y<=ans.S+ans.F; y++)
            {
                if(spc)
                {
                    printf(" + ");
                }
                else
                    spc=true;
                printf("%lld", y);
            }
            printf("\n");
        }
    }
}