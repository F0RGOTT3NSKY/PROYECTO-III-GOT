#include "command.h"
#include "aux_task.h"
#include "cpr/cpr.h"

Command::Command() 
{
	//Default constructor
}
void Command::help() 
{
	std::cout << "Para obtener mas informacion acerca de un comando especifico, escriba \"got help <comando>\" \n\n";
	std::cout << "init" << "\t\t" << "Instancia un nuevo repositorio en el servidor.\n";
	std::cout << "help" << "\t\t" << "Proporciona informacion de ayuda para los comandos de Got.\n";
	std::cout << "add" << "\t\t" << "Permite agregar todos los archivos que no esten registrados o que tengan nuevos cambios al repositorio.\n";
	std::cout << "commit" << "\t\t" << "Envia los archivos agregados y pendientes de commit al server.\n";
	std::cout << "status" << "\t\t" << "Muestra cuales archivos han sido cambiados, agregados o eliminados de acuerdo al commit anterior.\n";
	std::cout << "rollback" << "\t" << "Permite regresar un archivo en el tiempo a un commit especifico.\n";
	std::cout << "reset" << "\t\t" << "Deshace cambios locales para un archivo y lo regresa al ultimo commit.\n";
	std::cout << "sync" << "\t\t" << "Recupera los cambios para un archivo en el server y lo sincroniza con el archivo en el cliente.\n";
	std::cout << "\nPara mas informacion acerca del proyecto, consulte en r3dp4r4d153.github.io/PROYECTO-III-GOT/ \n\n";
	std::cout << "Sugerencia: Para ingresar un comando utilice \"got <comando>\"\n> ";
}
void Command::help_command(std::string command)
{
	Aux aux;
	switch (aux.command_detector(command))
	{
	case aux.init:
		
		break;
	case aux.help:
		std::cout << "Proporciona informacion de ayuda para los comandos de Got.\n\n";
		std::cout << "got help <comando>\n\n";
		std::cout << "     comando\tMuestra informacion de ayuda del comando especificado.\n\n";
		break;
	case aux.add:
		std::cout << "Permite agregar todos los archivos que no esten registrados  o que tengan nuevos cambios al repositorio.\n";
		std::cout << "Ignora los archivos que esten configurados en .gotignore.\n";
		std::cout << "Cuando los archivos se agregan, se marcan como pendientes de commit.\n\n";
		std::cout << "got add <parametro>\n\n";
		std::cout << "     -A     \tAgrega todos los archivos relevantes.\n";
		std::cout << "     name\tAgrega un archivo segun el nombre indicado.\n";
		break;
	case aux.commit:
		std::cout << "Permite enviar los archivos agregados y pendientes de commit al server.\n";
		std::cout << "Se debe especificar un mensaje a la hora de hacer el commit.\n";
		std::cout << "El server recibe los cambios, y cuando este proceso ha terminado de procesar los cambios,\n";
		std::cout << "retorna un id de commit al cliente generado con MD5.\n\n";
		std::cout << "got commit <mensaje>\n\n";
		std::cout << "     mensaje\tEspecifica la etiqueta del commit.\n\n";
		std::cout << "El server verifica si el commit esta al dia con el resto de cambios realizados por otros usuarios.\n";
		std::cout << "En caso que no sea asi, se rechaza el commit.\n\n";
		break;
	case aux.status:
		std::cout << "Muestra cuales archivos han sido cambiados, agregados o eliminados de acuerdo al commit anterior.\n";
		std::cout << "Si se especifica un archivo en especifico, muestra el historial de cambios, recuperando el historial de\n";
		std::cout << "cambios desde el server.\n\n";
		std::cout << "got status <file>\n\n";
		std::cout << "     file\tNombre del archivo.\n\n";
		break;
	case aux.rollback:
		std::cout << "Permite regresar un archivo en el tiempo a un commit en especifico. Recuperando el archivo hasta dicha version.\n\n";
		std::cout << "got  rollback <file> <commit>\n\n";
		std::cout << "     file\tNombre del archivo.\n";
		std::cout << "     commit\tNombre del commit.\n\n";
		break;
	case aux.reset:
		std::cout << "Deshace cambios locales de un archivo y lo regresa al ultimo commit\n\n";
		std::cout << "got reset <file>\n\n";
		std::cout << "     file\tNombre del archivo.\n\n";
		break;
	case aux.sync:
		std::cout << "Recupera los cambios de un archivo en el server y lo sincroniza con el archivo en el cliente.\n";
		std::cout << "Si existen cambios locales, se permite hacer merge de los cambios.\n\n";
		std::cout << "got sync <file>\n\n";
		std::cout << "     file\tNombre del archivo.\n\n";
		break;
	default:
		std::cout << "El programa de ayuda no admite este comando. Pruebe con" <<"\033[33m" <<" got help "<< "\033[0m" << "para ver los comandos disponibles.\n";
		break;
	}

}
void Command::init(std::string name)
{
	system("cls");
	if (name == "") {
		std::cout << "No se permite crear repositorios sin nombre. Para obtener mas informacion acerca de un comando especifico, escriba \"got help <comando>\" \n";
	}
	else {

		std::cout << "Se instancio un nuevo repositorio [" << name << "]";
	}
}
void Command::add(std::string name) 
{

}
void Command::commit(std::string mensaje) 
{

}
void Command::status(std::string file)
{

}
void Command::rollback(std::string file, std::string commit)
{

}
void Command::reset(std::string file)
{

}
void Command::sync(std::string file)
{

}