package week17.sangmin.problem3;

import java.util.LinkedList;
import java.util.List;

class Solution {

    List<String> cache = new LinkedList<>();

    public int solution(int cacheSize, String[] cities) {
        int answer = 0;

        if(cacheSize == 0) return cities.length * 5;

        for(String city : cities) {
            city = city.toLowerCase();
            if(cache.contains(city)) { // hit
                answer++;
                cache.remove(city);
                cache.add(city);
            }else { // miss
                answer += 5;
                if(cache.size() == cacheSize) {
                    cache.remove(0);
                    cache.add(city);
                }else {
                    cache.add(city);
                }
            }
        }
        return answer;
    }
}

public class Problem3 {

}
