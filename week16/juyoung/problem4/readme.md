# Info

���� : [Ʃ��](https://programmers.co.kr/learn/courses/30/lessons/64065)

�˰����� ���� : 

���� url : [�ٸ� ����� Ǯ�̿� '-'�� �ڵ�](https://programmers.co.kr/learn/courses/30/lessons/64065/solution_groups?language=cpp)


# 1. �˰����� ����

### :star: problem4.cpp

���� ���� Ǭ.. ���� ���� Ǯ��.. ^_��  

:round_pushpin: ��ü Ǯ��  
ù°, **�Է� ���ڿ����� �� ������ 2���� ���Ϳ� �����Ѵ�.**

���� ���ڰ� �����̸� ���ڸ� 1���� ���Ϳ� �����Ѵ�.  
�׷��� �ʴٸ� ��� ó���� �ʿ��ѵ� �̶�, ������ ������ ���� ������ ����ߴ�.  
���� ���ڰ� '{'��� ���ÿ� push�ϰ�, '}'��� ������ pop�Ѵ�.  
�׷��ٰ� ���� ���ڰ� ','�̸� ������ ����ִ� ���� ������� ���� ���� ������.

���� ������ ����ִٸ� ��� �� ������ �������� �ǹ��ϱ� ������  
������� ���ڸ� ������ 1���� ���͸� 2���� ���Ϳ� ������ �� 1���� ���͸� �ʱ�ȭ�Ѵ�.  
���� ������ ������� �ʴٸ�, ���� ���� ���̶�� �ǹ��̹Ƿ� ���� ó���� �ʿ䰡 ����.

��°, 2���� ���Ϳ� ���� ���� ���Ͱ� ���Ե� ��, **2���� ���͸� �����Ѵ�.**  
�̶� `cmp`��� ����� ���� �Լ��� ���� ���� ������ �������� �����ϵ��� �ߴ�.

��°, **���ĵ� 2���� ���͸� ��ȸ�ϸ� ���� ���Ϳ� ���ڸ� �����Ѵ�.**  

���ĵ� ���� �ȿ��� ���ʴ�� ������ ������ 1��, 2��, 3��, 4���� ���Ͱ� �ִ�.  
���� �ȿ��� ���� ������ �ٲ� ��찡 �ֱ� ������ map�� �̿��Ͽ� �ߺ��� ���� ���� �ʵ��� �ߴ�.  
map ���� �������� �ʴ� ���̸� ���� �迭�� ������ �� map�� �߰��߰�,  
map ���� �����ϴ� ���̸� �ƹ� ó�� ���� �Ѿ��.

:round_pushpin:  
������ Ǫ�� ���� �����ؼ� Ǯ������ �̷� Ǯ�̰� ���Դ�...  
�׽�Ʈ���̽� 10���뿡�� ����ð��� ���� 3000ms�� �����淡 ���ߴٰ� �����ߴ�.  

Ǯ�������� �������� �ڷᱸ���� ���� ���� �ڵ尡 �����ٰ� �����µ�  
�ٸ� ��� �ڵ带 ���ϱ� Ȯ��������...�Ф�  
�׷��� �ٸ� �ڵ带 �����ؼ� �ٽ� �ѹ� ¥�� �� `problem4_2.cpp`�̴�.


### :star: problem4_2.cpp

:round_pushpin:  
**������ `flag` �迭�� ����Ͽ� Ʃ���� ���� ��Ҹ� ǥ���Ѵ�.**  
���� `flag[10] = 3`�̶�� 4���� ���� �� 3���� ���տ� 10�� ����ִٴ� �ǹ��̴�.  
Ʃ���� ù��° ���Ҵ� ���տ� 4��, �ι�° ���Ҵ� 3��, ����° ���Ҵ� 2��, �׹�° ���Ҵ� 1�� �����Ѵٴ� ���� �̿��ϴ� ���̴�.    

�Է� ���ڿ��� Ž���� ��, �����̰ų� �ƴ� ��츸�� �����Ѵ�.  
1. `s[i]`�� ���ڶ��
	- ���ڿ� `number`�� ���Ѵ�.
2. `s[i]`�� ���ڰ� �ƴ϶��, �׸��� `number`�� ���ڿ��� ����Ǿ� �ִٸ�
	- `flag[stoi(number)]`�� 1��ŭ ������Ű�� `number`�� �ʱ�ȭ�Ѵ�.

�׸��� �� ������ �����ϴ� pair�� ���� `numbers`�� ����ϴµ�,  
���⿡ Ʃ���� ���� ��ҿ� ���տ� ������ Ƚ��(`flag`�� ����� ��)�� �����Ѵ�.
�׸��� `numbers` ���͸� ���� ��Ұ� ���տ� ������ Ƚ���� �������� �����Ѵ�.

�׸��� ������ ���� ���ʴ�� ���� �迭 `answer`�� �����ϸ� �ȴ�.

:round_pushpin:  
Ȯ���� ���� Ǭ Ǯ�̶� ���� ����ð� ���̰� ��û ����...  
���ڿ����� �ʿ��� �κи� �����ϰ�, �ڷᱸ���� �ܼ��� �迭�� ���� �Ǵ� �ſ��µ�  
�ʹ� ��ư� �����ϰ� Ǭ �� ����...


# 2. ���� ��� ����(�ڵ� ����)
[����](https://learncom1234.tistory.com/6)

### 2���� ���Ϳ��� 1���� ������ ���� �������� �����ϱ�
```cpp
bool cmp(vector<int> a, vector<int> b) {
	return a.size() < b.size();
}
sort(v.begin(), v.end(), cmp);
```