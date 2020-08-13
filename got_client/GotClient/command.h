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
	@param string name
	@param string -A
	*/
	void add(std::string name);
	/**
	Permite enviar los archivos agregados y pendientes de commit al server. Se debe especificar un mensaje a la hora de hacer commit.
	El server recibe los cambios, y cuando este proceso ha terminado de procesar los cambios, retorna un id de commit al cliente generado con MD5.
	@param string mensaje
	*/
	void commit(std::string mensaje);
	/**
	Muestra cuales archivos han sido cambiados, agregados o eliminados de acuerdo al commit anterior.
	Si se especifica un archivo en especifico, muestra el historial de cambios, recuperando el historial de cambios desde el server.
	@param string file
	*/
	void status(std::string file);
	/**
	Permite regresar un archivo en el tiempo a un commit en especifico. Recuperando el archivo hasta dicha version.
	@param string file
	@param string commit
	*/
	void rollback(std::string file, std::string commit);
	/**
	Deshace cambios locales de un archivo y lo regresa al ultimo commit.
	@param string file
	*/
	void reset(std::string file);
	/**
	Recupera los cambios de un archivo en el server y lo sincroniza con el archivo en el cliente.
	Si existen cambios locales, se permite hacer merge de los cambios.
	@param string file
	*/
	void sync(std::string file);
private:

};
#endif // COMMAND_H