#include "rsa.h"


#include <stdlib.h>
#include <time.h>


#define MAX_ROW 1997

size_t Pseudoprime(int n)
{
	bool ifprime = false;
	size_t a = 0;
	int arr[MAX_ROW];   //数组arr为{3，4, 5，6...2000}
	for (int i = 0; i < MAX_ROW; ++i)
	{
		arr[i] = i + 3;
	}
	while (!ifprime)
	{
		srand((unsigned)time(0) + n);
		ifprime = true;
		a = (rand() % 10000) * 2 + 3; //生成一个范围在3到20003里的奇数
		for (int j = 0; j < MAX_ROW; ++j)
		{
			if (a % arr[j] == 0)
			{
				ifprime = false;
				break;
			}
		}
	}
	return a;
}

size_t repeatMod(size_t base, size_t n, size_t mod)
{
	size_t a = 1;
	while (n)
	{
		if (n & 1)
		{
			a = (a * base) % mod;
		}
		base = (base * base) % mod;
		n = n >> 1;
	}
	return a;
}

bool rabinmiller(size_t n, size_t k)
{
	int s = 0;
	int temp = n - 1;
	while ((temp & 0x1) == 0 && temp)
	{
		temp = temp >> 1;
		s++;
	}   //将n-1表示为(2^s)*t
	size_t t = temp;

	while (k--)  //判断k轮误判概率不大于(1/4)^k
	{
		srand((unsigned)time(0));
		size_t b = rand() % (n - 2) + 2; //生成一个b(2≤a ≤n-2)

		size_t y = repeatMod(b, t, n);
		if (y == 1 || y == (n - 1))
			return true;
		for (int j = 1; j <= (s - 1) && y != (n - 1); ++j)
		{
			y = repeatMod(y, 2, n);
			if (y == 1)
				return false;
		}
		if (y != (n - 1))
			return false;
	}
	return true;
}

int gcd(int a, int b)
{
	int temp;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long long Rsa_E(long long phi)
{

	bool flag = true;
	/*while (flag) {
		if ((gcd(e, phi) == 1 )&& (e < phi) && (1 < e) ) {
			flag = false;
		}
		else {
			e = rand() % phi;
		}
	}*/
	while (flag) {
		long long e = rand() % phi;
		for (long long i = e; i < phi; i++) {
			if ((gcd(e, phi) == 1) && (e < phi) && (1 < e) ) {
				return e;
				flag = false;
			}
		}
	}
}

long long Rsa_D(long long phi, long long e)
{
	for (long long i = 1; i < phi; i++) {
		if ((e * i % phi) == 1) {
			return i;
			break;
		}
	}
}

long long Mod(long long a, long long b, long long m)
{
	long long r = 1;
	for (long long j = 0; j < b; j++) {
		r = (r * a) % m;
	}
	return r;
}

void rsaEncode(char* ch, long long* str, int e, int N)
{
	long long ascii = { 0x00 }; //存储信息的每个字符

	for (int i = 0; i < 64; i++) {
		ascii = ch[i];
		str[i] = Mod(ascii, e, N);
	}
}

void rsaDecode(long long* ch, char* str, int d, int N)
{
	long long ascii = { 0x00 }; //存储信息的每个字符

	for (int i = 0; i < 64; i++) {
		ascii = Mod(ch[i], d, N);
		str[i] = ascii;
	}
}

char* _10_to_16(long long a)
{
	char* str = new char[10];
	int i = 0;
	long long temp = 0;
	while (a > 0) {
		temp = a % 16;// 取余数 
		str[i++] = temp >= 10 ? ((temp - 10) + 'a') : (temp + '0');
		a = a >> 4;
	}
	str[i] = '\0';
	// 翻转 , 将高位与低位进行翻转 
	int t = 0;
	for (int j = 0; j < i / 2; j++) {
		t = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = t;
	}
	return str;
}
