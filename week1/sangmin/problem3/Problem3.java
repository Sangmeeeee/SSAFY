package week1.sangmin.problem3;

import java.io.*;
import java.util.*;
public class Problem3 {
    static Set<String> result = new TreeSet<>();
    static char[] str;
    static int[] left = new int[10];
    static int[] right = new int[10];
    static boolean[] check = new boolean[10];
    static boolean[] strVisit;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine().toCharArray();
        strVisit = new boolean[str.length];
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Stack<Integer> stack = new Stack<>();
        int count = 0;
        for(int i = 0; i < str.length; i++){
            switch (str[i]){
                case '(' : stack.push(i);
                    break;
                case ')' : left[count] = stack.pop();
                    right[count++] = i;
                    break;
            }
        }

        solve(count, 0);

        Iterator<String> iterator = result.iterator();
        StringBuilder sb = new StringBuilder();
        while (iterator.hasNext()){
            sb.append(iterator.next() + '\n');
        }
        bw.append(sb.toString());
        bw.flush();
    }

    public static void solve(int count, int level){
        if(level == count) {
            return;
        }
        for(int i = level; i < count; i++){
            if(!check[i]) {
                StringBuilder sb = new StringBuilder();
                check[i] = true; // for ( ) check
                strVisit[left[i]] = true;
                strVisit[right[i]] = true;
                for(int j = 0; j < str.length; j++){
                    if(!strVisit[j]){
                        sb.append(str[j]);
                    }
                }
                result.add(sb.toString());
                solve(count, level + 1);
                check[i] = false;
                strVisit[left[i]] = false;
                strVisit[right[i]] = false;
            }
        }
    }
}

/*
(1+(2*(3+4)))+(3+4)
답 >>>>>>>>
(1+(2*(3+4)))+3+4
(1+(2*3+4))+(3+4)
(1+(2*3+4))+3+4
(1+2*(3+4))+(3+4)
(1+2*(3+4))+3+4
(1+2*3+4)+(3+4)
(1+2*3+4)+3+4
1+(2*(3+4))+(3+4)
1+(2*(3+4))+3+4
1+(2*3+4)+(3+4)
1+(2*3+4)+3+4
1+2*(3+4)+(3+4)
1+2*(3+4)+3+4
1+2*3+4+(3+4)
1+2*3+4+3+4

(((1 + 0)))
답 >>>>>>
((1 + 0))
(1 + 0)
1 + 0
 */