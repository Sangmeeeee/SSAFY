# Info

���� : [���� �˻�](https://programmers.co.kr/learn/courses/30/lessons/72412)

�˰����� ���� :

���� url : https://algosu.tistory.com/99


# 1. �˰����� ����

�־��� `info`�� ��� ������ ���� ��� ����� ���� �̸� ����� �����ؾ߰ڴٴ� ������ �ߴµ�  
��� �������� �� �𸣰ھ �ٸ� �� �ڵ带 �����ؼ� Ǯ����.

:star: **Ǯ�� �帧**  
map�� ����Ͽ� Ǫ�µ�, key�� ���ڿ��� �� �����̸� value�� �� ������ �����ϴ� ������� ���� �����̴�.  
1. `info`���� �־��� �� ������ ���� "-"�� ������ ��� ����� key�� ���ϰ�, map�� ������ �Բ� ��´�.
2. map�� ���͵��� �����Ѵ�.
3. `query`�� �� ���ڿ��� key ���·� ��ȯ�ϰ� map���� �ش��ϴ� ����� ���� ���Ѵ�.

:star: **�� ����**  
**<< 1. >>**
�켱, �־��� �����ڵ��� ������ key�� ������ �Ѵ�.  
key�� ���´� �������� ������ ������ ��� ������ ���� ���� ���� ���̴�.  
���� ���, �������� ������ "java backend junior pizza 150"�̶��  
key�� "javabackendjuniorpizza"�� �Ǵ� ���̴�.  
������ �����Ͽ� �Է¹ޱ� ���� `<sstream>` ��� ������ `stringstream` ������ ����ߴ�.  

�׷��� ���������� ��� ������ �����ϴ� "-"�� �����Ѵ�.  
���� �� ������ �������� �����̰ų� "-"�� ��� ��쿡 ���� key�� ����� map�� �����ؾ� �Ѵ�.  
�̶� `detail`�̶�� 2���� �迭�� �����Ͽ� 0��° ���� "-"��, 1��° ���� �������� ������ �־���.  
�׸��� �� �迭�� �̿��Ͽ� 4�� for������ ��� ����� ���� ���ߴ�.  
�� ������ �׸����� ��Ÿ���ô�. (:arrow_down:)

`table`�� map�̸�, key�� string Ÿ���̰� value�� vector<int> Ÿ���̴�.  
![KakaoTalk_20220513_171809827](https://user-images.githubusercontent.com/57346428/168244234-3f4fbfa7-4d8c-430e-ba7c-7cdd90282c42.jpg)

��� �����ڿ� ���� �� ������ ������ map�� �ִ� 108������ ���Ұ� ���Եȴ�.  
`{"java", "python", "cpp", "-"}` 4����, `{"frontend", "backend", "-"}` 3����,  
`{"junior", "senior", "-"}` 3����, `{"chicken", "pizza", "-"}` 3������ 4*3*3*3 = 108�����̴�.

**<< 2. >>**  
map�� ����ִ� ���͵��� �������� �������ش�.  
�������ִ� ������ 3�� �������� `lower_bound()`�� ����ϱ� ���ؼ��̴�.  
`lower_bound()` �Լ��� ����� ��, �� �迭�� ������������ ���ĵǾ� �־�� �ϱ� �����̴�.

**<< 3. >>**  
�� `query`�� key�� ��ȯ�ϰ�, map�� �ش� ���ҿ��� ���� ������ �����ϴ� ����� ���� ���ؾ��Ѵ�.  
1�� �������� ���� key�� ���� ���·� `query`���� ������ �̾� key�� �����.  
�׸��� map���� �ش��ϴ� key�� �����Ͽ� �Ѿ���ϴ� ������ ���� `lower_bound()`�� �����Ͽ� ���� ���Ѵ�.  

ó������ `table[key]`�� ���Ϳ��� ������ �Ѵ� ��쿡 `cnt`�� ������Ű���� �ߴµ�, ȿ���� �˻翡�� �����ߴ�.  
�׷��� `lower_bound()` �Լ��� ����� ȿ���� �˻縦 ����ߴ�.  
for������ ���� ��ü�� ���鼭 if������ �Ÿ��� �� �ð����⵵�� `O(N)`�̰�,  
`lower_bound()` �Լ��� �̺� Ž���� ����ϱ� ������ �ð����⵵�� `O(logN)`�� �ɷ��� �׷� �� ����.


# 2. ���� ��� ����(�ڵ� ����)