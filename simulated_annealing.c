#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int elec_use[25] = {0, 943, 829, 765, 731, 721, 754, 860, 997, 1003, 954, 933, 942, 966, 957, 945, 954, 999, 1096, 1231, 1329, 1376, 1351, 1255, 1110};
int a, b; //y=ax+b
double tem=1, dec=0.9999, k=10, lim=0.0005;//tem:온도, dec:온도감률, k:볼츠만상수, lim:임계온도

int func(int xx)
{
    return (a*xx)+b;
}

int scoring() //오차(에러)값들의 합 = (평가함수)
{
    int score = 0;
    for(int i=1; i<25; i++)
    {
        if(elec_use[i]-func(i)<0) //평균제곱근오차 대신 오차가 음수일 경우 뺄셈을 사용
            score -= elec_use[i]-func(i);
        else
            score += elec_use[i]-func(i);
    }
    return score;
}

void simulated_annealing()
{
    srand(time(NULL));
    double now_s, next_s; //현재 선형함수의 평점, 다음 선형함수의 평점
    int a_sub, b_sub; //a와 b를 임시저장 할 temp
    while (tem > lim)
    {
        now_s = scoring();
        for(int i=1; i<25; i++)
        {
            a_sub = a;
            b_sub = b;
        }
        a = rand()%2000 + 1;
        b = rand()%2000 + 1;
        next_s = scoring();

        double percent = exp((now_s - next_s) / (k*tem)); //a와b값이 다음 랜덤값으로 변경 될 확률
        if(percent < (double)rand()) //1-p의 확률로 원래 a,b 값으로 되돌림
        {
            a = a_sub;
            b = b_sub;
        }
        tem *= dec; //실행할수록 온도를 낮춤
    }
}

int main(void)
{
    simulated_annealing();
    printf("%dx+%d", a, b);
}