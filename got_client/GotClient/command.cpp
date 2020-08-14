#include "command.h"
#include "aux_task.h"
#include "cpr/cpr.h"
#include <list>

std::string ID;
std::string Directorio;
std::list<std::list<std::string>> ArchivosAgregados;

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
		std::cout << "Permite instanciar un nuevo repositorio en el servidor y lo identifica con el nombre indicado por <name>.\n\n";
		std::cout << "Sintaxis del comando:\n";
		std::cout << "     got init <name>\n\n";
		std::cout << "Parametros:\n";
		std::cout << "     name\tNombre del repositorio.\n\n> ";
		break;
	case aux.help:
		std::cout << "Proporciona informacion de ayuda para los comandos de Got.\n\n";
		std::cout << "Sintaxis del comando:\n";
		std::cout << "     got help <comando>\n\n";
		std::cout << "Parametros:\n";
		std::cout << "     comando\tNombre del comando en especifico.\n\n> ";
		break;
	case aux.add:
		std::cout << "Permite agregar todos los archivos que no esten registrados  o que tengan nuevos cambios al repositorio.\n";
		std::cout << "Ignora los archivos que esten configurados en .gotignore.\n";
		std::cout << "Cuando los archivos se agregan, se marcan como pendientes de commit.\n\n";
		std::cout << "Sintaxis del comando:\n";
		std::cout << "     got add <parametro>\n\n";
		std::cout << "Parametros:\n";
		std::cout << "     -A     \tAgrega todos los archivos relevantes.\n";
		std::cout << "     name\tAgrega un archivo segun el nombre indicado.\n\n> ";
		break;
	case aux.commit:
		std::cout << "Permite enviar los archivos agregados y pendientes de commit al server.\n";
		std::cout << "Se debe especificar un mensaje a la hora de hacer el commit.\n";
		std::cout << "El server recibe los cambios, y cuando este proceso ha terminado de procesar los cambios,\n";
		std::cout << "retorna un id de commit al cliente generado con MD5.\n\n";
		std::cout << "Sintaxis del comando:\n";
		std::cout << "     got commit <mensaje>\n\n";
		std::cout << "Parametros:\n";
		std::cout << "     mensaje\tNombre del commit.\n\n";
		std::cout << "El server verifica si el commit esta al dia con el resto de cambios realizados por otros usuarios.\n";
		std::cout << "En caso que no sea asi, se rechaza el commit.\n\n> ";
		break;
	case aux.status:
		std::cout << "Muestra cuales archivos han sido cambiados, agregados o eliminados de acuerdo al commit anterior.\n";
		std::cout << "Si se especifica un archivo en especifico, muestra el historial de cambios, recuperando el historial de\n";
		std::cout << "cambios desde el server.\n\n";
		std::cout << "Sintaxis del comando:\n";
		std::cout << "     got status <file>\n\n";
		std::cout << "Parametros:\n";
		std::cout << "     file\tNombre del archivo.\n\n> ";
		break;
	case aux.rollback:
		std::cout << "Permite regresar un archivo en el tiempo a un commit en especifico. Recuperando el archivo hasta dicha version.\n\n";
		std::cout << "Sintaxis del comando:\n";
		std::cout << "     got  rollback <file> <commit>\n\n";
		std::cout << "Parametros:\n";
		std::cout << "     file\tNombre del archivo.\n";
		std::cout << "     commit\tNombre del commit.\n\n> ";
		break;
	case aux.reset:
		std::cout << "Deshace cambios locales de un archivo y lo regresa al ultimo commit\n\n";
		std::cout << "Sintaxis del comando:\n";
		std::cout << "     got reset <file>\n\n";
		std::cout << "Parametros:\n";
		std::cout << "     file\tNombre del archivo.\n\n> ";
		break;
	case aux.sync:
		std::cout << "Recupera los cambios de un archivo en el server y lo sincroniza con el archivo en el cliente.\n";
		std::cout << "Si existen cambios locales, se permite hacer merge de los cambios.\n\n";
		std::cout << "Sintaxis del comando:\n";
		std::cout << "     got sync <file>\n\n";
		std::cout << "Parametros:\n";
		std::cout << "     file\tNombre del archivo.\n\n> ";
		break;
	default:
		std::cout << "El programa de ayuda no admite este comando. Pruebe con" << "\033[33m" << " got help " << "\033[0m" << "para ver los comandos disponibles.\n> ";
		break;
	}

}
void Command::init(std::string name)
{
	if (name == "") {
		std::cout << "No se permite instanciar un repositorio sin nombre. Para obtener mas informacion acerca de un comando\n";
		std::cout << "especifico, escriba" << "\033[33m" << " got help init" << "\033[0m" << "\n> ";
	}
	else {
		std::string id = " {\"id\": 0, \"nombre\": ";
		std::string nombre = "\"" + name + "\"" + ", \"arbol\": \"TU PUTA MADRE\", \"gotignore\": \"TU PUTA MADRE\"} ";
		std::string BODY = id + nombre;

		auto r = cpr::Post(cpr::Url{ "http://localhost:3000/repositorios" },
			cpr::Body{ (BODY) },
			cpr::Header{ { "Content-Type", "application/json" } });
		std::cout << "Se instancio un nuevo repositorio [" << name << "]" << "\n";
	}
	std::cout << "Ingrese un directorio:" << "\n";
	std::cin >> Directorio;
	DWORD ftyp = GetFileAttributesA(Directorio.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES) {
		std::cout << "Hubo un problema a la hora de registrar el directorio " << "\n";
	}

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY) {
		std::cout << "El directorio se ha guardado" << "\n";
	}
	else {
		std::cout << "Ingrese un directorio válido" << "\n";
		auto r = cpr::Delete(cpr::Url{ "http://localhost:3000/repositorios/" + ID });
	}
}

void Command::select(std::string name)
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:3000/repositorios" });
	std::string BODY = r.text.c_str();
	std::size_t found = BODY.find(name);
	if (found != std::string::npos) {
		std::cout << "Se ha encontrado " << name << "\n";
		std::size_t found2 = BODY.find(",") - 1;
		if (found2 == 7) {
			ID = BODY[7];
		}
		else {
			ID = BODY.substr(7, found2);
		}
	}
	else {
		std::cout << "El repositorio \"" << name << "\" no se pudo encontrar en la base de datos" << "\n";
	}
}

void Command::add(std::string name)
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:3000/archivos" });
	std::string BODY = r.text.c_str();
	std::size_t found = BODY.find(name);
	std::string FileID;
	std::list<std::string> archivo;
	if (found != std::string::npos) {
		std::size_t found2 = BODY.find(",") - 1;
		if (found2 == 7) {
			FileID = BODY[7];
			archivo.push_back(FileID);
			archivo.push_back(ID);
			archivo.push_back(name);
			archivo.push_back(Directorio);
			archivo.push_back("CONTENIDO");
			ArchivosAgregados.push_back(archivo);
		}
		else {
			FileID = BODY.substr(7, found2);
			archivo.push_back(FileID);
			archivo.push_back(ID);
			archivo.push_back(name);
			archivo.push_back(Directorio);
			archivo.push_back("CONTENIDO");
			ArchivosAgregados.push_back(archivo);
		}
	}
	else {
		archivo.push_back("0");
		archivo.push_back(ID);
		archivo.push_back(name);
		archivo.push_back(Directorio);
		archivo.push_back("CONTENIDO");
		ArchivosAgregados.push_back(archivo);
	}
}
void Command::commit(std::string mensaje)
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:80/get" });
	if (r.status_code >= 400) {
		std::cout << "Favor inicializar un repositorio, utilize el comando got init para hacerlo";
	}
	else {
		auto r = cpr::Put(cpr::Url{ "http://localhost:80/repositorios/archivos/commit" },
			cpr::Body{ R"({"id":"0", "nombre": name, "arbol":"", "gotignore":"" })" },
			cpr::Header{ { "Content-Type", "application/json" } });
		std::cout << "Commit realizado con el mensaje [" << mensaje << "]";

	}
}
void Command::status(std::string file)
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:80/get" });
	if (r.status_code >= 400) {
		std::cout << "Favor inicializar un repositorio, utilize el comando got init para hacerlo";
	}
	else {
		std::cout << "Favor inicializar un repositorio, utilize el comando got init para hacerlo";
		auto r = cpr::Get(cpr::Url{ "http://localhost:80/repositorios/archivos/status" });
		std::cout << "Estos son los cambios realizados en [" << file << "]";
	}
}
void Command::rollback(std::string file, std::string commit)
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:80/get" });
	if (r.status_code >= 400) {
		std::cout << "Favor inicializar un repositorio, utilize el comando got init para hacerlo";
	}
	else {
		std::cout << "Favor inicializar un repositorio, utilize el comando got init para hacerlo";
		auto r = cpr::Put(cpr::Url{ "http://localhost:80/repositorios/archivos/rollback" },
			cpr::Body{ R"({"id":"0", "nombre": name, "arbol":"", "gotignore":"" })" },
			cpr::Header{ { "Content-Type", "application/json" } });
		std::cout << "Se regreso el archivo [" << file << "] al commit [" << commit << "]";
	}
}
void Command::reset(std::string file)
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:80/get" });
	if (r.status_code >= 400) {
		std::cout << "Favor inicializar un repositorio, utilize el comando got init para hacerlo";
	}
	else {
	}

}
void Command::sync(std::string file)
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:80/get" });
	if (r.status_code >= 400) {
		std::cout << "Favor inicializar un repositorio, utilize el comando got init para hacerlo";
	}
	else {
		std::cout << "Favor inicializar un repositorio, utilize el comando got init para hacerlo";
		auto r = cpr::Get(cpr::Url{ "http://localhost:80/repositorios/archivos/sync" });
		std::cout << "Cambios sincronizados";
	}
}