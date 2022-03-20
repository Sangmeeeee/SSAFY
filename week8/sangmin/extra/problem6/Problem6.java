package week8.sangmin.extra.problem6;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Problem6 {
    static int N, K, T;

    public static void getTime(int targetTime, int[] times, int[] inDegree, List< List<Integer> > graph) {
        int[] results = new int[N + 1];
        Queue<Integer> q = new LinkedList<>();

        for(int i = 1; i <= N; i++) {
            if(inDegree[i] == 0) {
                results[i] = times[i];
                q.add(i);
            }
        }

        while(!q.isEmpty()) {
            int curNode = q.poll();
            for(int nextNode : graph.get(curNode)) {
                inDegree[nextNode]--;
                results[nextNode] = Math.max(results[nextNode], results[curNode] + times[nextNode] );
                if(inDegree[nextNode] == 0) {
                    q.add(nextNode);
                }
            }
        }
        System.out.println(results[targetTime]);
    }

    public static void main(String[] args) throws Exception, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine().trim());
        while(T > 0) {
            String[] line = br.readLine().split(" ");
            N = Integer.parseInt(line[0]);
            K = Integer.parseInt(line[1]);
            int[] times = new int[N + 1];
            int[] inDegree = new int[N + 1];
            int target;
            List< List<Integer> > graph = new ArrayList<>();
            for(int i = 0; i <= N; i++) {
                graph.add(new ArrayList<>());
            }

            line = br.readLine().split(" ");
            for(int i = 1; i <= N; i++) {
                times[i] = Integer.parseInt(line[i - 1]);
            }
            for(int i = 0; i < K; i++) {
                line = br.readLine().split(" ");
                int node1 = Integer.parseInt(line[0]);
                int node2 = Integer.parseInt(line[1]);
                graph.get(node1).add(node2);
                inDegree[node2]++;
            }
            target = Integer.parseInt(br.readLine().trim());
            getTime(target, times, inDegree, graph);
            T--;
        }
    }
}