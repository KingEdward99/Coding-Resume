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