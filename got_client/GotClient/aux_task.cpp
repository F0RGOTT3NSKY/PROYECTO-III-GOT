#include "aux_task.h"

Aux::Aux()
{
	//Default constructor
}
Aux::string_code Aux::command_detection(std::string inputcommand) 
{
	if (inputcommand != "") 
	{
		std::string::iterator x;
		int phase = 1;
		phase1 = "";
		phase2 = "";
		phase3 = "";
		phase4 = "";
		std::string command = "";
		for (x = inputcommand.begin(); x < inputcommand.end(); x++)
		{
			if (*x == ' ') {
				//std::cout << command << "\n";
				//std::cout << "espacio\n";
				switch (phase)
				{
				case 1:
					phase1 = command;
					phase++;
					command = "";
					break;
				case 2:
					phase2 = command;
					phase++;
					command = "";
					break;
				case 3:
					phase3 = command;
					phase++;
					command = "";
					break;
				case 4:
					phase4 = command;
					phase++;
					command = "";
					break;
				default:
					if (command != "") {
						phase1 = "";
						phase++;
						command = "";
						break;
					}			
					break;
				}
			}
			else {
				//std::cout << *x << "\n";
				command = command + *x;
			}	
		}
		//std::cout << command << "\n";
		switch (phase)
		{
		case 1:
			phase1 = command;
			command = "";
			break;
		case 2:
			phase2 = command;
			command = "";
			break;
		case 3:
			phase3 = command;
			command = "";
			break;
		case 4:
			phase4 = command;
			command = "";
			break;
		default:
			if (command != "") {
				phase1 = "";
				phase++;
				command = "";
				break;
			}
			break;
		}
		//std::cout << "Phase_1 = " << phase1 << "\nPhase_2 = " << phase2 << "\nPhase_3 = " << phase3 << "\nPhase_4 = " << phase4 << "\n";
		if (phase1 == "got" && phase2 == "help" && phase3 == "") return help;
		if (phase1 == "got" && phase2 == "help" && phase3 != "") return help_command;
		if (phase2 == "init") return init;
		else return invalid;
	}
	else 
	{
		return invalid;
	}
}
Aux::string_code Aux::command_detector(std::string inputcommand) {
	if (inputcommand == "help") return help;
	if (inputcommand == "init") return init;
	if (inputcommand == "add") return add;
	if (inputcommand == "commit") return commit;
	if (inputcommand == "status") return status;
	if (inputcommand == "rollback") return rollback;
	if (inputcommand == "reset") return reset;
	if (inputcommand == "sync") return sync;
	else return invalid;
}