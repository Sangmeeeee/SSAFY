# 정규 문제
|  | 월 | 화 | 수 | 목 | 금 |
| --- | :---: | :---: | :---: | :---: | :---: |
| 1주차 | [문자열 폭발](https://www.acmicpc.net/problem/9935) | [이차원 배열과 연산](https://www.acmicpc.net/problem/17140) | [괄호 제거](https://www.acmicpc.net/problem/2800) | [센서](https://www.acmicpc.net/problem/2212) | [괄호 회전하기](https://programmers.co.kr/learn/courses/30/lessons/76502) |

# 추가 문제

| 문제 | 해결한 사람 | 풀이링크 |
| :---: | :---: | :---: |

# 깃허브 사용법

#### 현재 branch 확인 command

-   git branch
    
    ```
      isangmin@isangmin-ui-MacBookPro SSAFY % git branch
    
    ```
    

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#branch-%EC%83%9D%EC%84%B1-command)branch 생성 command

-   git branch '원하는 branch 이름'
    
    ```
      isangmin@isangmin-ui-MacBookPro SSAFY % git branch test_branch
    
    ```
    

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#branch-%EC%9D%B4%EB%8F%99-command)branch 이동 command

-   git checkout '원하는 branch 이름'
    
    ```
      isangmin@isangmin-ui-MacBookPro SSAFY % git checkout test_branch
    
    ```
    

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#%EC%9D%B4%EB%8F%99%ED%95%9C-branch%EC%97%90%EC%84%9C-git-add-command)(이동한 branch에서) git add command

##### [](https://github.com/Girin7716/KNU-Algorithm-Study#-add-%ED%95%98%EA%B8%B0-%EC%A0%84-%EB%B3%B8%EC%9D%B8%EC%9D%B4-%EA%B9%83%ED%97%88%EB%B8%8C%EC%97%90-%EC%98%AC%EB%A6%B4-%ED%8C%8C%EC%9D%BC%EC%9D%84-%EB%B8%8C%EB%9E%9C%EC%B9%98-%EC%95%88%EC%97%90-%EB%84%A3%EC%96%B4%EC%A4%98%EC%95%BC-%ED%95%9C%EB%8B%A4-%EB%AF%B8%EB%A6%AC-knu-algorithm-study-%ED%8F%B4%EB%8D%94%EC%97%90-branch_texttxt%ED%8C%8C%EC%9D%BC%EC%9D%84-%EB%A7%8C%EB%93%A4%EC%96%B4-%EB%86%93%EC%95%98%EB%8B%A4-%EC%9B%90%EB%9E%98%EB%8C%80%EB%A1%9C%EB%9D%BC%EB%A9%B4-%EB%B3%B8%EC%9D%B8%EC%9D%B4-%EC%9E%91%EC%84%B1%ED%95%9C-%EC%BD%94%EB%93%9C%EB%A5%BC-%EB%B3%B8%EC%9D%B8%EC%9D%98-%ED%8F%B4%EB%8D%94%EC%95%88%EC%97%90-%EB%84%A3%EC%96%B4%EB%86%93%EC%9D%80-%EC%83%81%ED%83%9C%EB%A9%B4-%EB%90%9C%EB%8B%A4)※ add 하기 전, 본인이 깃허브에 올릴 파일을 브랜치 안에 넣어줘야 한다. (미리 KNU-Algorithm-Study 폴더에 branch_text.txt파일을 만들어 놓았다. 원래대로라면 본인이 작성한 코드를 본인의 폴더안에 넣어놓은 상태면 된다.)

-   git add *
    
    ```
      isangmin@isangmin-ui-MacBookPro SSAFY % git add *
    
    ```
    

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#%EC%9D%B4%EB%8F%99%ED%95%9C-branch%EC%97%90%EC%84%9C-git-commit-command)(이동한 branch에서) git commit command

-   git commit -m '원하는 커밋 내용'
    
    ```
      isangmin@isangmin-ui-MacBookPro SSAFY % git commit -m "test_branch_commit"
    
    ```
    

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#%EC%9D%B4%EB%8F%99%ED%95%9C-branch%EC%97%90%EC%84%9C-git-push-command)(이동한 branch에서) git push command

-   git push origin '현재 브랜치 이름'
    
    ```
      isangmin@isangmin-ui-MacBookPro SSAFY % git push origin test_branch
    
    ```
    

### [](https://github.com/Girin7716/KNU-Algorithm-Study#%EC%9D%B4-%EB%8B%A8%EA%B3%84%EA%B9%8C%EC%A7%80-%EC%99%84%EB%A3%8C%ED%95%9C%EB%8B%A4%EB%A9%B4-%EB%B3%B8%EC%9D%B8%EC%9D%98-pc%EC%97%90%EC%84%9C-%EC%B2%98%EB%A6%AC-%ED%95%A0-%EC%9D%BC%EC%9D%80-%EB%81%9D%EB%82%98%EA%B2%8C-%EB%90%9C%EB%8B%A4)이 단계까지 완료한다면 본인의 PC에서 처리 할 일은 끝나게 된다.

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#github-knu-algorithm-study%EB%A1%9C-%EC%9D%B4%EB%8F%99)github SSAFY로 이동

-   SSAFY 레포지토리로 이동하면 본인이 변경한 사항이 아직 Merge되지 않았기 때문에 pull request후 merge를 해줘야한다.
-   상단의 Compare & pull request 클릭 -> Open pull request page로 자동 이동

[![](https://github.com/Girin7716/KNU-Algorithm-Study/raw/master/img/1.png)](https://github.com/Girin7716/KNU-Algorithm-Study/blob/master/img/1.png)

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#open-pull-request-page)Open pull request page

-   본인이 작성한 커밋 내용과 간단한 comment를 남길 수 있는 화면이 보인다.
-   comment를 남기지 않는다면, 우측 하단의 Create pull request 클릭 -> branch page로 자동이동
-  좌측 상단의 base branch를 week1으로 설정하고 compare 브랜치가 본인의 이름이 맞는지 확인한다.

[![](https://github.com/Girin7716/KNU-Algorithm-Study/raw/master/img/2.png)](https://github.com/Girin7716/KNU-Algorithm-Study/blob/master/img/2.png)

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#branch-page)branch page

-   본인이 커밋한 내용을 확인 할 수 있음
-   만약 이 브랜치를 최종적으로 week1 브랜치에 합치고 싶다면 좌측 하단의 Merge pull request 클릭

[![](https://github.com/Girin7716/KNU-Algorithm-Study/raw/master/img/3.png)](https://github.com/Girin7716/KNU-Algorithm-Study/blob/master/img/3.png)

-   Merge pull request 후 branch를 삭제해준다.

[![](https://github.com/Girin7716/KNU-Algorithm-Study/raw/master/img/4.png)](https://github.com/Girin7716/KNU-Algorithm-Study/blob/master/img/4.png)

-   week branch에 변경사항이 성공적으로 merge되었는지 확인해준다.

[![](https://github.com/Girin7716/KNU-Algorithm-Study/raw/master/img/5.png)](https://github.com/Girin7716/KNU-Algorithm-Study/blob/master/img/5.png)

### [](https://github.com/Girin7716/KNU-Algorithm-Study#%EB%8B%A4%EC%8B%9C-%EB%B3%B8%EC%9D%B8%EC%9D%98-git-bash%EB%82%98-%ED%84%B0%EB%AF%B8%EB%84%90%EB%A1%9C-%EB%8F%8C%EC%95%84%EC%99%80%EC%84%9C-%EB%B8%8C%EB%9E%9C%EC%B9%98%EB%A5%BC-%EC%82%AD%EC%A0%9C%ED%95%B4%EC%A4%80%EB%8B%A4)다시 본인의 git bash나 터미널로 돌아와서 브랜치를 삭제해준다.

#### [](https://github.com/Girin7716/KNU-Algorithm-Study#%EC%82%AD%EC%A0%9C%ED%95%98%EA%B8%B0-%EC%A0%84%EC%97%90-master-branch%EB%A1%9C-%EC%9D%B4%EB%8F%99%ED%95%B4%EC%A4%80%EB%8B%A4)삭제하기 전에 master branch로 이동해준다.

-   git branch -D '삭제할 브랜치 이름'
    
    ```
      isangmin@isangmin-ui-MacBookPro SSAFY % git branch -D test_branch
    
    ```
    

이 단계까지 왔으면 branch를 생성하고 commit하고 삭제하는 과정이 종료되게 된다.
