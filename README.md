# 모의 담금질 기법을 통한 회귀식 추정  
*인천대학교 정보통신공학과 201901687 양수진*
# 목차
    1. 모의 담금질 기법이란?
    2. 내가 선정한 데이터셋
    3. 작성한 코드의 동작방식
    4. 함수 및 매개변수 설명
    5. 코드 실행결과
    6. 데이터셋과 비교
    7. 결론
    8. 소감

1. **모의 담금질 기법이란?**
* 온도를 낮춰가며 최적해에 가까워지고 임계온도에 다다랐을때 전역 최적해에 가장 근사한 값을 도출하는 확률적 메타 알고리즘이다.

---
2. **내가 선정한 데이터셋**
* 현실에 실존하는 현상에 대한 실제값들 중 **2021년 6월 주택용 1~24시 전력소비계수**를 선정하였다.  
*전력소비자의 시간별 소비량 데이터를 바탕으로 가공된 상대계수로, 일간 평균을 기준(=1,000)으로 하여 시간별 사용량을 상대적으로 산출*
![image](https://user-images.githubusercontent.com/101388182/173496133-c56b9605-71f6-4bf3-98c1-54033914256a.png)
![image](https://user-images.githubusercontent.com/101388182/173863459-69235bc4-14dd-48a7-bd66-7c0fddc3d771.png)

출처: https://kosis.kr/statHtml/statHtml.do?orgId=310&tblId=DT_3664N_1&vw_cd=MT_ZTITLE&list_id=U_12&seqNo=&lang_mode=ko&language=kor&obj_var_id=&itm_id=&conn_path=MT_ZTITLE


---
3. **작성한 코드의 동작방식**
    1. 원하는 반복실행횟수를 생각하여 초기온도와 매 회차마다 감소할 온도감률, 도달시 반복실행을 종료할 임계온도를 설정한다
    2. 랜덤으로 y=ax+b 의 a와b를 설정하고 실제 데이터셋과의 오차값을 절대값으로 합하는 평가함수를 통해 평가값을 매긴다
    3. 평가값에 따라 더 최적인 a,b값으로 현재값을 수정하는 확률을 산출하고 랜덤값을 이용하여 확률에 따라 이행
    4. 반복실행이 종료되었을때 a,b값을 출력

---
4. **함수 및 매개변수 설명**
>함수
* ***func*** : 예측함수인 y=ax+b 의 x값에 따른 y값 리턴
* ***scoring*** : 오차값들의 절대값을 모두 더한 평가점수를 리턴
* ***simulated_annealing*** : 모의담금질 알고리즘 실행함수  

>매개변수
* ***elec_use*** : 시간별 전력소비계수
* ***a, b*** : 예측함수인 y=ax+b의 a와b
* ***tem*** : 초기온도
* ***dec*** : 매 반복실행마다 일정비율로 온도를 감소시키는 온도감률
* ***k*** : 볼츠만상수(*기체 1몰과 관계 있는 보편 기체 상수를 아보가드로수로 나눈 값으로 열 운동의 에너지와 온도가 관계를 맺게 하는 역할을 하며 1.380×10－23J/K이다. 코드에서는 간단하게 10으로 정의했다.*)
* ***lim*** : 도달하면 반복실행을 종료할 임계온도
* ***score*** : 평가함수를 통해 산출된 평가값
* ***now_s, next_s*** : 현재 예측함수의 평가값, 다음 실행회차의 예측함수 평가값
* ***a_sub, b_sub*** : a와b값을 임시저장할 변수


---
5. **코드 실행결과**
* 실행시간 단축을 위해 반복실행 횟수를 비교적 한정적으로 설정하였기 때문에 코드를 실행할때마다 최종 예측값이 조금씩 달라진다.  
1차 예측값: ![image](https://user-images.githubusercontent.com/101388182/174005579-8beee2de-43b7-4044-9d74-41bd9f8bd684.png)  
2차 예측값: ![image](https://user-images.githubusercontent.com/101388182/174006059-06e00618-d3d9-4657-9afa-f037cf850beb.png)  
3차 예측값: ![image](https://user-images.githubusercontent.com/101388182/174006119-c0547cf9-0721-4b3d-8c98-01dacae8e63d.png)  

---
6. **데이터셋과 비교**  
![image](https://user-images.githubusercontent.com/101388182/174011713-eea0f1c0-4814-43a9-9f9c-a4452f5c7359.png)  
* 1, 2, 3차 모두 데이터셋에 대하여 선형예측그래프를 그리고 있고 서로 기울기 등이 비슷하다.
---
7. **결론**
* 1차, 2차, 3차 예측그래프가 서로 많은 차이는 안나지만 코드에서 온도감률을 더 낮춰서 반복횟수를 기하급수적으로 증가시켜주면 더 정확한 예측값을 산출할 수 있을 것이다.
* 위의 3차례의 예측중 평균값에 가까운 2차 예측이 가장 예측그래프에 적절할 것이다.

---
8. **소감**  
처음 시작할때는 그냥 알고리즘의 한 종류인 줄 알았는데 진행할수록 인공지능 딥러닝의 간이버전인것 같았다. 뭔가 대단하고 멀게만 느껴졌던 딥러닝 분야가 친숙하게 느껴진 순간이었다.
이번 기말고사에서는 모의담금질을 이용해야해서 물리적인 공식을 일부 채용하였지만 자유로운 조건에서는 더 이해하기 쉬운 평가값과 확률 산출공식을 사용할 수 있을 것 같다.
