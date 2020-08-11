#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <iomanip>

std::string phase1 = "";
std::string phase2 = "";
std::string phase3 = "";
std::string phase4 = "";

class GotClient
{
public:
	/**
	Default constructor.
	*/
	GotClient();
	/**
	Lee los comandos ingresados por el usuario.
	*/
	void main();
private:

};
/**
Valores que son usados para determinar que comando esta usando el usuario.
*/
enum string_code {
	help,
	init,
	invalid,
};
/**
Determina que tipo de comando se esta usando y este se divide en secciones para un manejo mas eficiente.
@param string inputcommand 
@return enum string_code
*/
string_code newconversion(std::string inputcommand) {
	std::string word = "";
	int y = 0;
	phase1 = "";
	phase2 = "";
	phase3 = "";
	phase4 = "";
	for (auto x : inputcommand) {
		//std::cout << "For :: y = " << y << std::endl;
		if (x == ' ') {
			switch (y)
			{
			case 0:
				phase1 = word;
				word = "";
				y++;
				break;
			case 1:
				phase2 = word;
				word = "";
				y++;
				break;
			case 2:
				phase3 = word;
				word = "";
				y++;
				break;
			case 3:
				phase4 = word;
				word = "";
				y++;
			default:
				break;
			}
		}
		else
		{
			word = word + x;
		}
	}
	switch (y)
	{
	case 0:
		phase1 = word;
	case 1:
		phase2 = word;
	case 2:
		phase3 = word;
	case 3:
		phase4 = word;
	default:
		break;
	}
	if (y >= 1) {
		if (phase2 == "help") return help;
		if (phase2 == "init") return init;
	}
	else {
		return invalid;
	}
	//std::cout << phase1 << phase2 << phase3 << phase4<< std::endl;
}
#endif // MAIN_H