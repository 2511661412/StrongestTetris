#ifndef MYWINDOWS_H_INCLUDED
#define MYWINDOWS_H_INCLUDED
//�����ض�����󣬶���ļ�ͬʱ����ͷ�ļ������������ʱ�����׷����ض�������
//ͷ�ļ����з�װ�������ļ����Կ��ٵ��ã����ٴ�����д


/*ϵͳ����ģ��*/
#include <windows.h>

//ͷ�ļ���������
//��ʼ�����
void initHandle();//С�շ����������ں����ͱ������������շ峣�����������

//������ɫ
void setColor(int color);

//���ù��λ��
void setPos(int x,int y);

//���ع��
void hideCursor();

//��ʾundefine reference -> ͷ�ļ���Դ�ļ����Ʋ���Ӧ

#endif // MYWINDOWS_H_INCLUDED
