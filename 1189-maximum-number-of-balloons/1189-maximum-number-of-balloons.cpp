class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(int i =0 ; i<text.size(); i++){
            mp[text[i]]++;
        }

        string b="balon";
        int mini = INT_MAX;

        // for(auto it:ch){
        //     if(it.first == 'b'){
        //         mini = min(mini, it.second);
        //     }else if(it.first== 'a'){
        //         mini = min(mini, it.second);
        //     }else if(it.first == 'l'){
        //         mini = min(mini, it.second/2);
        //     }else if(it.first == 'o'){
        //           mini = min(mini, it.second/2);
        //     }else if(it.first == 'n'){
        //           mini = min(mini, it.second);
        //     }}
        // return mini;

        for( auto it :b){
          if( mp.find(it) != mp.end()){
             if(it == 'b'){
                mini = min(mini, mp[it]);
            }else if(it == 'a'){
                mini = min(mini, mp[it]);
            }else if(it == 'l'){
                mini = min(mini, mp[it]/2);
            }else if(it == 'o'){
                  mini = min(mini, mp[it]/2);
            }else if(it == 'n'){
                  mini = min(mini, mp[it]);
            }
          }else{
            return 0;
          }

      
        }     return mini;

    }
};