package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

//https://www.acmicpc.net/problem/16958
//16958번-텔레포트
public class baekjoon_16958 {
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		
		int[][] city = new int[n][3];
		int[][] graph = new int[n][n];
		
		for(int i = 0; i<n ; i++) {
			st = new StringTokenizer(br.readLine());
			city[i][0]=Integer.parseInt(st.nextToken());
			city[i][1]=Integer.parseInt(st.nextToken());
			city[i][2]=Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i<n ; i++) {
			for(int j = i+1 ; j<n ; j++) {
				if(i==j) continue;
				graph[i][j] = Math.abs(city[i][1]-city[j][1])+Math.abs(city[i][2]-city[j][2]);
				if(city[i][0]==1 && city[j][0]==1) graph[i][j] = Math.min(graph[i][j], t);
				graph[j][i] = graph[i][j];
			}
		}
		
		for(int k = 0; k<n ; k++) {
			for(int i = 0; i<n ; i++) {
				for(int j = i+1; j<n ; j++) {
					if(i!=j) {
						graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
						graph[j][i] = graph[i][j];
					}
				}
			} 
		}
		
		int m = Integer.parseInt(br.readLine());
		
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			System.out.println(graph[a-1][b-1]);
			
		}
		
		
	}
}
