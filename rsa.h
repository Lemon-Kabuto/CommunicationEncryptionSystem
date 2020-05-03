#pragma once

size_t Pseudoprime(int n);//生成素数
size_t  repeatMod(size_t base, size_t n, size_t mod);//模重复平方算法求(b^n)%m
bool rabinmiller(size_t n, size_t k);// Miller - Rabin素数检测
int gcd(int a, int b);//最大公约数算法
long long Rsa_E(long long phi);//伪随机生成公钥e
long long Rsa_D(long long phi, long long e);//求私钥d
long long Mod(long long a, long long  b, long long m);//对a的b次幂取模 m（大数取模）
void rsaEncode(char* ch, long long* str, int e, int N);////对输入信息进行rsa编码
void rsaDecode(long long* ch, char* str, int d, int N);////根据rsa编码得到原来的信息
char* _10_to_16(long long a);//十进制转十六制