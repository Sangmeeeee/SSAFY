package week20.sangmin.problem3;

import java.util.HashSet;
import java.util.Set;

class Solution {

    Set<String> set = new HashSet<>();

    boolean isIdMatch(String userId, String bannedId){
        if(userId.length() != bannedId.length()) return false;

        for(int idx = 0; idx < userId.length(); idx++){
            char bannedIdWord = bannedId.charAt(idx);
            if(bannedIdWord == '*') continue;
            else{
                char userIdWord = userId.charAt(idx);
                if(userIdWord != bannedIdWord) return false;
            }
        }
        return true;
    }

    void dfs(String[] user_id, String[] banned_id, boolean[] isMatch, int depth, int matchCount){

        if(matchCount == banned_id.length){
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < isMatch.length; i++){
                if(isMatch[i]) sb.append(user_id[i]);
            };
            set.add(sb.toString());
            return;
        }
        if(depth == banned_id.length) {
            return;
        }

        for(int idx = depth; idx < banned_id.length; idx++){
            for(int target = 0; target < user_id.length; target++){
                if(!isMatch[target] && isIdMatch(user_id[target], banned_id[idx])){
                    isMatch[target] = true;
                    dfs(user_id, banned_id, isMatch, idx + 1, matchCount + 1);
                    isMatch[target] = false;
                }
            }
        }
    }

    public int solution(String[] user_id, String[] banned_id) {
        dfs(user_id, banned_id, new boolean[user_id.length], 0, 0);
        return set.size();
    }
}

public class Problem3 {
    public static void main(String[] args) {
//        new Solution().solution(new String[]{"frodo", "fradi", "crodo", "abc123", "frodoc"}, new String[]{"fr*d*", "abc1**"});
//        new Solution().solution(new String[]{"frodo", "fradi", "crodo", "abc123", "frodoc"}, new String[]{"*rodo", "*rodo", "******"});
        new Solution().solution(new String[]{"frodo", "fradi", "crodo", "abc123", "frodoc"}, new String[]{"fr*d*", "*rodo", "******", "******"});
    }
}
