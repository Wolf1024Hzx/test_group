#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define screen_height 19
#define screen_width 21
char screen[screen_height + 2][screen_width + 2];
typedef struct
{
    char direction;
    int x_place;
    int y_place;
}Ball;
typedef struct 
{
    char direction;
    int x_place;
    int y_place;
    int length;
}Board;
void renew_board_box(Board *board);
void renew_screen();
void move_ball(Ball *ball);
void block_change_direction(Ball *ball,int mode);
void creat_map(Ball *ball,Board *board);
void move_board(Board *board,char control);
void board_collision(Ball *ball, Board *board);
int block_collision(Ball *ball);
int main()
{
    while(1){
        memset(screen, 0, sizeof(screen));
        printf("按任意键继续\n");
        system("pause");
        Ball ball;
        Board board;
        int i = 0, flag = 0;
        char control = 's', tempc;
        creat_map(&ball, &board);
        renew_board_box(&board);
        while (1)
        {
            do{
                move_board(&board, control);
                if (ball.x_place != 2)
                    while (block_collision(&ball))
                        renew_board_box(&board);
                else
                    board_collision(&ball, &board);
                if (!i)
                    move_ball(&ball);
                renew_board_box(&board);
                renew_screen();
                if (ball.x_place == 1){
                    flag = 1;
                    break;
                }
                i = (i + 1) % 3;
                Sleep(5);
                system("cls");
            } while (!kbhit());
            if (flag)
                break;
            tempc = getch();
            if (tempc != control)
                control = tempc;
    }
    printf("YOU LOSE\n");
    }
}

void move_board(Board *board, char control)//木板的移动
{
    switch(control)
    {
        case 'a':
            board->direction = 4;
            if(board->y_place-board->length/2>1)
            {
                screen[1][board->y_place + board->length / 2] = 0;
                board->y_place--;
            }else board->direction = 5;
            break;
        case 'd':
            board->direction = 6;
            if(board->y_place+board->length/2<screen_width)
            {
                screen[1][board->y_place - board->length / 2] = 0;
                board->y_place++;
            }else board->direction = 5;
            break;
        default: board->direction = 5;
    }
    return;
}

void renew_board_box(Board *board)//更新木板和边框
{
    for (int i = board->y_place - board->length / 2; i <= board->y_place + board->length / 2; i++)
        screen[board->x_place][i] = 1;
    for (int i = 0; i < screen_width + 2;i++)
    {
        screen[0][i] = 1;
        screen[screen_height + 1][i] = 1;
    }
    for (int i = 1; i < screen_height + 1; i++)
    {
        screen[i][0] = 1;
        screen[i][screen_width + 1] = 1;
    }
    return;
}

void creat_map(Ball *ball,Board *board)//随机创建一个地图
{
    srand((unsigned) time(NULL));
    for (int i = 7; i <= screen_height; i++)
        for (int j = 1; j <= screen_width; j++)
            screen[i][j] = rand() % 2;
    board->y_place = screen_width / 2 + 1;
    board->x_place = 1;
    board->direction = 5;
    board->length = 7;
    ball->y_place = screen_width / 2 + 1;
    ball->x_place = 2;
    ball->direction = 8;
    screen[ball->x_place][ball->y_place] = 1;
    return;
}

void renew_screen()//刷新屏幕
{
    char a[(screen_height + 2) * (screen_width + 3) + 1];
    int p = 0;
    for (int i = screen_height + 1; i >= 0; i--)
    {
        for (int j = 0; j <= screen_width + 1; j++)
        {
            if(screen[i][j])
                a[p] = '+';
            else
                a[p] = ' ';
            p++;
        }
        a[p] = '\n';
        p++;
    }
    a[p] = '\0';
    puts(a);
    return;
}

void move_ball(Ball *ball)//小球的移动
{
    screen[ball->x_place][ball->y_place] = 0;
    switch(ball->direction)
    {
        case 8:{ball->x_place++;}
            break;
        case 4:{ball->y_place--;}
            break;
        case 6:{ball->y_place++;}
            break;
        case 2:{ball->x_place--;}
            break;
        case 7:{ball->x_place++;ball->y_place--;}
            break;
        case 9:{ball->x_place++;ball->y_place++;}
            break;
        case 1:{ball->x_place--;ball->y_place--;}
            break;
        case 3:{ball->x_place--;ball->y_place++;}
            break;
    }
    screen[ball->x_place][ball->y_place] = 1;
    return;
}

void block_change_direction(Ball *ball,int mode)//小球与静态方块碰撞的方向计算
{
    switch(ball->direction)
    {
        case 8:
            ball->direction = 2;
            break;
        case 4:
            ball->direction = 6;
            break;
        case 6:
            ball->direction = 4;
            break;
        case 2:
            ball->direction = 8;
            break; 
        case 7:
            if(mode==1)
                ball->direction = 9;
            else if(mode==2)
                ball->direction = 1;
            else if(mode==3)
                ball->direction = 3;
            break;
        case 9:
            if(mode==1)
                ball->direction = 3;
            else if(mode==2)
                ball->direction = 7;
            else if(mode==3)
                ball->direction = 1;
            break;
        case 1:
            if(mode==1)
                ball->direction = 7;
            else if(mode==2)
                ball->direction = 3;
            else if(mode==3)
                ball->direction = 9;
            break;
        case 3:
            if(mode==1)
                ball->direction = 1;
            else if(mode==2)
                ball->direction = 9;
            else if(mode==3)
                ball->direction = 7;
            break;
    }
    return;
}

int block_collision(Ball *ball)//小球与方块的碰撞计算
{
    switch(ball->direction)
    {
        case 8:
            if(screen[ball->x_place+1][ball->y_place]==1){
                screen[ball->x_place+1][ball->y_place] = 0;
                block_change_direction(ball,1);
                return 1;}
            break;
        case 4:
            if(screen[ball->x_place][ball->y_place-1]==1){
                screen[ball->x_place][ball->y_place-1] = 0;
                block_change_direction(ball,1);
                return 1;}
            break;
        case 6:
            if(screen[ball->x_place][ball->y_place+1]==1){
                screen[ball->x_place][ball->y_place+1] = 0;
                block_change_direction(ball,1);
                return 1;}
            break;
        case 2:
            if(screen[ball->x_place-1][ball->y_place]==1){
                screen[ball->x_place-1][ball->y_place] = 0;
                block_change_direction(ball,1);
                return 1;}
            break;
        case 7:
            if(screen[ball->x_place+1][ball->y_place]==0 && screen[ball->x_place][ball->y_place-1]==1){
                screen[ball->x_place][ball->y_place-1]=0;
                block_change_direction(ball, 1);
                return 1;}
            else if(screen[ball->x_place+1][ball->y_place]==1&&screen[ball->x_place][ball->y_place-1]==0){
                screen[ball->x_place+1][ball->y_place]=0;
                block_change_direction(ball, 2);
                return 1;}
            else if(screen[ball->x_place+1][ball->y_place]==1 && screen[ball->x_place][ball->y_place-1]==1){
                screen[ball->x_place+1][ball->y_place] = screen[ball->x_place][ball->y_place-1] = 0;
                block_change_direction(ball, 3);
                return 1;}
            else if(screen[ball->x_place+1][ball->y_place]==0 && screen[ball->x_place][ball->y_place-1]==0 &&screen[ball->x_place+1][ball->y_place-1]==1){
                screen[ball->x_place+1][ball->y_place-1] = 0;
                block_change_direction(ball, 3);
                return 1;}
            break;
        case 9:
            if(screen[ball->x_place+1][ball->y_place]==1 && screen[ball->x_place][ball->y_place+1]==0){
                screen[ball->x_place+1][ball->y_place]=0;
                block_change_direction(ball, 1);
                return 1;}
            else if(screen[ball->x_place+1][ball->y_place]==0&&screen[ball->x_place][ball->y_place+1]==1){
                screen[ball->x_place][ball->y_place+1]=0;
                block_change_direction(ball, 2);
                return 1;}
            else if(screen[ball->x_place+1][ball->y_place]==1 && screen[ball->x_place][ball->y_place+1]==1){
                screen[ball->x_place+1][ball->y_place] = screen[ball->x_place][ball->y_place+1] = 0;
                block_change_direction(ball, 3);
                return 1;}
            else if(screen[ball->x_place+1][ball->y_place]==0 && screen[ball->x_place][ball->y_place+1]==0 &&screen[ball->x_place+1][ball->y_place+1]==1){
                screen[ball->x_place+1][ball->y_place+1] = 0;
                block_change_direction(ball, 3);
                return 1;}
            break;
        case 1:
            if(screen[ball->x_place-1][ball->y_place]==1 && screen[ball->x_place][ball->y_place-1]==0){
                screen[ball->x_place-1][ball->y_place]=0;
                block_change_direction(ball, 1);
                return 1;}
            else if(screen[ball->x_place-1][ball->y_place]==0&&screen[ball->x_place][ball->y_place-1]==1){
                screen[ball->x_place][ball->y_place-1]=0;
                block_change_direction(ball, 2);
                return 1;}
            else if(screen[ball->x_place-1][ball->y_place]==1 && screen[ball->x_place][ball->y_place-1]==1){
                screen[ball->x_place-1][ball->y_place] = screen[ball->x_place][ball->y_place-1] = 0;
                block_change_direction(ball, 3);
                return 1;}
            else if(screen[ball->x_place-1][ball->y_place]==0 && screen[ball->x_place][ball->y_place-1]==0 &&screen[ball->x_place-1][ball->y_place-1]==1){
                screen[ball->x_place-1][ball->y_place-1] = 0;
                block_change_direction(ball, 3);
                return 1;}
            break;
        case 3:
            if(screen[ball->x_place][ball->y_place+1]==1 && screen[ball->x_place-1][ball->y_place]==0){
                screen[ball->x_place][ball->y_place+1]=0;
                block_change_direction(ball, 1);
                return 1;}
            else if(screen[ball->x_place][ball->y_place+1]==0&&screen[ball->x_place-1][ball->y_place]==1){
                screen[ball->x_place-1][ball->y_place]=0;
                block_change_direction(ball, 2);
                return 1;}
            else if(screen[ball->x_place][ball->y_place+1]==1 && screen[ball->x_place-1][ball->y_place]==1){
                screen[ball->x_place][ball->y_place+1] = screen[ball->x_place-1][ball->y_place] = 0;
                block_change_direction(ball, 3);
                return 1;}
            else if(screen[ball->x_place][ball->y_place+1]==0 && screen[ball->x_place-1][ball->y_place]==0 &&screen[ball->x_place-1][ball->y_place+1]==1){
                screen[ball->x_place-1][ball->y_place+1] = 0;
                block_change_direction(ball, 3);
                return 1;}
            break;
    }
    return 0;
}

void board_collision(Ball *ball, Board *board)//小球与木板的碰撞计算
{
    switch(ball->direction)
    {
        case 1:
        if(screen[ball->x_place-1][ball->y_place]==1 &&screen[ball->x_place][ball->y_place-1]==1)
            ball->direction = 9;
        else if(screen[ball->x_place-1][ball->y_place]==0&&screen[ball->x_place][ball->y_place-1]==1)
            ball->direction = 3;
        else if(screen[ball->x_place-1][ball->y_place]==1)
        {
            if(board->direction==4)
                ball->direction = 7;
            if(board->direction==5)
                ball->direction = 7;
            if(board->direction==6)
                ball->direction = 8;
        }
            break;
        case 2:
        if(screen[ball->x_place-1][ball->y_place]==1)
        {
            if(board->direction==4)
                ball->direction = 7;
            if(board->direction==5)
                ball->direction = 8;
            if(board->direction==6)
                ball->direction = 9;
        }
            break;
        case 3:
        if(screen[ball->x_place-1][ball->y_place]==1 &&screen[ball->x_place+1][ball->y_place+1]==1)
            ball->direction = 7;
        else if(screen[ball->x_place-1][ball->y_place]==0 &&screen[ball->x_place][ball->y_place+1]==1)
            ball->direction = 1;
        else if(screen[ball->x_place-1][ball->y_place]==1)
        {
            if(board->direction==4)
                ball->direction = 8;
            if(board->direction==5)
                ball->direction = 9;
            if(board->direction==6)
                ball->direction = 9;
        }
            break;
    }
    return;
}