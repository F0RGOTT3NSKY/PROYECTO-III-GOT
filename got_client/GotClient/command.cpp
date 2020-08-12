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
		std::cout << "\nProporciona informacion de ayuda para los comandos de Got.\n\n";
		std::cout << "got help <comando>\n\n";
		std::cout << "comando - Muestra informacion de ayuda del comando especificado.\n\n";
		break;
	case aux.add:
		break;
	case aux.commit:
		break;
	case aux.status:
		break;
	case aux.rollback:
		break;
	case aux.reset:
		break;
	case aux.sync:
		break;
	default:
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