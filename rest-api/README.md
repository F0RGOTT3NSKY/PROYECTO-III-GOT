# Documentacion REST Api

## index.js

Este archivo configura al servidor, sus requerimientos, puertos o lo que sea necesario.

## Database.js

### Variables:

* mysql: Esta variable permite instanciar el requerimiento para mysql.

* mysqlConnection: Esta variable almacena los datos del servidor como el host, user, entre otros.

### Métodos:

* connect(): Con este método integrado, permite establecer una conexióne entre el api y la base de datos.

## repositorios.js

### Variables:

* express: Esta variable permite establecer el requerimiento para express.

* router: Este es un constructor propio de express para poder crear rutas.

* mysqlConnection: Variable que permite obtener el requerimiento de la base de datos.

### Métodos o rutas

* get('/get'): Esta ruta permite hacer un intento de conexión entre el cliente y el servidor.

* get('/repositorios'): Esta ruta permite obtener todos los repositorios creados en la base de datos.

* get('/repositorios/:id'): Esta ruta permite obtener un repositorio en específico utilizando su id, si no está, la consola muestra error.

* get('/archivos'): Esta ruta permite obtener todos los archivos guardados en la base de datos.

* get('/archivos/:id'): Esta ruta permite obtener un archivo en específico con su id, si no existe, la consolota muestra el error.

* post('/repositorios'): Esta ruta permite crear un nuevo repositorio en la base de datos utilizando un método propio de la base de datos consultando si este ya existe o no. Devuelve el status en la consoloa.

* put('/repositorios'): Esta ruta permite crear un nuevo repositorio en la base de datos utilizado un método propo de la base de datos si este existe para actualizarlo o no. Devuelve el status en la consola.

* delete('/repositorios/:id'): Esta ruta permite eliminar un repositorio utilizando su id y un query donde se escribe el comando en formato de sql para que la base de datos pueda ejecutarlo sin algún problema.

* post('/archivos/commit'): Esta ruta permite crear un nuevo archivo en la base de datos y, al igual que los repositorios, utiliza un método propio de la base de datos consultando si este existe o no, de no serlo, lo crea, de lo contrario se actualiza con la información brindada por el cliente.