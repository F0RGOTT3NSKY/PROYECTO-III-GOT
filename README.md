# Software Necesario #

Para poder acceder a este proyecto se necesita tener instalado los sigueintes programas:

### Visual Studio 2019 

Este se usa para ejecutar y modificar el codigo del proyecto.

Este se puede descargar desde el enlace: https://visualstudio.microsoft.com/es/downloads/

![VSD](https://user-images.githubusercontent.com/28927252/90082109-36db4400-dccc-11ea-9b16-b3ba33ecea25.PNG)

Debe de elegir Ingles como idioma predetermiando.

En proceso de instalaccion de Visual Studio se le pedirá que especifique los complementos que se desean instalar. Se debe asegurar de agregar:

1. Desarrollo de escritorio de .NET 

![NET](https://user-images.githubusercontent.com/28927252/90084113-c20b0880-dcd1-11ea-9c6c-b6df6ee937a9.PNG)

2. Desarrollo de Node.js

![NJS](https://user-images.githubusercontent.com/28927252/90084057-87a16b80-dcd1-11ea-8ef4-052d75e586f3.PNG)

3. Desarrollo para escritorio con C++

![C++](https://user-images.githubusercontent.com/28927252/90084139-d0592480-dcd1-11ea-8bf1-d1957f06c993.PNG)

4. Almacenamiento y porcesamiento de datos

![SQL](https://user-images.githubusercontent.com/28927252/90084102-bae3fa80-dcd1-11ea-8e43-207a747fd868.PNG)

5. Desarrollo de extensiones de Visual Studio 

![VSE](https://user-images.githubusercontent.com/28927252/90084161-e1099a80-dcd1-11ea-9376-a53cba42f2c7.PNG)

Una vez que se tenga Visual Studio Instalado es necesario instalar un paquete para poder instalar librerias. Para esto es necesario ingresar al siguiente enlace: https://github.com/microsoft/vcpkg

Una vez en la pagina de github prescione el boton verde "Code" y seleccione "download ZIP"

![VCPKG](https://user-images.githubusercontent.com/28927252/90194462-a4e34200-dd84-11ea-9294-397d03c70c8a.JPG)

Una vez que tenga el zip descargado tiene que crear una carpeta en el Disco C y llamarla "Librerias" la dirrecion debe de quedarle así: "C:\Librerias" 

Luego es necesario que descomprima el contenido del ZIP que descargo en la carpeta "Librerias", dejando una carpeta de nombre "vcpkg-master"

Una vez que tenga lo anterior listo tiene que abrir una ventada de powershell y ubicarse en la carpeta "vcpkg-master" con los sigueintes comandos: 

cd\

cd C:\Librerias\vcpkg-master

Unas vez dentro de la carpeta se procedera a instalar vcpkg con los siguentes comandos:

.\bootstrap-vcpkg.bat
.\vcpkg integrate install

Con el vcpkg instalado ya se puede instalar la libreria cpr, la cual servira para poder realizar la conexión, esto se hace con los siguientes comandos:

.\vcpkg search cpr
Este comando buscara y comprobara que se pueda instalar la libreria

.\vcpkg install cpr




### MySQL

Con este software se manejan las bases de datos

Se puede descargar del sigueinte enlace: https://dev.mysql.com/downloads/file/?id=496745
Una vez dentro de la pagina puede hacer click en "No thanks, just start my download" para empezar la desgarga directamente

![MySQL](https://user-images.githubusercontent.com/28927252/90084787-90933c80-dcd3-11ea-9f55-503480ed25f8.PNG)

Luego siga el proceso normal de instalación.

### GitKraken

Este software se usa para poder clonar el repositorio más facilmente.

Es necesario tener una cuenta de GitHub.

Este se puede descargar en el siguiente enlace: https://www.gitkraken.com/download

![GKD](https://user-images.githubusercontent.com/28927252/90085023-28912600-dcd4-11ea-8b9e-fe7753ab6933.PNG)

Luego siga el proceso normal de instalación.

# Clonación del Repositorio#

Abra GitKraken y dirigase adonde dice "Clone a repo"

![GK1](https://user-images.githubusercontent.com/28927252/90084225-07c7d100-dcd2-11ea-87c5-3cb8e50ca378.PNG)

Una vez en la ventana de clonación seleccione "GitHub.com", eliga la dirreccion en la que quiere que se clone el repositorio y luego elija el repositorio "PROYECTO-III-GOT".

![GK2](https://user-images.githubusercontent.com/28927252/90084229-08606780-dcd2-11ea-82a6-aa2813358008.PNG)
