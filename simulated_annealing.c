#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int elec_use[25] = {0, 943, 829, 765, 731, 721, 754, 860, 997, 1003, 954, 933, 942, 966, 957, 945, 954, 999, 1096, 1231, 1329, 1376, 1351, 1255, 1110};
int a, b; //y=ax+b
double tem=1, dec=0.9999, k=10, lim=0.0005;//tem:�µ�, dec:�µ�����, k:���������, lim:�Ӱ�µ�

int func(int xx)
{
    return (a*xx)+b;
}

int scoring() //����(����)������ �� = (���Լ�)
{
    int score = 0;
    for(int i=1; i<25; i++)
    {
        if(elec_use[i]-func(i)<0) //��������ٿ��� ��� ������ ������ ��� ������ ���
            score -= elec_use[i]-func(i);
        else
            score += elec_use[i]-func(i);
    }
    return score;
}

void simulated_annealing()
{
    srand(time(NULL));
    double now_s, next_s; //���� �����Լ��� ����, ���� �����Լ��� ����
    int a_sub, b_sub; //a�� b�� �ӽ����� �� temp
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

        double percent = exp((now_s - next_s) / (k*tem)); //a��b���� ���� ���������� ���� �� Ȯ��
        if(percent < (double)rand()) //1-p�� Ȯ���� ���� a,b ������ �ǵ���
        {
            a = a_sub;
            b = b_sub;
        }
        tem *= dec; //�����Ҽ��� �µ��� ����
    }
}

int main(void)
{
    simulated_annealing();
    printf("%dx+%d", a, b);
}