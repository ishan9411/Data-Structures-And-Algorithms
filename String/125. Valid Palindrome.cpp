class Solution {
private:
    char toLower(char ch){
        if(ch>='A' && ch<='Z'){
            char s = ch - 'A' + 'a';
            return s;
        }
        return ch;
    }
    bool checkValidChar(char s){
        if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9')){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool checkPalindrome(string s, int e){
        int st = 0;
        e = e-1;

        while(st<=e){
            if(toLower(s[st]) != toLower(s[e])){
                return 0;
            }
            st++;
            e--;
        }
        return 1;
    }
public:
    bool isPalindrome(string s) {
        int i = 0;

        for(int j = 0; j<s.length(); j++){
            if(checkValidChar(s[j])){
                swap(s[j], s[i]);
                i++;
            }
        }
        s[i] = '\0';
        return checkPalindrome(s,i);
    }
};