#include "mywindows.h"  //�����ų���������ϵͳͷ�ļ���˫���ų����������Լ������ͷ�ļ�   Ĭ�ϼ���˳��ͬ

HANDLE handle;

//��������

void initHandle(){
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    hideCursor();//��Ϸ���������ع��λ��
    //
}

void setColor(int color){
    SetConsoleTextAttribute(handle,color);
}

void setPos(int x,int y){
    COORD coord = {x*2,y};    //��ĸabcd:һ���ַ������֣������ַ�
    SetConsoleCursorPosition(handle,coord); //���þ��λ��
}

void hideCursor(){
    CONSOLE_CURSOR_INFO info;        //ϵͳ�Ľṹ��������ֶ��Ǵ�д
    info.bVisible = FALSE;           //���ù���Ƿ�ɼ�
    info.dwSize = 1;                 //���ù����(1-100)
    SetConsoleCursorInfo(handle,&info);//ָ��ȡ��ַ��
}
