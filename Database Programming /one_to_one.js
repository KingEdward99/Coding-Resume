const { Sequelize, DataTypes } = require("sequelize");

const sequelize = new Sequelize(
   'student_db',
   'root',
   'Jumpman17!',
    {
      host: 'DATABASE_HOST',
      dialect: 'mysql'
    }
  );

sequelize.authenticate().then(() => {
   console.log('Connection has been established successfully.');
}).catch((error) => {
   console.error('Unable to connect to the database: ', error);
});

const Student = sequelize.define("students", {
   student_id: {
       type: DataTypes.UUID,
       defaultValue: DataTypes.UUIDV4,
       primaryKey: true,
   },
   name: {
       type: DataTypes.STRING,
       allowNull: false
   }
});