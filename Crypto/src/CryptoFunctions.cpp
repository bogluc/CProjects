// Return_nth_char.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <ctype.h>

std::string sIn = "UTPDH UGNYH USVKC GMVCE FXLKQ IBWXR KUGIT ZNRLS BBHZL XMSNP \
				   KDKSC EBIHH KEWIB AYYMS BRPFR SBSJV UPLOU VADGR HRRWX FJVZT \
				   VOOVY HZCQU YUKWG EBPLU QFBPF OUKCG TBFRQ VHCFR KPGOU KFTZC \
				   QUMAW QKKWZ GSYFP PGMQK FTKUQ FBDER EZRNM CYEMG UCTFS VAWPK \
				   FTZCQ UMAWK QIJSL COVNT HDNVJ PNUJV BIHGG VRWXO NKCGT HKFLX \
				   GVKDZ JMVGC CIMVG DJPNU JRLSE WVKJT ASGUC SMVGD DDKVG NYHPW \
				   UVCCH IIYRD DBQNR WTHPF RWBBI VTTKV CGNTG SFFLI AWUXJ DUSHF \
				   PVHCF RRLAW EYQDF SRVME ESFZB CHHJR TTMVG ZPUBZ NFDAT IIYRT \
				   KWPKF THIVJ CITBF BLDPW PXRWT HULAW TGVYC HXKQL JSUSD CGCWO \
				   PPUPR VGKFD NUJKG IJIKK CPLKG CJIAO VKFTR GJFSA WKTZL ZESWG \
				   RWXWT VWTLW PXPXG GCJFP OSVYC BTZCU WXGZG JQPMH TRAIB JGWMG \
				   FGJZQ DPBJV YGMZC LEWXR CEBIA OVNYH JIKKC TGCWX FUHFJ ZKWXV \
				   CULDY ITKFT KWPKC GVCWI QTPWV YQEBF KKQQN HNZTT WIRFL IASVF \
				   RPEOD JRXGS PTCEK WPTGE ESGMC GTTVV PLTFF JYCWW VNYHT ZYRWH \
				   LOKUM UAWOK FPMVG BLTPV QNRDD SGGAW KWUKK PLKGC JXYOP PKPGO \
				   NZTTI CUJCH LSFKF TDBQN JTWUG DYNMV CKZTM FWCWH TWFFD JLOPU \
				   YAECH LQPGR UFYHM WPPRX FCDJC GOSFX MSUZG JQJLS XVPNH BG";

std::string sTest = "gsvm gsv drgxs ollpvw zg gsv yrt hszttb orlm zmw zhpvw dsvm wlilgsb szh ivgfimvw gl svi ldm slnv dszg droo yvxlnv lu blf levi gsv sroo lu gsv sznnvi svzwh sv zmhdvivw orvh z tizmw low ulivhg zmw zoo gsv yvzhgh gszg orev gsviv szev nzwv nv gsvri prmt";
std::string sTest1 = "The Atbash Cipher is a really simple substitution cipher that is sometimes called mirror code.It is believed to be the first cipher ever used, and its use pre - dates Egyptian examples of encryption.To use Atbash, you simply reverse the alphabet, so A encodes to Z, B to Y and so on.";

int ModularMultiplicativeInverse(int a);
void GetNthChar(int start, int step);
void InvertString(std::string& sIn);
std::string EncodeDecodeAtbash(std::string sIn, std::string& sRes);
std::string EncodeAffine(std::string sIn, int a, int b);
std::string DecodeAffine(std::string sIn, int a, int b);
std::string ConvertToUpper(std::string sIn);
std::string ConvertToLower(std::string sIn);
void EratosthenesSieve();

#define MAX_ARRAY_SIZE	1000

//#include "ExMArcel.h"

int main()
{
	/*	std::string sIn = "12345 67890 \
				abcdef ghijklmno \
				prstu vwxyz \
				12345 67890 \
				abcdef ghijklmno \
				prstu vwxyz";
	*/

	int start = 0;
	int step = 3;

//	GetNthChar(start, step);

	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

//	std::cout << sTest1 << '\n';

//	std::string sRes = sTest1;
//	sChiper = EncodeDecodeAtbash(sTest1, sRes);
	int a = 1;
	int b = 0;
//	std::string sPlainUpper;

	// convert to UPPER case
	sTest1 = ConvertToUpper(sTest1);

	std::string sChiper = EncodeAffine(sTest1, a, b);
//	std::cout << '\n' << sChiper << '\n';

//	sChiper = EncodeDecodeAtbash(sChiper, sRes);
	std::string sPlain = DecodeAffine(sChiper, a, b);
	
	// convert to lower case
	sPlain = ConvertToLower(sPlain);
//	std::cout << '\n' << sPlain << '\n';

	EratosthenesSieve();

	//invertString();

	return 0;
}

int ModularMultiplicativeInverse(int a)
{
	int a_inv = 0;
	int flag = 0;

	for (int i = 0; i < 26; i++)
	{
		flag = (a * i) % 26;
		if (flag == 1)
		{
			a_inv = i;
			break;
		}
	}

	return a_inv;
}
	
//
//
//
std::string ConvertToUpper(std::string sIn)
{
	std::string sOut = "";
	int j = 0;

	while (j < sIn.length()) {
		sOut += toupper(sIn[j]);
		j++;
	}

	return sOut;
}

//
//
//
std::string ConvertToLower(std::string sIn)
{
	std::string sOut = "";
	int j = 0;

	while (j < sIn.length()) {
		sOut += tolower(sIn[j]);
		j++;
	}

	return sOut;
}

// ???
void GetNthChar(int start, int step)
{
	size_t i = 0;
	size_t len = sIn.length();

	while (i < len)
	{
		if (!isalnum(sIn[i]) || sIn[i] == ' ')
		{
			sIn.erase(i, 1);
			len--;
		}
		else
			i++;
	}
	
	for (int i = 0; i < sIn.length() && (start + i * step) < sIn.length() ; i++)
	{
		if (i != 0 && i % 5 == 0)
		{
			std::cout << " ";
		}
		
		printf("%c", sIn[start + i * step]);
	}

	std::cout << '\n';
}

void InvertString(std::string& sIn)
{
	size_t i = 0;
	size_t len = sIn.length();
	char cTemp;

	while (i < len/2) {
		cTemp = sIn[len - 1 - i ];
		sIn[len - 1 - i] = sIn[i];
		sIn[i] = cTemp;

		i++;
	}
}

//
// a b c d e f g h i j k l m n o p q r s t u v w x y z
// z y x w v u t s r q p o n m l k j i h g f e d c b a
//
std::string EncodeDecodeAtbash(std::string sIn, std::string& sRes)
{
	size_t i = 0;
	size_t len = sIn.length();
	int iDif = 0;
	std::string sChiper = "";

	while (i < len) {
		if (sIn[i] >= 'a' && sIn[i] <= 'z')
		{
			iDif = sIn[i] - 'a';
//			sRes[i] = 'a' + 25 - iDif;
			sChiper = sChiper + (char)('a' + 25 - iDif);
		}
		else if (sIn[i] >= 'A' && sIn[i] <= 'Z')
		{
			iDif = sIn[i] - 'A';
//			sRes[i] = 'A' + 25 - iDif;
			sChiper = sChiper + (char)('A' + 25 - iDif);
		}
		else
		{
			// non-alphanumeric character
//			sRes[i] = sIn[i];
			sChiper = sChiper + sIn[i];
		}

		i++;
		iDif = 0;
	}

	return sChiper;
}

//
// c = (a*x + b) mod 26
// sPlain MUST be in UPPERCASE
//
std::string EncodeAffine(std::string sPlain, int a, int b)
{
	int i = 0;
	size_t len = sPlain.length();
	std::string sChiper = "";
	int d = 0;
	if (b < 26)
		d = b;
	else
		d = b % 26;
		
	while (i < len) {
		if (sPlain[i] >= 'A' && sPlain[i] <= 'Z')
		{
			sChiper = sChiper + (char)(((a * (sPlain[i] - 'A') + d) % 26) + 'A');
		}
		else
		{
			// non-alphanumeric character
			sChiper = sChiper + sPlain[i];
		}

		i++;
	}

	return sChiper;
}

//
// (a*x + b) mod 26 = c
// x = a^-1 * (c - b) mod 26  // a^-1 = the multiplicative inverse of a in modulo m, where m = 26
// x = a^-1 * (c + (26 - b)) mod 26
// sCipher MUST be in UPPERCASE
//
std::string DecodeAffine(std::string sCipher, int a, int b)
{
	size_t i = 0;
	size_t len = sCipher.length();
	std::string sPlain = "";
	int a_inv = 0;
	int flag = 0;

	a_inv = ModularMultiplicativeInverse(a);
	
	int d = 0;
	if (b < 26)
		d = 26 - b;
	else
		d = 26 - (b % 26);

	while (i < len) {
		if (sCipher[i] >= 'A' && sCipher[i] <= 'Z')
		{
			sPlain = sPlain + (char)(((a_inv * (sCipher[i] - 'A' + d)) % 26) + 'A');
	//		sPlain = sPlain + (char)(((a_inv * (sCipher[i] + 'A' - b)) % 26) + 'A');
		}
		else
		{
			// non-alphanumeric character
			sPlain = sPlain + sCipher[i];
		}

		i++;
	}

	return sPlain;
}

// Returns all prime numbers < n
void EratosthenesSieve()
{
	int prime[MAX_ARRAY_SIZE];

	for (int i = 2; i < MAX_ARRAY_SIZE; i++)
	{
		prime[i] = 1;
	}

	int i = 2;
	while (i < MAX_ARRAY_SIZE)
	{
		int k = 2;
		for (int j = k * i; j < MAX_ARRAY_SIZE; j = k * i  )  // 2*2 2*3 2*4 2*5 2*6  // 2*3 3*3 4*3  
		{
			prime[j] = 0;
			k++;
		}

		i++;
	}

	for (int i = 2; i < MAX_ARRAY_SIZE; i++)
	{
		if (prime[i] == 1)
			std::cout << i << ";\t";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file