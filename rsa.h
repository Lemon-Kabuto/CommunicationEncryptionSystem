#pragma once

size_t Pseudoprime(int n);//��������
size_t  repeatMod(size_t base, size_t n, size_t mod);//ģ�ظ�ƽ���㷨��(b^n)%m
bool rabinmiller(size_t n, size_t k);// Miller - Rabin�������
int gcd(int a, int b);//���Լ���㷨
long long Rsa_E(long long phi);//α������ɹ�Կe
long long Rsa_D(long long phi, long long e);//��˽Կd
long long Mod(long long a, long long  b, long long m);//��a��b����ȡģ m������ȡģ��
void rsaEncode(char* ch, long long* str, int e, int N);////��������Ϣ����rsa����
void rsaDecode(long long* ch, char* str, int d, int N);////����rsa����õ�ԭ������Ϣ
char* _10_to_16(long long a);//ʮ����תʮ����