
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void Map_Print(int (*Arr2D)[20], int *Position_X, int *Position_Y)
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (Arr2D[i][j] == 1)
                printf("🟫 ");
            else if (Arr2D[i][j] == 0)
                printf("   ");
            else if (Arr2D[i][j] == 2)
            {
                printf("🐱 ");
                *Position_X = i;
                *Position_Y = j;
            }
        }
        printf("\n");
    }
    printf("\n\n\n\n");
}

void Disease_Map_Print(int (*Arr2D)[20], int *Position_X, int *Position_Y)
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (Arr2D[i][j] == 1)
                printf("🟫 ");
            else if (Arr2D[i][j] == 0)
                printf("   ");
            else if (Arr2D[i][j] == 2)
            {
                printf("👿 ");
                *Position_X = i;
                *Position_Y = j;
            }
        }
        printf("\n");
    }
    printf("\n\n\n\n");
}

void Chun_Moving(int (*Arr2D)[20], int *Position_X, int *Position_Y)
{
    int Move_Control_Num;
    srand((unsigned int)time(NULL));
    Move_Control_Num = rand() % 8 + 1; // 1~8

    switch (Move_Control_Num)
    {
    case 1: // 왼쪽
        Arr2D[*Position_X][*Position_Y] = 0;
        (*Position_Y) -= 1;
        Arr2D[*Position_X][*Position_Y] = 2;
        break;

    case 2: // 오른쪽
        Arr2D[*Position_X][*Position_Y] = 0;
        (*Position_Y) += 1;
        Arr2D[*Position_X][*Position_Y] = 2;
        break;

    case 3: // 아래
        Arr2D[*Position_X][*Position_Y] = 0;
        (*Position_X) += 1;
        Arr2D[*Position_X][*Position_Y] = 2;
        break;

    case 4: // 위
        Arr2D[*Position_X][*Position_Y] = 0;
        (*Position_X) -= 1;
        Arr2D[*Position_X][*Position_Y] = 2;
        break;

    case 5: // 왼쪽 대각 위
        Arr2D[*Position_X][*Position_Y] = 0;
        (*Position_X) -= 1;
        (*Position_Y) -= 1;
        Arr2D[*Position_X][*Position_Y] = 2;
        break;

    case 6: // 오른쪽 대각 위
        Arr2D[*Position_X][*Position_Y] = 0;
        (*Position_X) -= 1;
        (*Position_Y) += 1;
        Arr2D[*Position_X][*Position_Y] = 2;
        break;

    case 7: // 왼쪽 대각 아래
        Arr2D[*Position_X][*Position_Y] = 0;
        (*Position_X) += 1;
        (*Position_Y) -= 1;
        Arr2D[*Position_X][*Position_Y] = 2;
        break;

    case 8: // 오른쪽 대각 아래
        Arr2D[*Position_X][*Position_Y] = 0;
        (*Position_X) += 1;
        (*Position_Y) += 1;
        Arr2D[*Position_X][*Position_Y] = 2;
        break;

    default:
        printf("오류");
        break;
    }
}

int main(void)
{
    int i, j;
    int Chun_Position_X = 0;
    int Chun_Position_Y = 0;
    int Turn_Count = 0;
    double Weight = 10;
    int Affection = 0;
    int Poop_Chance = 0;      // 2
    int Disease_Chance = 0;   // 1~10
    int Game_Over_Chance = 0; // 1~10
    int Recover_Chance = 0;

    int Chun_Room[20][20] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};


    Map_Print(Chun_Room, &Chun_Position_X, &Chun_Position_Y);
    sleep(2);
    printf("춘식이 키우기 게임에 오신걸 환영합니다. 잠시후 게임이 시작 됩니다.\n");
    sleep(2);
    printf("10\n");
    sleep(1);
    printf("9\n");
    sleep(1);
    printf("8\n");
    sleep(1);
    printf("7\n");
    sleep(1);
    printf("6\n");
    sleep(1);
    printf("5\n");
    sleep(1);
    printf("4\n");
    sleep(1);
    printf("3\n");
    sleep(1);
    printf("2\n");
    sleep(1);
    printf("1\n");
    sleep(1);

    printf("게임 시작! 춘식이가 움직이기 시작합니다.\n");
    sleep(1);

    while(1)
    {
        Turn_Count += 1;
        Affection += 10;
        Weight += 0.3;
        Poop_Chance = rand() % 2 + 1;     // 1~2 1이면 똥 쌈
        Disease_Chance = rand() % 10 + 1; // 1~10
    
        Chun_Moving(Chun_Room, &Chun_Position_X, &Chun_Position_Y);
        Map_Print(Chun_Room, &Chun_Position_X, &Chun_Position_Y);

        printf("%d회차 입니다.\n", Turn_Count);
        printf("춘식이가 밥을 먹습니다. 냠냠냠\n");
        printf("춘식이의 몸무게가 올라갑니다. +0.3kg, 현재 몸무게: %.2lfkg\n", Weight);
        printf("춘식이의 애정도가 올라갑니다. +5, 현재 애정도: %d°C입니다.\n", Affection);
        if (Poop_Chance == 1)
        {
            Weight -= 0.2;
            printf("춘식이가 똥을 쌌습니다. 몸무게 감소 - 0.2kg 현재 몸무게: %.2lfkg\n", Weight);
        }

        if (Disease_Chance == 1)
        {
            Weight -= 0.5;
            printf("=============================경고===============================\n");
            printf("춘식이가 병에 걸렸습니다. 춘식이가 병으로 인해 밥을 먹지 않습니다.\n");
            printf("지금부터 회복되기 전까지 계속 매턴 0.5kg 씩 빠집니다.\n");
            printf("춘식이가 병세모드로 전환됩니다.\n");
            
            sleep(5);
            printf("5\n");
            sleep(1);
            printf("4\n");
            sleep(1);
            printf("3\n");
            sleep(1);
            printf("2\n");
            sleep(1);
            printf("1\n");
            sleep(1);
            
            while (1)
            {
                Game_Over_Chance = rand() % 10 + 1; // 1~10
                Recover_Chance = rand() % 100 + 1;
                Chun_Moving(Chun_Room, &Chun_Position_X, &Chun_Position_Y);
                Disease_Map_Print(Chun_Room, &Chun_Position_X, &Chun_Position_Y);


                Weight -= 0.5;
                Turn_Count += 1;
                Affection += 10;

                printf("%d회차 입니다.\n", Turn_Count);
                printf("병으로 인해 춘식이가 밥을 먹지 않습니다. 몸무게가 빠졌습니다. -0.5kg 현재 몸무게: %.2lfkg\n", Weight);
                printf("춘식이의 애정도가 올라갑니다. +5 현재 애정도: %d°C\n", Affection);

                // if(Game_Over_Chance == 1)////문제 발생
                // {
                //     printf("춘식이가 죽었습니다. 게임이 종료됩니다.\n");
                //     printf("Game Over");
                // }
                if(Recover_Chance == Affection * 0.1)
                {
                    printf("==========================행운=============================\n");
                    printf("춘식이가 질병에서 회복하였습니다. 다시 정상 모드로 복귀합니다.\n");
                    break;
                }
                
                sleep(1.5);
            }
        }
 
        sleep(1.5);
    }

    return 0;

    Disease_Die:
        printf("Game over");
}
