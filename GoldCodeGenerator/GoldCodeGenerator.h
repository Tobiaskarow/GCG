#pragma once
class GoldCodeGenerator
{
public:
	GoldCodeGenerator();
	~GoldCodeGenerator();
	int generateChipSequence(unsigned int lengthOfSequence, int tapOne, int tapTwo, int rotation);
private:
	const int LENGTH = 10;
	bool upperRegister[10];
	bool lowerRegister[10];

	bool shiftUpperRegister(bool reg[], int len);
	bool shiftLowerRegister(bool reg[], int len, int tap1, int tap2);

	void clearRegisters(void);
};

