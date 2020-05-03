#include "crypto.h"
#include "rsa.h"
#include "SHA256.h"
#include "des.h"


#include <time.h>

int main() {
	crypto A, B;
	long Des_Key = 0;

	A.Exchange_S(B.DH_Sa);
	B.Exchange_S(A.DH_Sa);

	A.Generate_Des_Key();//生成DES私钥
	B.Generate_Des_Key();//生成DES私钥

	FILE* fp1, *fp2;
	errno_t err;

	char PLAINTEXT[8] = { 0 };
	char PLAINTEXT_D[8] = { 0 };
	char SCERCTKEY[8] = { 0 };
	int CRYPTOTEXT[64] = { 0 };

	char file_sha256[65];
	long long str1_sha256[65];
	char str2_sha256[65];

	Des_Key = A.ReturnDes_key();

	sprintf_s(SCERCTKEY, 8, "%ld", Des_Key);

	int output[64] = { 0 };

	if (err = fopen_s(&fp1, "plaintext.txt", "r") ) {
		printf("文件打开失败\n");
		return 0;
	}

	if (err = fopen_s(&fp2, "cryptotext.txt", "w+")) {
		printf("文件打开失败\n");
		return 0;
	}

	long long e = 0, d = 0, p = 0, q = 0;

	srand((unsigned)time(0));
	int a = (rand() % 10000);//随机生成0-10000

	p = 17;
	q = 19;
	e = 5;
	d = 29;
	long long N = p * q;
	long long phi = (p - 1) * (q - 1);
	//d = A.ReturnRSA_D();
	//e = A.ReturnRSA_E();
	char* str4 = {0};

	printf("************************************************************************************************************************\n");
	printf("A、B共同协商的密钥：%ld\n", Des_Key);
	printf("************************************************************************************************************************\n");
	//printf("p=%ld\tq=%ld\tA的私钥:%ld\tA的公钥:%ld\n", A.RSA_P, A.RSA_Q, d, e);
	//printf("A的私钥:%d\nA的公钥:%d\n", d, e);
	printf("A的公钥:%d\n",e);
	printf("************************************************************************************************************************\n");
	printf("A的散列值:\n");
	FileSHA256("PLAINTEXT.txt", file_sha256);//对文件进行散列值输出
	puts(file_sha256);
	printf("************************************************************************************************************************\n");
	rsaEncode(file_sha256, str1_sha256, d, N);//RSA加密
	cout << "A的数据签名：" << endl;
	for (int i = 0; i < 64; i++) {
		char *str3 = _10_to_16(str1_sha256[i]);
		cout << str3;
		/*
		if (i == 5)
			str4 = str3;
			*/
	}
	//cout << endl << str4;
	printf("\n************************************************************************************************************************\n");
	cout << "B验证A的数据签名：" << endl;
	rsaDecode(str1_sha256, str2_sha256, e, N);//RSA解密
	for (int i = 0; i < 64; i++) {
		cout << str2_sha256[i];
	}
	printf("\n************************************************************************************************************************\n");

	fseek(fp1, 0L, SEEK_END);
	int size = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);

	fread(SCERCTKEY, 8, 1, fp2);

	if (size % 8 == 0) {
		int n = size / 8;

		for (int i = 0; i < n; i++) {
			fread(PLAINTEXT, 8, 1, fp1);
			DES_Efun(PLAINTEXT, SCERCTKEY, output);

			for (int i = 0; i < 64; i++)
			{
				fprintf_s(fp2, "%d\t ", output[i]);
			}
		}

		printf("\n");

	}
	else {
		int m = size / 8;

		for (int i = 0; i < (m + 1); i++) {

			if (i == m) {
				int remainder = size % 8;
				fread(PLAINTEXT, remainder, 1, fp1);

				for (int j = remainder; j < 8; j++) {
					PLAINTEXT[j] = 0;
				}
				DES_Efun(PLAINTEXT, SCERCTKEY, output);

			}
			else {
				fread(PLAINTEXT, 8, 1, fp1);
				DES_Efun(PLAINTEXT, SCERCTKEY, output);
			}

			for (int i = 0; i < 64; i++)
			{
				fprintf_s(fp2, "%d\t ", output[i]);
			}
		}

	}

	fseek(fp2, 0, SEEK_SET);
	fseek(fp2, 0L, SEEK_END);
	size = ftell(fp2);
	fseek(fp2, 0, SEEK_SET);

	printf("B解密，明文如下:\n");

	for (int i = 0; i < (size / 192); i++) {

		for (int i = 0; i < 64; i++)
		{
			fscanf_s(fp2, "%d", &CRYPTOTEXT[i]);

		}

		DES_Dfun(CRYPTOTEXT, SCERCTKEY, PLAINTEXT_D);

		for (int i = 0; i < 8; i++)
			printf("%c", PLAINTEXT_D[i]);

	}
	printf("\n************************************************************************************************************************\n");

	fclose(fp1);
	fclose(fp2);

	return 0;
}