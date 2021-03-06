문제 : [센서](https://www.acmicpc.net/problem/2212)

알고리즘 종류 : 정렬

참조 url :

# 1. 알고리즘 설명

거리가 최소가 되기 위해선 가장 멀리떨어진 센서들을 다른 집중국으로 묶어줘야한다.

    4
    3
    1  2  100 10000

위와같이 극단적인 상황을 가정으로 두었을때 4개의 센서 중 가장 서로 동떨어져있는 100과 1000에 집중국을 설치해야한다.

결론은 센서간의 거리 차이로 정렬했을 때, 가장 거리차이가 많이 나는 센서끼리에는 집중국을 설치해줘야한다.

위와같이 100과 10000사이에는 엄청난 격차가 존재하기 때문에 100과 10000에 집중국을 설치해서 따로 관리해준다.

    4
    2
    1000 1999 2999

이런 상황에서는 1000과 1999의 사이도 크고 1999와 2999의 사이도 크지만

결국 두 수의 차이가 가장 큰 구간은 1999와 2999이다.

집중국을 만약 1000과 1999에 설치해버리면 1999에 설치한 집중국은 2999까지 커버해야해서 거리는 1000이 된다.

반대로 집중국을 1000(혹은 1999)과 2999에 설치해버리면 1000의 설치국은 1999까지만 커버하면 되기 때문에 거리는 999로 가장 작아진다.

이를 단계별로 나타내면

1. 각 센서별 거리의 차이를 오름차순으로 정렬한다.

2. 중개국이 K개 이면 결국 K - 1개의 거리의 차이를 지울 수 있다. 중개국 2개에 1개의 거리를 차이를 지울 수 있고
중개국 3개에 2개의 거리 차이를 지울 수 있다. 이는 중개국으로 이어져있는 선분을 나눈다고 생각하면 편할것 같다.(중개국 2개 사이의 구간이 삭제되는 느낌)
   
3. 결국은 거리의 차이의 개수  - (K-1) 개만큼 오름차순으로 정렬된 거리의 차이를 더하게 되고 답이 나오게 된다.

# 2. 새로 배운 내용