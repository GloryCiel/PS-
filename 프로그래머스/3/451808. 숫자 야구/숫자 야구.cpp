#include <string>
#include <vector>
using namespace std;

extern string submit(int);

static inline int enc(int s, int b){ return s*10 + b; }

static inline void score(int g, int s, int &st, int &ba){
    int gd[4], sd[4];
    gd[0]=g/1000; gd[1]=g/100%10; gd[2]=g/10%10; gd[3]=g%10;
    sd[0]=s/1000; sd[1]=s/100%10; sd[2]=s/10%10; sd[3]=s%10;

    bool in[10]={0};
    for(int i=0;i<4;i++) in[sd[i]]=1;

    st=0; ba=0;
    for(int i=0;i<4;i++){
        if(gd[i]==sd[i]) st++;
        else if(in[gd[i]]) ba++;
    }
}

static inline int parseHint(const string& t){
    int s=0,b=0,i=0;
    while(i<(int)t.size() && t[i]>='0' && t[i]<='9'){ s = s*10 + (t[i]-'0'); i++; }
    while(i<(int)t.size() && t[i]!=' ') i++;
    while(i<(int)t.size() && t[i]==' ') i++;
    while(i<(int)t.size() && t[i]>='0' && t[i]<='9'){ b = b*10 + (t[i]-'0'); i++; }
    return enc(s,b);
}

static inline bool valid4(int x){
    if(x<1000 || x>9999) return false;
    int a=x/1000,b=x/100%10,c=x/10%10,d=x%10;
    if(a==0||b==0||c==0||d==0) return false;
    return a!=b && a!=c && a!=d && b!=c && b!=d && c!=d;
}

int solution(int n){
    vector<int> all; all.reserve(3024);
    for(int i=1000;i<=9999;i++) if(valid4(i)) all.push_back(i);

    vector<int> cand = all;
    int used=0;

    while(true){
        int best = 1e9, bestGuess = all[0];

        for(int gi=0; gi<(int)all.size(); gi++){
            int g = all[gi];
            int cnt[55]={0};
            int worst=0;

            for(int si=0; si<(int)cand.size(); si++){
                int st,ba; score(g, cand[si], st, ba);
                int k = st*10 + ba;
                int v = ++cnt[k];
                if(v>worst) worst=v;
                if(worst>=best) break;
            }
            if(worst<best){ best=worst; bestGuess=g; }
        }

        int hint = parseHint(submit(bestGuess));
        used++;

        if(hint==40) return bestGuess;

        vector<int> nxt; nxt.reserve(cand.size());
        for(int si=0; si<(int)cand.size(); si++){
            int st,ba; score(bestGuess, cand[si], st, ba);
            if(enc(st,ba)==hint) nxt.push_back(cand[si]);
        }
        cand.swap(nxt);

        if((int)cand.size()==1) return cand[0];
        if(used>=n) return cand[0];
    }
}