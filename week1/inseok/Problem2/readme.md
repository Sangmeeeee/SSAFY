# 1. 알고리즘 설명(로직위주)

## 문제 이해

다중 조건 정렬 문제임!

## 실패

테스트 4가 값 52가 나와야 하는데 70이 나옴.. 뭔가 어디가 잘못 된거 같은데 계속 해도 안됨..

지금 머리에 딱 박혀가지고 나중에 다시 풀어보자.

# 2. 새로 배운 내용(코드위주)

## Comparable Interface

comparable 인터페이스에서 compareTo를 overriding 해서 sorting 을 할 수있다.

```
static class Block implements Comparable<Block> {//freq sort -> num sort //static?
        int num;
        int freq;
        Block(int num, int freq){
            this.num = num;
            this.freq = freq;
        }
        @Override
        public int compareTo(Block other) {//freq->num
            if(freq == other.freq){//오름 차순
                Integer.compare(num,other.num);
            }
            return Integer.compare(freq,other.freq);//오름차순
        }
    }
public static void main(String[] args) {
  List<Block> bl = new ArrayList<>();
  bl.add(5,2);
  b1.add(2,3);
  b1.add(3,2);
  Collections.sort(bl);
}
/*
  3,2
  5,2
  2,3
*/
```