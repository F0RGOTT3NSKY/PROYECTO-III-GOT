#include "main.h"
#include "command.h"

int main() {
	GotClient client;
	client.main();
}

GotClient::GotClient()
{

}

void GotClient::main()
 {	
	Command command;
	std::cout << "Bienvenido a GOT v0.1.\n";
	std::cout << "Ingrese \"got help\" para mas informacion. \n> ";
	int x = 1;
	while (x==1)
	{
		std::string inputcommand;
		std::getline(std::cin, inputcommand);
		switch (newconversion(inputcommand))
		{
		case help:
			command.help();
			break;
		case init:
			command.init(phase3);
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
