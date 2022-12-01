class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(s==p) return 0;
        if(m==0) return 0;
        if(m>n) return -1;
        string str = s.substr(0,m);
        // cout<<str<<" ";
        if(str==p) return 0;
        for(int i=m;i<n;i++){
            string st = str.substr(1) + s[i];
            // cout<<str<<" ";
            str = st;
            if(st==p) return i-m+1;
        }
        return -1;
    }
};