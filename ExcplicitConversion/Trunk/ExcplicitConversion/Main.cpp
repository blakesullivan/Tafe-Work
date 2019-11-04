//Blake Sullivan - Main.cpp
#include <iostream>

int main()
{
	double dV1 = 5.3;
	int iV2 = 13, iV3 = 3;

	std::cout << "dV1 - (iV2/iV3)\n";
	std::cout << dV1 << " - (" << static_cast<double>(iV2) << "/" << iV3 << ")\n";
	dV1 -= (static_cast<double>(iV2)/iV3);

	std::cout << dV1 << std::endl;

	system("PAUSE");
	return 0;
}