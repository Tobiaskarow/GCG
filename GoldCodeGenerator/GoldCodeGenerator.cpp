#include "stdafx.h"
#include "GoldCodeGenerator.h"

#include <iostream>

GoldCodeGenerator::GoldCodeGenerator()
{
	//Initialising Registers with Ones
	for (size_t i = 0; i < 10; i++)
	{
		upperRegister[i] = true;
		lowerRegister[i] = true;
	}

}

bool GoldCodeGenerator::shiftUpperRegister(bool reg[], int len)
{
	bool last = reg[len-1];
	bool tap = reg[2];

	for (int i = len - 1; i >= 1; i--)
	{
		reg[i] = reg[i - 1];
	}

	reg[0] = last ^ tap;
	
	return last;
}

bool GoldCodeGenerator::shiftLowerRegister(bool reg[], int len, int tap1, int tap2)
{
	bool last = reg[len - 1];

	bool tapOne = reg[tap1-1];
	bool tapTwo = reg[tap2-1];
	
	bool internalTap1 = reg[1];
	bool internalTap2 = reg[2];
	bool internalTap3 = reg[5];
	bool internalTap4 = reg[7];
	bool internalTap5 = reg[8];

	for (int i = len - 1; i >= 1; i--)
	{
		reg[i] = reg[i - 1];
	}

	reg[0] = last ^ internalTap1 ^ internalTap2 ^ internalTap3 ^ internalTap4 ^ internalTap5;

	return (tapOne ^ tapTwo);
}

void GoldCodeGenerator::clearRegisters()
{
	for (size_t i = 0; i < 10; i++)
	{
		upperRegister[i] = true;
		lowerRegister[i] = true;
	}
}


int GoldCodeGenerator::generateChipSequence(unsigned int lengthOfSequence, int tapOne, int tapTwo, int rotation)
{
	clearRegisters();


	std::cout << "{ ";
	for (size_t i = 0; i < lengthOfSequence; i++)
	{
		bool upper, lower;
		upper = shiftUpperRegister(upperRegister, LENGTH);
		lower = shiftLowerRegister(lowerRegister, LENGTH, tapOne, tapTwo);
		//cout << upper << " XOR " << lower << "  "<< (upper ^ lower) << endl;
		std::cout << (upper ^ lower);
		std::cout << ',';
	}
	std::cout << "}, ";
	std::cout << std::endl;
	return 42;
}

GoldCodeGenerator::~GoldCodeGenerator()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	int length = 1023;
	GoldCodeGenerator gcg;

	
	gcg.generateChipSequence(length, 2, 6, 5);//1
	gcg.generateChipSequence(length, 3, 7, 6);//2
	gcg.generateChipSequence(length, 4, 8, 7);//3
	gcg.generateChipSequence(length, 5, 9, 8);//4
	gcg.generateChipSequence(length, 1, 9, 17);//5
	gcg.generateChipSequence(length, 2, 10, 18);//6
	gcg.generateChipSequence(length, 1, 8, 139);//7
	gcg.generateChipSequence(length, 2, 9, 140);//8
	gcg.generateChipSequence(length, 3, 10, 141); //9
	gcg.generateChipSequence(length, 2, 3, 251);//10
	gcg.generateChipSequence(length, 3, 4, 252);//11
	gcg.generateChipSequence(length, 5, 6, 254);//12
	

	gcg.generateChipSequence(length, 6, 7, 255);//13
	gcg.generateChipSequence(length, 7, 8, 256);//14
	gcg.generateChipSequence(length, 8, 9, 257);//15
	gcg.generateChipSequence(length, 9, 10, 258);//16
	gcg.generateChipSequence(length, 1, 4, 469);//17
	gcg.generateChipSequence(length, 2, 5, 470);//18
	gcg.generateChipSequence(length, 3, 6, 471);//19
	gcg.generateChipSequence(length, 4, 7, 472);//20
	gcg.generateChipSequence(length, 5, 8, 473);//21
	gcg.generateChipSequence(length, 6, 9, 474);//22
	gcg.generateChipSequence(length, 1, 3, 509);//23
	gcg.generateChipSequence(length, 4, 6, 512);//24

	return 0;
}
