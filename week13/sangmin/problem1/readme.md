문제 : [거짓말](https://www.acmicpc.net/problem/1043)

알고리즘 종류 : 유니온파인드

참조 url :

# 1. 알고리즘 설명

유니온파인드 문제였다.

조금 의아했던건 파티에 참석하는 인원이 오름차순으로 입력되었다는건데 문제 어디에도 그런 내용은 적혀있지 않아 좀 신경써줘야한다. 이유는 나중에 설명할것이다.

일단 각 사람들의 부모정보를 담고있을 parents배열과 해당 인원이 거짓말쟁이인걸 알고있는 사람들을 저장할 isKnown 배열을 둔다.

내가 생각한 기본 전략은 일단 모든 파티를 돌면서 각 노드간의 연관관계를 만들어준다.

이 때 내가 왜 오름차순으로 입력됬다는게 중요하다 했냐면 만약 생각없이 집합을 만들어주면 알고있던 사람에 속해있던 트리는 루트가 항상 알고있는 사람이여야 하는데

모르는 사람이 루트를 차지할 수도 있다. 따라서 union시 둘중 하나라도 알고있는 사람일경우 무조건적으로 해당 노드를 부모로 해준다.

만약 둘 다 모르는 사람일경우 단순하게 합해줘도 괜찮다.

모든 파티에 대해 유니온 파인드를 돌리고 나면 한번이라도 알고있는 사람들과 접촉한 사람의 부모는 알고있는 사람이 된다.

따라서 다시 한번 파티를 돌면서 해당 파티에 속해있는 모든 사람에 대해 findParent를 해주고 만약 findParent로 찾은 부모가 isKnown에 속할경우 해당 파티는

참가하지 못한다고 판단하고 참가하지 못하는 파티를 모두 세어 전체 파티에서 빼준다.

# 2. 새로 배운 내용

