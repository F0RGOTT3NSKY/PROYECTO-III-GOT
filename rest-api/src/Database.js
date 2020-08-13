const mysql = require('mysql');

const mysqlConnection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'Admin123',
    database: 'GOTDB'
});

mysqlConnection.connect(function(err) {
    if(err){
        console.log(err);
        return
    } else {
        console.log('Base de datos conectada exitosamente');
    }
});

module.exports = mysqlConnection;