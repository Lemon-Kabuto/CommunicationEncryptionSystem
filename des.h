#pragma once


void CharToBit(const char input[], int output[], int bits);//��CHARת��ΪINT
void BitToChar(const int intput[], char output[], int bits);//��INTת��ΪCHAR
void Xor(int* INA, int* INB, int len);//������  
void IP(const int input[64], int output[64], int table[64]);//��ʼIP�û� 
void E(const int input[32], int output[48], int table[48]);//E��չ
void P(const int input[32], int output[32], int table[32]);//P�û� 
void IP_In(const int input[64], int output[64], int table[64]);//��IP 
void PC_1(const int input[64], int output[56], int table[56]);//PC_1 
void PC_2(const int input[56], int output[48], int table[48]);//PC_2
void S(const int input[48], int output[32], int table[8][4][16]);//S��ѹ��
void F_func(int input[32], int output[32], int subkey[48]);//���DES�㷨�ֱ任
void RotateL(const int input[28], int output[28], int leftCount);//��Կѭ������
void  subKey_fun(const int input[64], int Subkey[16][48]);//����Կ���� 
void  DES_Efun(char input[8], char key_in[8], int output[64]);//DES����
void  DES_Dfun(int input[64], char key_in[8], char output[8]);//DES����