const {Sequelize, DataTypes} = require("sequelize");

const sequelize = new Sequelize(
   'student_books',
   'root',
   'Jumpman17!',
    {
      host: 'localhost',
      dialect: 'mysql'
    }
   );

sequelize.authenticate().then(() => {
    console.log('Connection has been established successfully.');
}).catch((error) => {
    console.error('Unable to connect to the database: ', error);
});

sequelize.query(
    'SELECT * FROM students WHERE student_id = ?',
    {
      replacements: ['45d1f26c-ba76-431f-ac5f-f41282351710'],
      type: sequelize.QueryTypes.SELECT
    }
).then(result => {
    console.log(result);
}).catch((error) => {
    console.error('Failed to insert data : ', error);
});