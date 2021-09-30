#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std;
#define screen_length 20
class Point
{
    int x, y;
public:
    Point(){}
    Point(int x,int y):x(x),y(y){}
    int getx() { return x; }
    int gety() { return y; }
    void setx(int x0) { x = x0; }
    void sety(int y0) { y = y0; }
};

class Snack
{
    int length;
    char direction;
    Point HeadPoint, **body, HailPoint;
public:
    Snack(int x, int y) : length(1), direction(0), HeadPoint(x, y), HailPoint(x, y) { 
        body = new Point *[screen_length * screen_length];
        body[length] = new Point(x, y);
    }
    Point& GetBody(int num) { return body[num][0]; }
    int GetLength() { return length; }
    char GetDirection() { return direction; }
    void SetDirection(char direction0) { direction = direction0; }
    void move(){
        if(direction=='w')
            HeadPoint.sety(HeadPoint.gety() + 1);
        else if(direction=='s')
            HeadPoint.sety(HeadPoint.gety() - 1);
        else if(direction=='a')
            HeadPoint.setx(HeadPoint.getx() - 1);
        else if(direction=='d')
            HeadPoint.setx(HeadPoint.getx() + 1);
        HailPoint = body[length][0];
        for (int i = length; i >= 2;i--)
            body[i][0] = body[i - 1][0];
        body[1][0] = HeadPoint;
    }
    void EatFood(){
        length++;
        body[length] = new Point(0, 0);
        body[length][0] = HailPoint;
    }
};

class Screen:public Snack
{
    char screen[screen_length][screen_length] = {0};
    Point food;
public:
    Screen():Snack(screen_length/2,screen_length/2),food(-1,-1){
        for (int i = 0; i < screen_length;i++){
            screen[i][0] = '+';
            screen[i][screen_length - 1] = '+';
        }
        for (int j = 1; j < screen_length - 1;j++){
            screen[0][j] = '+';
            screen[screen_length - 1][j] = '+';
        }
    }
    int IsDie(){
        if(GetBody(1).getx()==0||GetBody(1).getx()==screen_length-1)
            return 1;
        if(GetBody(1).gety()==0||GetBody(1).gety()==screen_length-1)
            return 1;
        for (int i = 2; i <= GetLength();i++)
            if(GetBody(1).getx()==GetBody(i).getx()&&GetBody(1).gety()==GetBody(i).gety())
                return 1;
        return 0;
    }
    int JudgeFood(Point &point){
        if(point.getx()==food.getx()&&point.gety()==food.gety())
            return 1;
        else return 0;
    }
    void DeleteFood(){
        food.setx(-1);
        food.sety(-1);
    }
    int IsExistFood(){
        if(food.getx()==-1&&food.gety()==-1)
            return 0;
        else return 1;
    }
    void CreatFood(){
        srand((unsigned int)time(0));
        int foodx, foody;
        while(1){
            foodx = rand() % (screen_length - 2) + 1;
            foody = rand() % (screen_length - 2) + 1;
            int flag = 1;
            for (int i = 1; i <= GetLength();i++)
                if(foodx==GetBody(i).getx()&&foody==GetBody(i).gety())
                    flag = 0;
            if(flag)
                break;
        }
        food.setx(foodx);
        food.sety(foody);
    }
    void print(){
        screen[food.gety()][food.getx()] = '$';
        for(int i = 1; i <= GetLength();i++)
            screen[GetBody(i).gety()][GetBody(i).getx()] = '*';
        char screen0[screen_length * (screen_length + 1) + 1];
        int p = 0;
        for (int i = screen_length - 1; i >= 0;i--){
            for (int j = 0; j < screen_length;j++){
                if(screen[i][j]==0)
                    screen0[p] = ' ';
                else
                    screen0[p] = screen[i][j];
                p++;
            }
            screen0[p] = '\n';
            p++;
        }
        screen0[p] = 0;
        screen[food.gety()][food.getx()] = 0;
        for(int i = 1; i <= GetLength();i++)
            screen[GetBody(i).gety()][GetBody(i).getx()] = 0;
        puts(screen0);
    }
};

int main()
{
    while(1){
        cout << "按任意键开始" << endl;
        system("pause");
        Screen screen;
        screen.CreatFood();
        int DeadFlag = 0;
        char direction;
        while(1){
            do{
                screen.move();
                if(screen.JudgeFood(screen.GetBody(1))){
                    screen.EatFood();
                    screen.DeleteFood();
                }
                if(!screen.IsExistFood())
                    screen.CreatFood();
                screen.print();
                if(screen.IsDie()){
                    DeadFlag = 1;
                    break;
                }
                Sleep(150);
                system("cls");
            }while(!kbhit());
            if(DeadFlag)
                break;
            direction = getch();
            if(direction!='w'&&direction!='s'&&
            direction!='a'&&direction!='d')
                continue;
            if(screen.GetDirection()=='w')
                if(direction=='s')
                    continue;
            if(screen.GetDirection()=='s')
                if(direction=='w')
                    continue;
            if(screen.GetDirection()=='a')
                if(direction=='d')
                    continue;
            if(screen.GetDirection()=='d')
                if(direction=='a')
                    continue;
            screen.SetDirection(direction);
        }
        cout << "YOU DIE" << endl;
    }
}