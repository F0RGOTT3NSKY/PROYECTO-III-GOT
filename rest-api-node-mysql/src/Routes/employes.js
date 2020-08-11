const express = require('express');
const router = express.Router();
const mysqlConnection = require('../Database');

// GET ALL DATA
router.get('/', (req, res) => {
    mysqlConnection.query('SELECT * FROM employees', (err, rows, fields) => {
        if(!err){
            res.json(rows);
        } else {
            console.log(err);
            return;
        }
    });
});

// GET SPECIFIC DATA
router.get('/:id', (req, res) => {
    const { id } = req.params;
    mysqlConnection.query('SELECT * FROM employees WHERE id = ?', [id],(err, rows, fields) => {
        if(!err){
            res.json(rows);
        } else {
            console.log(err);
            return;
        }
    });
});

// CREATE NEW DATA
router.post('/', (req, res) =>{
    const { id, name, salary} = req.body;
    const query = `
        CALL employeeAddOrEdit(?, ?, ?);
    `;
    mysqlConnection.query(query, [id, name, salary], (err, rows, fields) => {
        if(!err){
            res.json({Status: 'Employee added'});
        } else {
            console.log(err);
        }
    });
});

// UPDATE SPECIFIC DATA
router.put('/:id', (req, res) =>{
    const { name, salary} = req.body;
    const { id } = req.params;
    const query = 'CALL employeeAddOrEdit(?, ?, ?)';
    mysqlConnection.query(query, [id, name, salary], (err, rows, fields) => {
        if(!err){
            res.json({Status: "Employee Updated"});
        } else {
            console.log(err);
        }
    });
});

// DELETE DATA
router.delete('/:id', (req, res) => {
    const { id } = req.params;
    mysqlConnection.query('DELETE FROM employees WHERE id = ?', [id], (err, rows, fields) => {
        if(!err){
            res.json({Status: "Employee deleted"});
        } else {
            console.log(err);
        }
    });
});

module.exports = router;