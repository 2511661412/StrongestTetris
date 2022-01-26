#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <time.h>

/*��Ϸ�߼�ģ��*/

#include <stdio.h>

///����ṹ��
typedef struct{
    int x;
    int y;
    int shape;
    int status;
    int color;
}BLOCK;

//������Ϸ�ر߿�
void windowPrint(int x,int y);

//��Ϸ���г�ʼ��
void gameInit();

//��ӡ����˵��
void printInfo();
void printInfoStandard();
//��ӡ�����ȼ�
void printGradelevel(int num);

//��Ϸ��ʱ
void gameTime(clock_t start_time);

//��ӡ����
void printBlock(int x,int y,int shape,int status,int color);

//ɾ������
void deleteBlock(int x,int y,int shape,int status);

//������Ϸ�ĵ�һ������
void startBlock();

//������Ϸ����һ������
void nextBlock();

//��������
void copyBlock();

///��������
///����ֵ����ʶ�����Ƿ���Ϸ�صײ�
int downBlock();

///��������
///�޷���ֵ
void leftBlock();


///��������
///�޷���ֵ
void rightBlock();

///���鷽��ı�
void changeStatusBlock();

///������״�ı�
void changeShapeBlock();

///�����Ų�Ч��
void coolColor();

///��ײ��⺯��
int crash(int x,int y,int shape,int status);

///���淽��
void save();

///ˢ����Ϸ��
void updateGame();

///����
void removeLine();

///��ͣ
void pause();

///����ֱ�����
void bottomBlock();

///���ļ�ʱ��
void setClock();

///���м��
void lineClear();

///��������
void lineDown(int line);

///��Ϸ��������
void printOver1();

///���¿�ʼ��ʾ
void printFinish1();

///���¿�ʼ��Ϸ
void againGame1();

///��ӡ��ʼͼ��
void printStart(int x,int y);

///�����ʼͼ��
void clearStart(int x,int y);

///����Ч�� ->��ʱ(�߽����)
void printAnimation();

//�������ļ�
void openMusic();

//�ر������ļ�
void closeMusic();

#endif // GAME_H_INCLUDED
