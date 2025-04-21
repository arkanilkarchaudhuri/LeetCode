int numRabbits(int* answers, int n) {
    int freq[1000]={0};
    int cnt=0;
    for(int i=0; i<n; i++){
        const int x=answers[i];
        cnt+=(freq[x]++%(x+1)==0)*(x+1);
    }
    return cnt;
}