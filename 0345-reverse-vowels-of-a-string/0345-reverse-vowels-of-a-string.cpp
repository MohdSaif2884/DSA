class Solution {
public:
    string reverseVowels(string s) {

        vector<char>str;
        int n = s.size();

        for(int i =0 ; i<n ; i++){
            if(s[i] =='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O' || s[i]=='U'|| s[i]=='a'|| s[i]=='e'|| s[i]== 'i' || s[i]== 'o' || s[i]=='u'){
                str.push_back(s[i]);
            }
        }

        reverse(str.begin(), str.end());
int j =0;
         for(int i =0 ; i<n ; i++){
            if(s[i] =='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O' || s[i]=='U'|| s[i]=='a'|| s[i]=='e'|| s[i]== 'i' || s[i]== 'o' || s[i]=='u'){
                 s[i]= str[j++];
            }
        }

        return s;
        
    }
};