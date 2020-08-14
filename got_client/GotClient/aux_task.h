#ifndef AUX_TASK
#define AUX_TASK

#include <iostream>
#include <string>
#include <iomanip>

class Aux
{
public:
	/**
	Variable que guarda la primera parte del comando
	*/
	std::string phase1 = "";
	/**
	Variable que guarda la segunda parte del comando
	*/
	std::string phase2 = "";
	/**
	Variable que guarda la tercera parte del comando
	*/
	std::string phase3 = "";
	/**
	Variable que guarda la cuarta parte del comando
	*/
	std::string phase4 = "";
	Aux();
	/**
	Valores que son usados para determinar que comando esta usando el usuario.
	*/
	enum string_code {
		help,
		help_command,
		init,
		add,
		commit,
		status,
		rollback,
		reset,
		sync,
		select,
		invalid,
	};
	/**
	Determina que tipo de comando se esta usando y este se divide en secciones para un manejo mas eficiente.
	@param string inputcommand
	@return enum string_code
	*/
	string_code command_detection(std::string inputcommand);
	/**
	Determina que tipo de comando se esta usando para ver su informacion en la seccion de ayuda.
	@param string inputcommand
	@return enum string_code
	*/
	string_code command_detector(std::string inputcommand);
private:

};

#endif // AUX_TASK