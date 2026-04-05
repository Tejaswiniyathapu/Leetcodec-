class Solution {
public:
    bool judgeCircle(string moves) {
        int V=0,H=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') V+=1;
            else if(moves[i]=='D') V-=1;
            else if(moves[i]=='R') H+=1;
            else if(moves[i]=='L') H-=1;
        }
        if(V==0 && H==0) return true;
        else return false;
    }
};