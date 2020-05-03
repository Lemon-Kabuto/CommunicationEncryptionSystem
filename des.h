#pragma once


void CharToBit(const char input[], int output[], int bits);//把CHAR转换为INT
void BitToChar(const int intput[], char output[], int bits);//把INT转换为CHAR
void Xor(int* INA, int* INB, int len);//异或操作  
void IP(const int input[64], int output[64], int table[64]);//初始IP置换 
void E(const int input[32], int output[48], int table[48]);//E扩展
void P(const int input[32], int output[32], int table[32]);//P置换 
void IP_In(const int input[64], int output[64], int table[64]);//逆IP 
void PC_1(const int input[64], int output[56], int table[56]);//PC_1 
void PC_2(const int input[56], int output[48], int table[48]);//PC_2
void S(const int input[48], int output[32], int table[8][4][16]);//S盒压缩
void F_func(int input[32], int output[32], int subkey[48]);//完成DES算法轮变换
void RotateL(const int input[28], int output[28], int leftCount);//秘钥循环左移
void  subKey_fun(const int input[64], int Subkey[16][48]);//子密钥生成 
void  DES_Efun(char input[8], char key_in[8], int output[64]);//DES加密
void  DES_Dfun(int input[64], char key_in[8], char output[8]);//DES解密