package week14.sangmin.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Problem4 {
    static Map<String, Integer> trees = new HashMap<>();
    public static void main(String[] args) throws IOException {
        int count = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        while (line != null && line.length() != 0){
            count++;
            trees.put(line, trees.getOrDefault(line, 0) + 1);
            line = br.readLine();
        }
        List<String> treeList = new ArrayList<>(trees.keySet());
        Collections.sort(treeList);
        StringBuilder sb = new StringBuilder();
        for(String tree : treeList){
            double result = (double) trees.get(tree) / count * 100;
            sb.append(tree + " " + String.format("%.4f", result) + "\n");
        }
        System.out.println(sb.toString());
    }
}
/*
Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow


 */