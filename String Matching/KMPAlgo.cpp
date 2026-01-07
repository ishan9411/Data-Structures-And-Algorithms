class Solution {
  public:
    void computeLPS(vector<int>& LPS, string& pat){
        int length = 0;
        int M = pat.length();
        LPS[0] = 0;
        
        int i = 1;
        while(i < M){
            if(pat[i] == pat[length]){
                length++;
                LPS[i] = length;
                i++;
            }else{
                if(length != 0){
                    length = LPS[length-1];
                }else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
  
    vector<int> search(string &pat, string &txt) {
        // code here
        int N = txt.length();
        int M = pat.length();
        
        vector<int> result;
        
        vector<int> LPS(M, 0);
        
        computeLPS(LPS, pat);
        
        int i = 0;
        int j = 0;
        while(i < N){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            
            if(j == M){
                result.push_back(i-M);
                j = LPS[j-1];
            }
            else if(i < N && txt[i] != pat[j]){
                if(j != 0){
                    j = LPS[j-1];
                }else{
                    i++;
                }
            }   
        }
        return result;
    }
};