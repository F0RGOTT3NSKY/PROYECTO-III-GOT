#include "command.h"

Command::Command() {
}
void Command::help() 
{
	system("cls");
	std::cout << "Para obtener mas informacion acerca de un comando especifico, escriba \"got help <comando>\" \n\n";
	std::cout << "init" << "\t\t" << "Instancia un nuevo repositorio en el servidor.\n";
	std::cout << "help" << "\t\t" << "Muestra en la consola informacion de lo que hace cada comando en GOT.\n";
	std::cout << "add" << "\t\t" << "Permite agregar todos los archivos que no esten registrados o que tengan nuevos cambios al repositorio.\n";
	std::cout << "commit" << "\t\t" << "Envia los archivos agregados y pendientes de commit al server.\n";
	std::cout << "status" << "\t\t" << "Muestra cuales archivos han sido cambiados, agregados o eliminados de acuerdo al commit anterior.\n";
	std::cout << "rollback" << "\t" << "Permite regresar un archivo en el tiempo a un commit especifico.\n";
	std::cout << "reset" << "\t\t" << "Deshace cambios locales para un archivo y lo regresa al ultimo commit.\n";
	std::cout << "sync" << "\t\t" << "Recupera los cambios para un archivo en el server y lo sincroniza con el archivo en el cliente.\n";
	std::cout << "\nPara mas informacion acerca del proyecto, consulte en r3dp4r4d153.github.io/PROYECTO-III-GOT/ \n\n";
	std::cout << "Sugerencia: Para ingresar un comando utilice \"got <comando>\"\n> ";
}
void Command::init(std::string name)
{
	system("cls");
	std::cout << "Se instancio un nuevo repositorio ["<<name<<"]";
}