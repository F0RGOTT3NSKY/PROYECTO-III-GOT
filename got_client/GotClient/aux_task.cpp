#include "aux_task.h"

Aux::Aux()
{
	//Default constructor
}
Aux::string_code Aux::command_detector(std::string inputcommand)
{
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
		if (word == phase2) {
			phase3 = "";
		}
		else {
			phase3 = word;
		}
	case 3:
		if (word == phase3) {
			phase4 = "";
		}
		else {
			phase4 = word;
		}
	default:
		break;
	}
	if (y >= 1) {
		if (phase2 == "help") return help;
		if (phase2 == "help" && phase3 != "") return help_command;
		if (phase2 == "init") return init;
	}
	else {
		return invalid;
	}
}
