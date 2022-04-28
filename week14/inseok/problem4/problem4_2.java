package week14.inseok.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class problem4_2 {
    static class Node {
        String tree;
        int cnt;
        public Node(String tree, int cnt) {
            this.tree = tree;
            this.cnt = cnt;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        Map<String, Integer> hm = new HashMap<>();//entry Set 에 순서가 있는 해쉬맵

        int count=0;
        while(true) {
            String tree = br.readLine();
            if(tree==null || tree.equals("")) break;
            count++;
            //hm.putIfAbsent(tree,0);
            //hm.put(tree, hm.get(tree)+1);

            if(!hm.containsKey(tree)) hm.put(tree,1);
            else hm.put(tree, hm.get(tree)+1);
        }

        ArrayList<Node> list = new ArrayList<>();
        Iterator<String> keys = hm.keySet().iterator();//iterator
        while(keys.hasNext()) {
            String tree1 = keys.next();
            list.add(new Node(tree1,hm.get(tree1)));
        }
        Collections.sort(list, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.tree.compareTo(o2.tree);
            }
        });

        for(int i=0;i<list.size();i++) {
            double per = (double)(list.get(i).cnt*100.0)/count;

            sb.append(list.get(i).tree+" "+String.format("%.4f", per)+"\n");
        }
        System.out.println(sb.toString());

    }//END main
}//END public class

//linkedHashMap 처음에 써볼 생각 했는데 이건 들어오는 keySet의 순서를 저장 해주는..(String 의 사전순과는 멀어서 포기했다.)