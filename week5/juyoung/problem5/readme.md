# Info

���� : [�� �μ��� �̵��ϱ�](https://www.acmicpc.net/problem/2206)

�˰����� ���� : BFS

���� url : https://ongveloper.tistory.com/124


# 1. �˰����� ����
ó������ ��� ���� ���� �� ���� ���ְ� �ʺ� �켱 Ž���� �����ߴ�. ������ ������ ���ó� �ð� �ʰ�...

�׷��� bfs�� ���鼭 ���� �ϳ��� ���ֺ����� �ߴµ� �� �ȵż� �ٸ� ��� �ڵ带 �����ߴ�.

�湮 ���� Ȯ�ΰ� ���ÿ� **�̵� �Ÿ��� �����ϴ� 3���� int�� �迭**�� **3���� ������ �����ϴ� ť**�� ����Ͽ� �ذ��� �� �־���.


### ��� ����
1. `vector<vector<vector<int>>> visited`
	- �湮 ���θ� üũ�ϴ� �����̸�, 3���� int�� �迭�� �����Ѵ�.
	- ���±��� **�̵��� �Ÿ��� ����**�Ѵ�.
2. `queue<tuple<int, int, int>> q`
	- `bfs` �Լ� �ȿ��� ���̸�, tuple�� 3���� ������ �����Ѵ�.
	- **x��ǥ, y��ǥ, ���� ���� �μ� �� �ִ� ��������(�̹� ������ ���� �ν��ٸ� 0, �ƴϸ� 1)**


### ��ü���� Ǯ�� ���
ť�� �� ������ �ʺ� �켱 Ž���� �Ѵ�.

1. ť�� pop�Ͽ� x��ǥ�� y��ǥ, ���� ���� �μ� �� �ִ����� ���� ������ �����´�.
2. x��ǥ�� y��ǥ�� ���� ������ ���ٸ� ���� ��ġ�� ���� `visited` ��, �� �̵� �Ÿ��� ��ȯ�Ѵ�.
	- ���Ž�� ������ ���ִ� ������ ������ ��ĭ¥��(`r`=1, `c`=1)�� �� �ֱ� �����̴�.
3. ���Ž���� �Ѵ�.
	1. ������ �̵��� ��ġ�� ���� �ְ�, ���� ���� �μ� �� �ִ� �����̸�
		- ť�� ��ġ ������ 0(���̻� ���� �μ� �� ���� ����)�� �����Ѵ�.
		- `visited` �迭���� �̵��� ��ġ�� 3���� ���� 0��(���� �μ��� ����) ���� ���� ��ġ�� `visited`�� + 1�� �����Ѵ�.
	2. ������ �̵��� ��ġ�� ���� ����, ���� �湮���� ���� ���̶��
		- ť�� ��ġ ������ �� ���¸� �����Ѵ�.
		- �̵��� ��ġ�� `visited` �迭�� ���� ��ġ�� `visited`�� + 1�� �����Ѵ�.
4. ���߿� return ���� �ʾҴٸ� ���� �������� �� �� ���ٴ� ���̹Ƿ� -1�� ��ȯ�Ѵ�. 


# 2. ���� ��� ����(�ڵ� ����)