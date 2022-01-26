//��Ϸ�߼�
#include "game.h"
#include "data.h"
#include "mywindows.h"
#include <conio.h>

#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")

int k = 0;
int grade = 0;  //����
int level = 1;    //�ȼ�
float speed = 0.45;
int l1=0,k;
BLOCK cur_block;   ///��ǰ����
BLOCK next_block;  ///��һ������

void windowPrint1(int x,int y){
    //������Ϸ�ر߿�
    int i,j;  //����������ά����
    for(i=0;i<25;i++){
        for(j=0;j<26;j++){
            if(windowShape[i][j] == 1){
                setColor(0xc0);
                setPos(x+j,y+i);  //x���У�y����
                printf("%2s","");  // <-->  printf("  ");
            }
        }
    }

}

//����������
void printInfo1(){
    setColor(0x01);
    setPos(31,9);
    printf("��������");
    setPos(31,10);
    printf("�� a �� A ����");
    setPos(31,11);
    printf("�� d �� D ����");
    setPos(31,12);
    printf("�� s �� S ����");
    setPos(31,13);
    printf("�� w �� W �䷽��");
    setPos(31,14);
    printf("�� �س� ֱ������");
    setPos(31,15);
    printf("�� �ո� ��ͣ");
    setPos(31,16);
    printf("�� q ����");
    setPos(31,17);
    printf("�� e ����");
    setPos(31,18);
    printf("�� z ����");
    setPos(31,19);
    printf("�� x �����Ų�ģʽ");
}


void printGradeLevel(int num){
    switch(num){
        case 1:
            grade+=10; break;
        case 2:
            grade+=30; break;
        case 3:
            grade+=50; break;
        case 4:
            grade+=80; break;
    }

    if(grade < 100){
        level = 1;
    }
    else if(grade >= 100 && grade < 300){
        level =2;
    }

    setColor(0x09);
    setPos(3,6);
    printf("����:%d",grade);

    setPos(3,7);
    printf("�ȼ�:%d",level);
}

void gameTime(clock_t start_time){
    setColor(0x0b);
    setPos(3,3);
    printf("������Ϸ������ %d s",(clock()-start_time)/CLOCKS_PER_SEC);
}

void printBlock(int x,int y,int shape,int status,int color){
    int i,j;
    for(i = 0;i<4;i++){
        for(j = 0;j<4;j++){
            if(block[shape][status][i][j] == 1){
                setColor(color);
                setPos(x+j,y+i);
                printf("��");
            }
        }
    }
}

/**�ṹ�壺��һ�ּ��ϣ����԰������������ֵ���飨��Ա��
    ģ�壺
        struct �ṹ����{
            �ṹ������ı�����������;
        }; -->�ֺŲ�����
1.�ȶ���ṹ�����ͣ��ڶ���ṹ�����
    struct stu{
        char *name;
        int age;
        float score;
    };
    struct stu stu1,stu2; //stu1,stu2�ǽṹ�����
2.����ṹ�����͵�ͬʱ����ṹ�����
    struct stu{
        char *name;
        int age;
        float score;
    }stu1,stu2;
    struct stu stu3,stu4;
3.ֱ�Ӷ���ṹ�����
    struct{
        char *name;
        int age;
        float score;
    }stu1,stu2;
    û�нṹ�����ƣ������޷�����ṹ�������

    typedef struct stu{
        char *name;
        int age;
        float score;
    }STU;
    STU stu1,stu2;
**/

void deleteBlock(int x,int y,int shape,int status){
    int i,j;
    for(i = 0;i<4;i++){
        for(j = 0;j<4;j++){
            if(block[shape][status][i][j] == 1){
                setPos(x+j,y+i);
                printf("  ");
            }
        }
    }
}

void startBlock(){
    ///��һ�����飺��״/��̬/��ɫ->��� λ��(x,y)�̶���
    ///��ʼ��cur_block
    ///������������ӣ�ʱ����Զ��һ����
    srand((unsigned)time(NULL));
    cur_block.x = 22;
    cur_block.y = 1;
    cur_block.shape = rand()%7;
    cur_block.status = rand()%4;
    cur_block.color = rand()%0x10;
    ///��������������ɫ�Ǻ�ɫ������ɫ���óɰ�ɫ
    if(cur_block.color == 0x00){
        cur_block.color = 0x0f;
    }
    printBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status,cur_block.color);

}

void nextBlock(){
    ///��״/��̬/��ɫ->��� λ��(x,y)�̶�
    ///��ʼ��next_blockֵ
    deleteBlock(next_block.x,next_block.y,next_block.shape,next_block.status);
    next_block.x = 35;
    next_block.y = 2;
    next_block.shape = rand()%7;
    next_block.status = rand()%4;
    next_block.color = rand()%0x10;
    ///��������������ɫ�Ǻ�ɫ������ɫ���óɰ�ɫ
    if(next_block.color == 0x00){
        next_block.color = 0x0f;
    }
    printBlock(next_block.x,next_block.y,next_block.shape,next_block.status,next_block.color);
}

void copyBlock(){
    ///��ǰ���� = ��һ�����飬�������µġ���һ�����顱
    cur_block = next_block;
    cur_block.x = 22;
    cur_block.y = 1;
    printBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status,cur_block.color);
    nextBlock();
}

int downBlock(){
    //ԭ��ɾ��������ʾ��ͼ�㣬�������һ�����´�ӡ

    if(l1%2!=0){
            coolColor();
           }
    if(crash(cur_block.x,cur_block.y+1,cur_block.shape,cur_block.status) == -1){
     ///������ײ�������䵽��Ϸ�صײ�
            ///�����µķ��飺��һ������ֵ -> ��ǰ��������ķ��飬���²�����һ������
            ///���淽��->�������->��ӡ��Ϸ��->�����·���
            save();
//            lineClear();
            removeLine();
            updateGame();

            copyBlock();
            return -1;
    }

    else if(crash(cur_block.x,cur_block.y+1,cur_block.shape,cur_block.status) == -2){

///��Ϸ����
            return -2;
    }

    else{
         deleteBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status);
    cur_block.y += 1;
    printBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status,cur_block.color);
    return 1;
    }
}

void leftBlock(){
    //ԭ��ɾ��������ʾ��ͼ�㣬�������һ�����´�ӡ
    ///������ײ������������߿��޷����������ƶ��������ƶ�
    if(crash(cur_block.x-1,cur_block.y,cur_block.shape,cur_block.status) != -1){
    deleteBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status);
    cur_block.x -= 1;
    printBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status,cur_block.color);
    }

}

void rightBlock(){
    //ԭ��ɾ��������ʾ��ͼ�㣬�������һ�����´�ӡ
    if(crash(cur_block.x+1,cur_block.y,cur_block.shape,cur_block.status) != -1){
    deleteBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status);
    cur_block.x += 1;
    printBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status,cur_block.color);
    }

}

void changeStatusBlock(){
     if(crash(cur_block.x,cur_block.y,cur_block.shape,(cur_block.status+1)%4) != -1){
    deleteBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status);
    if(cur_block.status==3)cur_block.status = 0;
    else cur_block.status++;
    printBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status,cur_block.color);
     }
    //cur_block.status = (cur_block.status+1)%4;
}

void changeShapeBlock(){
    if(crash(cur_block.x,cur_block.y,(cur_block.shape+1)%7,cur_block.status) != -1){
    deleteBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status);
    if(cur_block.shape==6)cur_block.shape = 0;
    else cur_block.shape++;
    printBlock(cur_block.x,cur_block.y,cur_block.shape,cur_block.status,cur_block.color);
    }
}

void coolColor(){
    int i;

           cur_block.color = rand()%0x10;
    ///��������������ɫ�Ǻ�ɫ������ɫ���óɰ�ɫ
    if(cur_block.color == 0x00){
        cur_block.color = 0x0f;
    }
    }

    //��ײ��������һ��λ�õļ��,�������������Ķ�Ӧ
int crash(int x,int y,int shape,int status){
    int i,j;
    for(i = 0;i<4;i++){
        for(j = 0;j<4;j++){
            if(block[shape][status][i][j] == 1){
                if(windowShape[y+i][x+j-15] == 1){
                      ///������ײ
                      if(cur_block.x == 22 && cur_block.y == 1){
                        ///��Ϸ����
                        return -2;
                      }
                      ///�����䵽��Ϸ�صײ���������ײ


                    return -1;
                }

            }
        }

    }
    return 0;
}

void save(){
    ///���ݷ����ڽ����ϵ����꣬�������Ӧ����Ϸ���±�Ķ�Ӧλ��
    ///����Ϊ1�ı��浽windowShape����
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(block[cur_block.shape][cur_block.status][i][j] == 1){
                windowShape[i+cur_block.y][j+cur_block.x-15] = 1;
            }

        }
    }
}

void updateGame(){
    int i,j;
    for(i=23;i>0;i--){
        for(j=1;j<15;j++){
                if(windowShape[i][j] == 1){
            setColor(0x0e);
            setPos(15+j,i);
            printf("��");
                }else{
                setColor(0x00);
                setPos(15+j,i);
                printf("  ");
                }
        }
    }
}

void removeLine(){
    int i,j,m,n;
    int number = 0;
    for(i=23;i>1;i--){
            int total = 0;
        for(j=1;j<15;j++){
            if(windowShape[i][j] == 1){
              total++;
            }
            if(total == 14){
                    number++;
                for(m = i;m>1;m--){   ///m>1,��֤�߽粻������
        for(n=1;n<15;n++){
            windowShape[m][n] = windowShape[m-1][n];
        }
    }
        i++;
        ///ͳ��һ�����˼���

                }

            }

        }
        printGradeLevel(number);
    }



//void lineClear(){
//    ///����windowShape,�ж��Ƿ������У���������ֵ������Ϊ14
//    int i,j;
//    for(i=23;i>0;i--){
//          int total = 0;
//        for(j=1;j<15;j++){
//            total += windowShape[i][j];
//        }
//        if(total == 14){
//            lineDown(i);
//            i += 1; //��֤�ܶ������н��м��
//        }
//    }
//
//}
//
//void lineDown(int line){
//    ///�ӵ�line�п�ʼ��i= i-1
//    int i,j;
//    for(i = line;i>1;i--){   ///i>1,��֤�߽粻������
//        for(j=1;j<15;j++){
//            windowShape[i][j] = windowShape[i-1][j];
//        }
//    }
//}

void pause(){
    clock_t time1;
    time1 = clock();
    ///��ͣ������ȥִ����һ������
    while(1){
        if(getch() == 32){
            break;
        }
    }
    k +=  (clock()-time1)/CLOCKS_PER_SEC;
}

void bottomBlock(){
    while(crash(cur_block.x,cur_block.y+1,cur_block.shape,cur_block.status) != -1&&crash(cur_block.x,cur_block.y+1,cur_block.shape,cur_block.status) != -2){

    cur_block.y += 1;


    }

        if(crash(cur_block.x,cur_block.y+1,cur_block.shape,cur_block.status) == -1){
            ///������ײ�������䵽��Ϸ�صײ�
            ///�����µķ��飺��һ������ֵ -> ��ǰ��������ķ��飬���²�����һ������
            save();
            removeLine();
//            lineClear();
            updateGame();
            copyBlock();

    }
    else if(crash(cur_block.x,cur_block.y+1,cur_block.shape,cur_block.status) == -2){
        ///��Ϸ����
        printOver();
    }
}

void printOver1(){
    int i,j;
    for(i=23;i>0;i--){
        for(j=1;j<15;j++){
            setColor(0x76);
            setPos(j+15,i);
            printf("��");
            Sleep(5);
        }
    }

}

void printFinish1(){
    setColor(0x10);
    setPos(21,10);
    printf("��Ϸ������ ");
    setPos(18,11);
    printf("��Y���¿�ʼ ");
    setPos(24,11);
    printf("��N������Ϸ");

    ///����û�����
    switch(getch()){
    {
        case 'y':
        case 'Y':
            againGame();break;
        case 'n':
        case 'N':
            mciSendString(TEXT("stop a"),NULL,0,NULL);break;
        default:
            printFinish();break;
    }
    }
}

void againGame1(){
    ///���÷���/�ȼ�/��Ϸ������->��ʼ��Ϸ
    level = 1;
    grade =0;
    int i,j;
    for(i=1;i<24;i++){
        for(j=1;j<15;j++){
            windowShape[i][j] = 0;
        }
    }
    setColor(0x00);
    system("cls");  ///����
    gameInit();
}

void printStart(int x,int y){
     //���������ɫ
    int color = rand()%0x10;
    //�����ɫ�����
    if(color == 0x00)
    {
        color = 0x0f;
    }

    setColor(color);
    setPos(x,y);
    printf("����������  ����������  ����������  ��������  ������  ��������");
    setPos(x,y+1);
    printf("    ��      ��              ��      ��    ��    ��    ��");
    setPos(x,y+2);
    printf("    ��      ��������        ��      ������      ��      ������");
    setPos(x,y+3);
    printf("    ��      ��              ��      ��  ��      ��          ��");
    setPos(x,y+4);
    printf("    ��      ����������      ��      ��    ��  ������  ������");

    setPos(25,14);
    printf("���������ʼ��Ϸ!");
    }

void deleteStart(int x,int y){
    int i,j;
    for(i = y;i<=y+4;i++){
        for(j = x;j<=x+33;j++){
            setPos(j,i);
            printf("%2s","");
        }
    }

}

void printAnimation(){
    clock_t time1,time2;
    time1 = clock();
    int x = 5;
    printStart(x,5);
    while(1){
        time2 = clock();
    if(time2 - time1 > 150) {  ///ʱ����300����
        time1 = time2;
        deleteStart(x,5);
        printStart(++x,5);
        if(25 == x){
            deleteStart(x,5);
            x=5;
        }
    }
    ///��������˳�
    if(kbhit()){
        break;
    }
    }
    system("cls");
}

void gameInit(){
    ///��ʼ���������������ʼ
    initHandle();
    ///�������ļ�
    mciSendString("open E:\\20200705\\bin\\Debug\\res\\����˹������Ϸ�� ������.mp3 alias a",NULL,0,NULL);//alias a:Ϊ���·����һ������ a
    ///��������
    mciSendString(TEXT("play a"),NULL,0,NULL);
    ///��ʼ����
    printAnimation();
    windowPrint1(15,0);
    printInfo();
    printGradeLevel(0);

    ///��Ϸ��ʼʱ��
    clock_t startTime = clock();
    gameTime(startTime);


    ///��ʱ��
    clock_t time1,time2;
    time1 = clock();


    //��ӡ����߿�
    setPos(1,24);
    setColor(0x80);
    printf("                            ");
    setColor(0x40);
    setPos(1,0);
    printf("                            ");
    int i;

    startBlock();
    nextBlock();
    setColor(0x30);
    for(i=0;i<25;i++){
        setPos(1,i);
        printf("  ");
    }
    setPos(40,25);


    while(1){
        //��������
        ///����Ƿ��а�������
        if(kbhit()){
            switch(getch()){
            case 'w':
            case 'W':
            case 72:
               changeStatusBlock();break;
            case 'a':
            case 'A':
            case 75:
                leftBlock();break;
            case 'd':
            case 'D':
            case 77:
                rightBlock();break;
            case 's':
            case 'S':
            case 80:
                downBlock();break;
            case 'q':
            case 'Q':
                speed-=0.01;break;
            case 'e':
            case 'E':
                speed+=0.01;break;
            case 'z':
            case 'Z':
                changeShapeBlock();break;
            case 'x':
            case 'X':
                l1++;break;
            case 32:
                pause();break;
            case 13:
                bottomBlock();break;
            }
        }

        time2 = clock();

        ///ÿ0.45������һ��
        if((time2-time1)/CLOCKS_PER_SEC > speed){
            gameTime(startTime + k*CLOCKS_PER_SEC);
            if(downBlock() == -2) break;

            time1 = time2;


    }

}
printOver();
printFinish();
}
