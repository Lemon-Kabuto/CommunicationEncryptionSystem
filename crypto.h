#pragma once

#include <iostream>

using namespace std;

class crypto {
private:
	long p;//DH����p
	long a;//p��ԭ��a
	long DH_Rand;//DH�����
	long Des_key;//des��Կ
	long RSA_D;//RSA˽Կ
public:
	long DH_Sa;//DH��ԿS
	long DH_Sb;//�Է�DH��Կ
	long RSA_P;//RSA������P
	long RSA_Q;//RSA������Q
	long long RSA_PHI;
	long long RSA_N;
	long long RSA_E;//RSA��Կ
	long long RSA_P_E;//�Է�RSA��Կ

	crypto();
	~crypto();
	void Generate_Rand();//����DH�����
	void Generate_S();//����DH��Կ
	void Exchange_S(long DH_sb);//������Կ
	void Generate_Des_Key();//����DES��Կ

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