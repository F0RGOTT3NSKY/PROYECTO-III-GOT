#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>


class Command
{
public:
	/**
	Default constructor
	*/
	Command();
	/**
	Muestra toda la informacion de lo que hace cada comando en Got.
	*/
	void help();
	/**
	Instancia un nuevo repositorio en el servidor y lo identifica con el nombre indicado por <name>.
	@param <name> nombre del nuevo repositorio en el servidor.
	*/
	void init(std::string name);


private:

};
#endif // COMMAND_H