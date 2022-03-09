문제 : [수들의 합4](https://www.acmicpc.net/problem/2015)

알고리즘 종류 : 누적합

참조 url : 

# 1. 알고리즘 설명

처음에는 투포인터로 해결하는 문제인가 싶었지만 정렬도 불가능하고 음수까지 중간에 껴 있어서 불가능하다고 판단했다.

구간합을 하나하나 구하기에는 n^2의 시간이 걸려 불가능하고

결국 누적합을 이용해서 구간합을 구해야한다는 생각까지는 했지만 sum[i] - sum[j] = N이라는 식을 찾는데는 생각할 시간이 좀 필요했다.

이 문제의 결론은 K까지의 누적합을 전부 구한 뒤 누적합을 이용해서 구간합을 구해 해결하는 문제이다.

시간 복잡도는 n의 원소에대해 HashMap을 통해 찾기 때문에 n이 된다.

정답의 조건은 sum[i] - sum[j] = N 이 되는데,

sum[i]는 i번째 idx까지의 누적합, sum[j]는 j번째 idx까지의 누적합이다.

이 둘을 빼주게 되면 j ~ i까지의 구간합이 나오게 된다.

그렇다면 만약 i번째 idx가 들어왔을 때, i - 1까지의 각각의 idx에 대한 누적합이 sum[i] - N이 된다면 이는 각각 idx부터 i까지의 구간합이 N이라는 소리이다.

sum[i] - sum[j] = N이라는 소리는 sum[i] - N = sum[j]와 같기 때문이다.

예를들어 N이 5이고 현재 i까지의 누적합은 500이라고 가정한다면 1 ~ i-1 까지의 누적합을 봤을때 1, 3, 8번째 idx의 누적합이 495라 하자.

1번째 idx에서 i번째 idx까지의 구간합은 5가 된다. i가 아무리 크다고 해봤자 1에서 i까지의 구간합은 5밖에 되지 않고 이는 정답이 된다.

그 다음으로 3번째 idx에서 i번째 idx까지의 구간합 또한 5가 된다.

이를 i번째 idx가 들어올때마다 반복해주는데, map을 이용하여 해결해준다. 결국 i번째 idx가 들어왔을때 필요한건 sum[i] - N이 존재하는지, 존재한다면 갯수가

몇개인지 필요하기 때문이다.

   1. i번째 idx까지의 누적합을 구한 후 map에 sum[i] - N의 key가 존재하는지 보고 있다면 갯수를 가져온다.
   2. i번째 idx까지의 누적합 또한 map에 넣어주는데, 해당 누적합이 존재한다면 갯수를 1 증가해주고 없다면 새로 넣어준다.

# 2. 새로 배운 내용