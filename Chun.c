
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void FirstGetBigger(int (*Arr2D)[20], int *Position_X, int *Position_Y, int* Arr_X, int* Arr_Y )
{

        Arr2D[*Position_X-1][*Position_Y-1]=2;//왼 대각 위 배치
        Arr_X[0] = *Position_X-1;
        Arr_Y[0] = *Position_Y-1;
        Arr2D[*Position_X-1][*Position_Y]=2;//위 배치
        Arr_X[1] = *Position_X-1;
        Arr_Y[1] = *Position_Y;
        Arr2D[*Position_X-1][*Position_Y+2]=2;//오른 대각 위 배치
        Arr_X[2] = *Position_X-1;
        Arr_Y[2] = *Position_Y+2;
        Arr2D[*Position_X][*Position_Y-1]=2;//왼쪽 배치
        Arr_X[3] = *Position_X;
        Arr_Y[3] = *Position_Y-1;
        Arr2D[*Position_X][*Position_Y]=2;
        Arr_X[4] = *Position_X;
        Arr_Y[4] = *Position_Y;
        Arr2D[*Position_X][*Position_Y+1]=2;//오른쪽 배치
        Arr_X[5] = *Position_X;
        Arr_Y[5] = *Position_Y+1;
        Arr2D[*Position_X+2][*Position_Y-1]=2;//왼 대각 아래 배치
        Arr_X[6] = *Position_X+2;
        Arr_Y[6] = *Position_Y-1;
        Arr2D[*Position_X+1][*Position_Y]=2;//아래 배치
        Arr_X[7] = *Position_X+1;
        Arr_Y[7] = *Position_Y;
        Arr2D[*Position_X+2][*Position_Y+2]=2;//오른 대각 아래 배치
        Arr_X[8] = *Position_X+2;
        Arr_Y[8] = *Position_Y+2;
    
}

// void Fbig_Chun_Moving(int (*Arr2D)[20], int* Arr_X, int *Arr_Y)
// {
//     int Move_Control_Num;
//     srand((unsigned int)time(NULL));
//     Move_Control_Num = rand() % 8 + 1; // 1~8

//     switch (Move_Control_Num)
//     {
//     case 1: // 왼쪽
//         if(*Position_Y>1)
//         {
//             Arr2D[*Position_X][*Position_Y] = 0;
//             (*Position_Y) -= 1;
//             Arr2D[*Position_X][*Position_Y] = 2;
//             break;
//         }
//         break;
        
//     case 2: // 오른쪽
//         if(*Position_Y<18)
//         {
//             Arr2D[*Position_X][*Position_Y] = 0;
//             (*Position_Y) += 1;
//             Arr2D[*Position_X][*Position_Y] = 2;
//             break;
//         }
//         break;

//     case 3: // 아래
//         if(*Position_X<18)
//         {
//             Arr2D[*Position_X][*Position_Y] = 0;
//             (*Position_X) += 1;
//             Arr2D[*Position_X][*Position_Y] = 2;
//             break;
//         }
//         break;

//     case 4: // 위
//         if(*Position_X>1)
//         {
//             Arr2D[*Position_X][*Position_Y] = 0;
//             (*Position_X) -= 1;
//             Arr2D[*Position_X][*Position_Y] = 2;
//             break;
//         }
//         break;
    
//     case 5: // 왼쪽 대각 위
//         if(*Position_X>1 && *Position_Y>1)
//         {
//             Arr2D[*Position_X][*Position_Y] = 0;
//             (*Position_X) -= 1;
//             (*Position_Y) -= 1;
//             Arr2D[*Position_X][*Position_Y] = 2;
//             break;
//         }
//         break;

//     case 6: // 오른쪽 대각 위
//         if(*Position_X>1 && *Position_Y<18)
//         {
//             Arr2D[*Position_X][*Position_Y] = 0;
//             (*Position_X) -= 1;
//             (*Position_Y) += 1;
//             Arr2D[*Position_X][*Position_Y] = 2;
//             break;
//         }
//         break;

//     case 7: // 왼쪽 대각 아래
//         if(*Position_X<18 && *Position_Y>1)
//         {
//             Arr2D[*Position_X][*Position_Y] = 0;
//             (*Position_X) += 1;
//             (*Position_Y) -= 1;
//             Arr2D[*Position_X][*Position_Y] = 2;
//             break;
//         }
//         break;

//     case 8: // 오른쪽 대각 아래
//         if(*Position_X<18 && *Position_Y<18)
//         {
//             Arr2D[*Position_X][*Position_Y] = 0;
//             (*Position_X) += 1;
//             (*Position_Y) += 1;
//             Arr2D[*Position_X][*Position_Y] = 2;
//             break;
//         }
//         break;
//     }
// }
//===================================================================================================
// void SecondGetBigger(int (*Arr2D)[20], int *Position_X, int *Position_Y)
// {

// }
void img()
{
    FILE *file;
        char line[100];
        file = fopen("/home/iot/Desktop/Sang_ho/게임시작.txt","r");
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
}

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

void supplies(int(*Arr2D)[20], int *HP_X, int* HP_Y,  int*FP_X, int* FP_Y)
{
    srand((unsigned int)time(NULL));
    int H_X, H_Y;
    int F_X, F_Y;
    int i;
    
    for(i=0; i<10; i++)
    {

        H_X=rand() % 17 + 1;
        H_Y=rand() % 17 + 1;
        if(Arr2D[H_X][H_Y]==0)
        { 
            Arr2D[H_X][H_Y]=3;
            HP_X[i] =H_X;
            HP_Y[i]=H_Y;
        
        }
    }

    for(i=0; i<10; i++)
    {
    
        F_X=rand() % 17 + 1;
        F_Y=rand() % 17 + 1;
        if(Arr2D[F_X][F_Y]==0)
        {
            Arr2D[F_X][F_Y]=4;
            FP_X[i] =F_X;
            FP_Y[i]=F_Y;
            
        }
    }
}
void HF_Clear(int (*Arr2D)[20])
{
    int i,j;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            if(Arr2D[i][j]==3 || Arr2D[i][j]==4)
                Arr2D[i][j]=0;
        }
    }
}
void Disease_Map_Print(int (*Arr2D)[20], int *Position_X, int *Position_Y)
{
    
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (Arr2D[i][j] == 1)
                printf("🔥 ");
            if (Arr2D[i][j] == 0)
                printf("   ");
            if(Arr2D[i][j]==3)
                printf("🏥 ");
            if(Arr2D[i][j]==4)
                printf("🍖 ");
            if (Arr2D[i][j] == 2)
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
        if(*Position_Y>1)
        {
            Arr2D[*Position_X][*Position_Y] = 0;
            (*Position_Y) -= 1;
            Arr2D[*Position_X][*Position_Y] = 2;
            break;
        }
        break;
        
    case 2: // 오른쪽
        if(*Position_Y<18)
        {
            Arr2D[*Position_X][*Position_Y] = 0;
            (*Position_Y) += 1;
            Arr2D[*Position_X][*Position_Y] = 2;
            break;
        }
        break;

    case 3: // 아래
        if(*Position_X<18)
        {
            Arr2D[*Position_X][*Position_Y] = 0;
            (*Position_X) += 1;
            Arr2D[*Position_X][*Position_Y] = 2;
            break;
        }
        break;

    case 4: // 위
        if(*Position_X>1)
        {
            Arr2D[*Position_X][*Position_Y] = 0;
            (*Position_X) -= 1;
            Arr2D[*Position_X][*Position_Y] = 2;
            break;
        }
        break;
    
    case 5: // 왼쪽 대각 위
        if(*Position_X>1 && *Position_Y>1)
        {
            Arr2D[*Position_X][*Position_Y] = 0;
            (*Position_X) -= 1;
            (*Position_Y) -= 1;
            Arr2D[*Position_X][*Position_Y] = 2;
            break;
        }
        break;

    case 6: // 오른쪽 대각 위
        if(*Position_X>1 && *Position_Y<18)
        {
            Arr2D[*Position_X][*Position_Y] = 0;
            (*Position_X) -= 1;
            (*Position_Y) += 1;
            Arr2D[*Position_X][*Position_Y] = 2;
            break;
        }
        break;

    case 7: // 왼쪽 대각 아래
        if(*Position_X<18 && *Position_Y>1)
        {
            Arr2D[*Position_X][*Position_Y] = 0;
            (*Position_X) += 1;
            (*Position_Y) -= 1;
            Arr2D[*Position_X][*Position_Y] = 2;
            break;
        }
        break;

    case 8: // 오른쪽 대각 아래
        if(*Position_X<18 && *Position_Y<18)
        {
            Arr2D[*Position_X][*Position_Y] = 0;
            (*Position_X) += 1;
            (*Position_Y) += 1;
            Arr2D[*Position_X][*Position_Y] = 2;
            break;
        }
        break;
    }
}

int main(void)
{
    int i, j;
    int Chun_Position_X = 0;
    int Chun_Position_Y = 0;
    int Hospital_X[10], Hospital_Y[10];
    int Food_X[10], Food_Y[10];
    int Turn_Count = 0;
    double Weight = 10;
    int Affection = 0;
    int Poop_Chance = 0;      // 2
    int Disease_Chance = 0;   // 1~10
    int Game_Over_Chance = 0; // 1~10
    int Recover_Chance = 0;
    int Bigger_P_X[8]={0,};
    int Bigger_P_Y[8]={0,};

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

    img();
    

    printf("게임 시작! 춘식이가 움직이기 시작합니다.\n");
    sleep(1);

    while(1)
    {
        system("clear");
        Turn_Count += 1;
        Affection += 10;
        Weight += 0.8;
        Poop_Chance = rand() % 2 + 1;     // 1~2 1이면 똥 쌈 
        Disease_Chance = rand() % 10000 + 1; // 1~10
    
        Chun_Moving(Chun_Room, &Chun_Position_X, &Chun_Position_Y);
        Map_Print(Chun_Room, &Chun_Position_X, &Chun_Position_Y);

        printf("%d회차 입니다.\n", Turn_Count);
        printf("춘식이가 밥을 먹습니다. 냠냠냠\n");
        printf("춘식이의 몸무게가 올라갑니다. +0.3kg, 현재 몸무게: %.2lfkg\n", Weight);
        printf("춘식이의 애정도가 올라갑니다. +5, 현재 애정도: %d°C입니다.\n", Affection);

        if (Poop_Chance == 1)
        {
            Weight -= 0.3;
            printf("춘식이가 똥을 쌌습니다. 몸무게 감소 - 0.2kg 현재 몸무게: %.2lfkg\n", Weight);
        }
        if(Weight>10)
        {
            printf("춘식이가 커졌습니다.");
            FirstGetBigger(Chun_Room, &Chun_Position_X, &Chun_Position_Y,Bigger_P_X,Bigger_P_Y);
            Map_Print(Chun_Room, &Chun_Position_X, &Chun_Position_Y);
        }

        if (Disease_Chance == 1)
        {
            int r;
            supplies(Chun_Room, Hospital_X, Hospital_Y, Food_X, Food_Y);
            for(r=0; r<10; r++)
            {
                printf("%d번째 약품위치 X좌표 %d, Y좌표 %d\n",r+1, Hospital_X[r], Hospital_Y[r]);
                printf("%d번째 음식위치 X좌표 %d, Y좌표 %d\n",r+1, Food_X[r], Food_Y[r]);
            }
            printf("\n\n\n=============================경고===============================\n");
            printf("춘식이가 병에 걸렸습니다. 춘식이가 병으로 인해 밥을 먹지 않습니다.\n");
            printf("지금부터 회복되기 전까지 계속 매턴 0.5kg 씩 빠집니다.\n");
            printf("춘식이가 질병모드로 전환됩니다.\n");
            
            sleep(5);
            printf("3\n");
            sleep(1);
            printf("2\n");
            sleep(1);
            printf("1\n");
            sleep(1);
            
            while (1)
            {
                system("clear");
                Game_Over_Chance = rand() % 100 + 1; // 1~10
                Recover_Chance = rand() % 1000+ 1;
                Chun_Moving(Chun_Room, &Chun_Position_X, &Chun_Position_Y);
                Disease_Map_Print(Chun_Room, &Chun_Position_X, &Chun_Position_Y);
                int h, f;

                Weight -= 0;
                Turn_Count += 1;
                Affection += 10;

                printf("%d회차 입니다.\n", Turn_Count);
                printf("병으로 인해 춘식이가 밥을 먹지 않습니다. 몸무게가 빠졌습니다. -0.5kg 현재 몸무게: %.2lfkg\n", Weight);
                printf("춘식이의 애정도가 올라갑니다. +10 현재 애정도: %d°C\n", Affection);
                
                //고기찾기 ============================================================
                if(Chun_Position_X==Food_X[0] && Chun_Position_Y==Food_Y[0])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[1] && Chun_Position_Y==Food_Y[1])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[2] && Chun_Position_Y==Food_Y[2])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[3] && Chun_Position_Y==Food_Y[3])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[4] && Chun_Position_Y==Food_Y[4])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[5] && Chun_Position_Y==Food_Y[5])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[6] && Chun_Position_Y==Food_Y[6])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[7] && Chun_Position_Y==Food_Y[7])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[8] && Chun_Position_Y==Food_Y[8])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                if(Chun_Position_X==Food_X[9] && Chun_Position_Y==Food_Y[9])
                {
                    printf("춘식이가 고기를 발견했습니다 10kg 증가합니다\n");
                    Weight += 10;
                }
                //병원찾기============================================================
                if(Chun_Position_X== Hospital_X[0] && Chun_Position_Y == Hospital_Y[0])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Chun_Position_X== Hospital_X[1] && Chun_Position_Y == Hospital_Y[1])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Chun_Position_X== Hospital_X[2] && Chun_Position_Y == Hospital_Y[2])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Chun_Position_X== Hospital_X[3] && Chun_Position_Y == Hospital_Y[3])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Chun_Position_X== Hospital_X[4] && Chun_Position_Y == Hospital_Y[4])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Chun_Position_X== Hospital_X[5] && Chun_Position_Y == Hospital_Y[5])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Chun_Position_X== Hospital_X[6] && Chun_Position_Y == Hospital_Y[6])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Chun_Position_X== Hospital_X[7] && Chun_Position_Y == Hospital_Y[7])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                
                if(Chun_Position_X== Hospital_X[8] && Chun_Position_Y == Hospital_Y[8])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Chun_Position_X== Hospital_X[9] && Chun_Position_Y == Hospital_Y[9])
                {
                    printf("춘식이가 병원에 다녀와 질병상태를 회복하였습니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                //병원찾기============================================================
                if(Game_Over_Chance == 40)
                {
                    break;
                }
                if(Recover_Chance == 1)
                {
                    printf("\n\n\n\n\n\n\n==========================행운=============================\n");
                    printf("춘식이가 질병에서 회복하였습니다. 다시 정상 모드로 복귀합니다.\n");
                    HF_Clear(Chun_Room);
                    break;
                }
                if(Weight < 0)
                    break; //2번째 반복문 빠져나오기
                
                sleep(1);
            }
        }
        if(Weight == 100)
        {
            printf("춘식이의 몸무게가 목표치에 도달하여 게임을 종료합니다.\n");
            printf("!!!!!!!!!!!!!!!!Congraturation!!!!!!!!!!!!!!!!!!!!\n");
            printf("회차: %d 몸무게: %.2lfkg 애정도: %d°C\n", Turn_Count, Weight, Affection);
            break;
        }

        if(Weight < 0)
        {
            printf("춘식이의 몸무게가 0이하가 되어 사망했습니다.\n");
            printf("Game Over\n");
            printf("회차: %d 몸무게: %.2lfkg 애정도: %d°C\n", Turn_Count, Weight, Affection);
            break; //1번째 반복문 빠져나오기
        }
        if(Game_Over_Chance == 40)
        {
            printf("질병으로 인해 춘식이가 사망했습니다.\n");
            printf("Game over\n");
            printf("회차: %d회 몸무게: %.2lfkg 애정도: %d°C\n",Turn_Count, Weight, Affection);
            break;
        }
        sleep(1);
    }
     return 0;
}

