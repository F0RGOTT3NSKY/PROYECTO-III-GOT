#include "main.h"
#include "command.h"
#include "aux_task.h"

int main() {
	GotClient client;
	client.main();
}

GotClient::GotClient()
{
	//Default constructor
}

void GotClient::main()
 {	
	Command command;
	Aux aux;
	std::cout << "Proyecto III GOT [Version 32.0.a861559.455a]\n";
	std::cout << "TEC | 2020 ";
	std::cout << "Ingrese \"got help\" para mas informacion. \n";
	int x = 1;
	while (x==1)
	{
		std::cout << "Sugerencia: Para ingresar un comando utilice \"got <comando>\"\n> ";
		std::string inputcommand;
		std::getline(std::cin, inputcommand);
		switch (aux.command_detection(inputcommand))
		{
		case aux.help:
			command.help();
			break;
		case aux.init:
			command.init(aux.phase3);
			break;
		case aux.help_command:
			command.help_command(aux.phase3);
			break;
		default:
			std::cout << "default \n";
			break;
		}
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
