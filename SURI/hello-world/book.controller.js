const { Sequelize, DataTypes } = require("sequelize");

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

 const Book = sequelize.define("books", {
    title: {
      type: DataTypes.STRING,
      allowNull: false
    },
    author: {
      type: DataTypes.STRING,
      allowNull: false
    },
    release_date: {
      type: DataTypes.DATEONLY,
    },
    subject: {
      type: DataTypes.INTEGER,
    }
 });

 sequelize.sync().then(() => {
    console.log('Book table created successfully!');

    Book.destroy({
      where: {
        id: 2
      }
  }).then(() => {
      console.log("Successfully deleted record.")
  }).catch((error) => {
      console.error('Failed to delete record : ', error);
  });
 }).catch((error) => {
    console.error('Unable to create table : ', error);
 });