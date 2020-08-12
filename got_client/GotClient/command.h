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
	Muestra toda la informacion general de los comandos disponibles en Got.
	*/
	void help();
	/**
	Muestra la informacion en especifico de cada comando disponible en Got.
	*/
	void help_command(std::string command);
	/**
	Instancia un nuevo repositorio en el servidor y lo identifica con el nombre indicado por <name>.
	@param <name> nombre del nuevo repositorio en el servidor.
	*/
	void init(std::string name);
	/**
	Permite agregar todos los archivos que no esten registrados o que tengan nuevos cambios al repositorio.
	Ignorando los archivos que esten configurados en .gotignore.
	@param <name> nombre del archivo por agregar.
	@param <-A> para agregar todos los archivos relevantes.
	*/
	void add(std::string name);


private:

};
#endif // COMMAND_H