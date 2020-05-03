#pragma once

#include <iostream>

using namespace std;

class crypto {
private:
	long p;//DH素数p
	long a;//p的原根a
	long DH_Rand;//DH随机数
	long Des_key;//des密钥
	long RSA_D;//RSA私钥
public:
	long DH_Sa;//DH公钥S
	long DH_Sb;//对方DH公钥
	long RSA_P;//RSA大素数P
	long RSA_Q;//RSA大素数Q
	long long RSA_PHI;
	long long RSA_N;
	long long RSA_E;//RSA公钥
	long long RSA_P_E;//对方RSA公钥

	crypto();
	~crypto();
	void Generate_Rand();//生成DH随机数
	void Generate_S();//生成DH公钥
	void Exchange_S(long DH_sb);//交换公钥
	void Generate_Des_Key();//生成DES密钥

	void SetDes_key(long key);
	void SetRSA_E();
	void SetRSA_D();
	void SetRSA_P_E(long key);
	void SetRSA_P();
	void SetRSA_Q();
	void SetRSA_PHI(long P,long Q);

	long ReturnDes_key();
	long ReturnRSA_P();
	long ReturnRSA_Q();
	long long ReturnRSA_PHI();
	long long ReturnRSA_E();
	long long ReturnRSA_P_E();
	long long ReturnRSA_D();
};