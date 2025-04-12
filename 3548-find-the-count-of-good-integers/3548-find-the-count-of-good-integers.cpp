class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<long long>fact(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i]=i*fact[i-1];
        }
        int x=n/2;
        if(n%2==0){
            long long ans=0;
            unordered_map<string,bool>mpp;
            if(x==1){
                for(int i=1;i<10;i++){
                    int num=i*10 + i;
                    if(num%k==0){
                        ans++;
                    }
                }
                return ans; 
            }
            if(x==2){
                
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        long long num=i*10 + j;
                        string t=to_string(num);
                        string s=t;
                        reverse(s.begin(),s.end());
                        t+=s;
                        long long temp=stoll(t);
                        if(temp%k==0){
                            sort(t.begin(),t.end());
                            mpp[t]=true;
                        }
                    }
                }
                
                
            }
            if(x==3){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int m=0;m<10;m++){
                            long long num=i*100 + j*10 +m;
                            string t=to_string(num);
                            string s=t;
                            reverse(s.begin(),s.end());
                            t+=s;
                            long long temp=stoll(t);
                            if(temp%k==0){
                                sort(t.begin(),t.end());
                                mpp[t]=true;
                            }
                        }
                        
                    }
                }
                
            }
            if(x==4){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int m=0;m<10;m++){
                            for(int l=0;l<10;l++){
                                long long num=i*1000 + j*100 +m*10 +l;
                                string t=to_string(num);
                                string s=t;
                                reverse(s.begin(),s.end());
                                t+=s;
                                long long temp=stoll(t);
                                if(temp%k==0){
                                    sort(t.begin(),t.end());
                                    mpp[t]=true;
                                }
                            }
                            
                        }
                        
                    }
                }
                
            }
            if(x==5){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int m=0;m<10;m++){
                            for(int l=0;l<10;l++){
                                for(int d=0;d<10;d++){
                                    long long num=i*10000 + j*1000 +m*100 +l*10 +d;
                                    string t=to_string(num);
                                    string s=t;
                                    reverse(s.begin(),s.end());
                                    t+=s;
                                    long long temp=stoll(t);
                                    if(temp%k==0){
                                        sort(t.begin(),t.end());
                                        mpp[t]=true;
                                    }
                                }
                                
                            }
                            
                        }
                        
                    }
                }
                
            }
            
            for(auto it:mpp){
                vector<int>cnt(10,0);
                for(auto c:it.first){
                    cnt[c-'0']++;
                }
                long long z=fact[n];
                for(auto i:cnt){
                    z=z/fact[i];
                }
                if(cnt[0]>0){
                    cnt[0]--;
                    long long y=fact[n-1];
                    for(auto i:cnt){
                        y=y/fact[i];
                    }
                    z=z-y;

                }
                ans+=z;

            }
            return ans;
        }
        else{
            long long ans=0;
            unordered_map<string,bool>mpp;
            if(x==0){
                for(int i=1;i<10;i++){
                    int num=i;
                    if(num%k==0){
                        ans++;
                    }
                }
                return ans; 
            }
            if(x==1){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        long long num=i*10 + j;
                        string t=to_string(num);
                        string s=t;
                        s.pop_back();
                        reverse(s.begin(),s.end());
                        t+=s;
                        long long temp=stoll(t);
                        if(temp%k==0){
                            sort(t.begin(),t.end());
                            mpp[t]=true;
                        }
                    }
                }
            }
            if(x==2){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int m=0;m<10;m++){
                            long long num=i*100 + j*10 +m;
                            string t=to_string(num);
                            string s=t;
                            s.pop_back();
                            reverse(s.begin(),s.end());
                            
                            t+=s;
                            long long temp=stoll(t);
                            if(temp%k==0){
                                sort(t.begin(),t.end());
                                mpp[t]=true;
                            }
                        }
                        
                    }
                }
                
            }
            if(x==3){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int m=0;m<10;m++){
                            for(int l=0;l<10;l++){
                                long long num=i*1000 + j*100 +m*10 +l;
                                string t=to_string(num);
                                string s=t;
                                s.pop_back();
                                reverse(s.begin(),s.end());
                                
                                t+=s;
                                long long temp=stoll(t);
                                if(temp%k==0){
                                sort(t.begin(),t.end());
                                mpp[t]=true;
                            }
                            }
                            
                        }
                        
                    }
                }
                
            }
            if(x==4){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int m=0;m<10;m++){
                            for(int l=0;l<10;l++){
                                for(int d=0;d<10;d++){
                                    long long num=i*10000 + j*1000 +m*100 +l*10 +d;
                                    string t=to_string(num);
                                    string s=t;
                                    s.pop_back();
                                    reverse(s.begin(),s.end());
                                    
                                    t+=s;
                                    long long temp=stoll(t);
                                    if(temp%k==0){
                                sort(t.begin(),t.end());
                                mpp[t]=true;
                            }
                                }
                                
                            }
                            
                        }
                        
                    }
                }
                
            }
            
            for(auto it:mpp){
                vector<int>cnt(10,0);
                for(auto c:it.first){
                    cnt[c-'0']++;
                }
                long long z=fact[n];
                for(auto i:cnt){
                    z=z/fact[i];
                }
                if(cnt[0]>0){
                    cnt[0]--;
                    long long y=fact[n-1];
                    for(auto i:cnt){
                        y=y/fact[i];
                    }
                    z=z-y;

                }
                ans+=z;

            }
            return ans;
        }
        return 0;
    }
};