const Sequelize = require("sequelize");
const sequelize = new Sequelize(
  'DATABASE_NAME',
  'DATABASE_USERNAME',
  'DATABASE_PASSWORD',
   {
     host: 'HOST_NAME',
     dialect: 'mysql'
   }
  );

sequelize.authenticate().then(() => {
    console.log('Connection has been established successfully.');
 }).catch((error) => {
    console.error('Unable to connect to the database: ', error);
 });

 sequelize.query(
  'SELECT * FROM students WHERE student_id = :id',
  {
    replacements: { id: 'd0fcf846-df00-40aa-b236-5dca1621b35b' },
    type: sequelize.QueryTypes.SELECT
  }
 ).then(result => {
    console.log(result);
}).catch((error) => {
    console.error('Failed to insert data : ', error);
});