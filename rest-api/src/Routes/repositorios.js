const express = require('express');
const router = express.Router();

const mysqlConnection = require('../Database');

router.get('/repositorios', (req, res) => {
    mysqlConnection.query('SELECT * FROM repositorios', (err, rows, fields) => {
        if(!err){
            res.json(rows);
        } else {
            console.log(err);
        }
    });
});

router.get('/repositorios/:id', (req, res) => {
    const { id } = req.params;
    mysqlConnection.query('SELECT * FROM repositorios WHERE id = ?', [id], (err, rows, fields) => {
        if(!err){
            res.json(rows[0]);
        } else {
            console.log(err);
            return;
        }
    });
});

router.get('/archivos', (req, res) => {
    mysqlConnection.query('SELECT * FROM archivos', (err, rows, fields) => {
        if(!err){
            res.json(rows);
        } else {
            console.log(err);
        }
    })
});

router.get('/archivos/:id', (req, res) => {
    const { id } = req.params;
    mysqlConnection.query('SELECT * FROM archivos WHERE id = ?', [id], (err, rows, fields) => {
        if(!err){
            res.json(rows[0]);
        } else {
            console.log(err);
            return;
        }
    });
});

router.post('/repositorios', (req, res) => {
    const { id, nombre, arbol, gotignore} = req.body;
    console.log(req.body);
    const query = 'CALL repositoryAddOrEdit(?, ?, ?, ?)';
    mysqlConnection.query(query, [id, nombre, arbol, gotignore], (err, rows, fields) => {
        if(!err) {
            res.json({Status: 'Repositorio guardado'});
        } else {
            console.log(err);
        }
    });
});

router.put('/repositorios/:id', (req, res) => {
    const { nombre, arbol, gotignore } = req.body;
    const { id } = req.params;
    const query = 'CALL repositoryAddOrEdit(?, ?, ?, ?)';
    mysqlConnection.query(query, [id, nombre, arbol, gotignore], (err, row, fields) => {
        if(!err){
            res.json({Status: "Repositorio actualizado"});
        } else {
            console.log(err);
        }
    });
});

router.delete('/repositorios/:id', (req, res) => {
    const { id } = req.params;
    mysqlConnection.query('DELETE FROM repositorios WHERE id = ?', [id], (err, rows, fields) => {
        if(!err) {
            res.json({Status: "Repositorio eliminado"});
        } else {
            console.log(err);
        }
    });
});

module.exports = router;