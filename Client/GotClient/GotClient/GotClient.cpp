// GotClient.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <iomanip>

void menu();

int main()
{
	std::cout << "Bienvenido a GOT v0.1.\n";
	std::cout << "Ingrese \"got <help>\" para mas informacion. \n> ";
	int x = 1;
	while (x==1)
	{
		menu();
	}
	return 0;
}
enum string_code {
	help,
	init,
};

string_code coversion(std::string command) {
	if (command == "got <help>") return help;
	if (command == "got init <name>") return init;
}

void menu() {
	std::string command;
	std::getline(std::cin, command);
	//std::cout << "Command you entered: " << command <<"\n";
	switch (coversion(command))
	{
	case help:
		system("cls");
		std::cout << "Para obtener mas informacion acerca de un comando especifico, escriba \"got <help> <comando>\" \n\n";
		std::cout << "init"<<"\t\t" <<"Instancia un nuevo repositorio en el servidor.\n";
		std::cout << "help"<<"\t\t"<<"Muestra en la consola informacion de lo que hace cada comando en GOT.\n";
		std::cout << "add"<<"\t\t"<<"Permite agregar todos los archivos que no esten registrados o que tengan nuevos cambios al repositorio.\n";
		std::cout << "commit"<<"\t\t"<<"Envia los archivos agregados y pendientes de commit al server.\n";
		std::cout << "status"<<"\t\t"<<"Muestra cuales archivos han sido cambiados, agregados o eliminados de acuerdo al commit anterior.\n";
		std::cout << "rollback"<<"\t"<<"Permite regresar un archivo en el tiempo a un commit especifico.\n";
		std::cout << "reset"<<"\t\t"<<"Deshace cambios locales para un archivo y lo regresa al ultimo commit.\n";
		std::cout << "sync" << "\t\t" << "Recupera los cambios para un archivo en el server y lo sincroniza con el archivo en el cliente.\n";
		std::cout << "\nPara mas informacion acerca del proyecto, consulte en r3dp4r4d153.github.io/PROYECTO-III-GOT/ \n\n";
		std::cout << "Sugerencia: Para ingresar un comando utilice \"got <comando>\"\n> ";
		break;
	case init:
		std::cout << "init  \n";
		break;
	default:
		std::cout << "default \n";
		break;
	}

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
