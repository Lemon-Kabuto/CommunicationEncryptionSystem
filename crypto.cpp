#include "crypto.h"
#include "rsa.h"
#include <time.h>

crypto::crypto()
{
	p = 19;
	a = 3;
	Generate_Rand();
	Des_key = 0;
	Generate_S();
	DH_Sb = 0;
	/*
	size_t rsa_p = Pseudoprime(0);
	while (!rabinmiller(rsa_p, 10)) {
		rsa_p = Pseudoprime(0);
	}

	srand((unsigned)time(0));
	int a = (rand() % 10000);//随机生成0-10000

	size_t rsa_q = Pseudoprime(a);
	while (!rabinmiller(rsa_q, 10)) {
		rsa_q = Pseudoprime(a);
	}

	RSA_P = rsa_p;
	RSA_Q = rsa_q;

	RSA_N = RSA_P * RSA_Q;

	RSA_PHI = (RSA_P - 1) * (RSA_Q - 1);

	RSA_E = Rsa_E(RSA_PHI);
	RSA_D = Rsa_D(RSA_PHI, RSA_E);
	*/
}

crypto::~crypto()
{
	p = 0;
	a = 0;
	DH_Rand = 0;
	Des_key = 0;
	DH_Sa = 0;
	DH_Sb = 0;
}

void crypto::Generate_Rand()//随机数
{
	srand((unsigned)time(NULL));
	this->DH_Rand = 1 + rand() % (p - 1);//1<=DH_Rand<=p-2
}

void crypto::Generate_S()//自身公钥
{
	double temp = a * 1.0;
	this->DH_Sa = pow(temp, DH_Rand);
	this->DH_Sa = DH_Sa % p;
}

void crypto::Exchange_S(long DH_Sb)
{
	this->DH_Sb = DH_Sb;
}

void crypto::Generate_Des_Key()
{
	double temp = this->DH_Sb * 1.0;
	this->Des_key = pow(temp, this->DH_Rand);
	this->Des_key = this->Des_key % p;
}

void crypto::SetDes_key(long key)
{
	this->Des_key = key;
}

void crypto::SetRSA_E()
{
	this->RSA_E = Rsa_E(this->RSA_PHI);
}

void crypto::SetRSA_D()
{
	this->RSA_D = Rsa_D(this->RSA_PHI,this->RSA_E);
}

void crypto::SetRSA_P_E(long key)
{
	this->RSA_P_E = key;
}

void crypto::SetRSA_P()
{
	srand((unsigned)time(0));
	int a = (rand() % 10000);
	this->RSA_P = Pseudoprime(0);
}

void crypto::SetRSA_Q()
{
	srand((unsigned)time(0));
	int a = (rand() % 10000);
	while (!rabinmiller(p, 10)) {
		p = Pseudoprime(0);
	}
}

void crypto::SetRSA_PHI(long P, long Q)
{
	this->RSA_PHI = (P - 1) * (Q - 1);
}


long crypto::ReturnDes_key()
{
	return this->Des_key;
}

long crypto::ReturnRSA_P()
{
	return this->RSA_P;
}

long crypto::ReturnRSA_Q()
{
	return this->RSA_Q;
}

long long crypto::ReturnRSA_PHI()
{
	return this->RSA_PHI;
}

long long crypto::ReturnRSA_E()
{
	return this->RSA_E;
}

long long crypto::ReturnRSA_P_E()
{
	return this->RSA_P_E;
}

long long crypto::ReturnRSA_D()
{
	return this->RSA_D;
}

