const {Sequelize, DataTypes} = require("sequelize");

const sequelize = new Sequelize(
   'student_books',
   'root',
   '--',
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
const Grade = sequelize.define("grades", {
   grade: {
       type: DataTypes.INTEGER,
       allowNull: false
   }
});

const grade_data = [ {grade : 9}, {grade : 10}, {grade : 11}]

const student_data = [
   {name : "John Baker", gradeId: 2},
   {name : "Max Butler", gradeId: 1},
   {name : "Ryan Fisher", gradeId: 3},
   {name : "Robert Gray", gradeId: 2},
   {name : "Sam Lewis", gradeId: 1}
]

// One-To-Many relationship
Grade.hasMany(Student);

sequelize.sync({ force: true }).then(() => {
   Grade.bulkCreate(grade_data, { validate: true }).then(() => {
       Student.bulkCreate(student_data, { validate: true }).then(() => {
           Grade.findAll({
               where: {
                   grade: 9
               },
               include: [{
                   model: Student
               }]
           }).then(result => {
               console.dir(result, { depth: 5 });
           }).catch((error) => {
               console.error('Failed to retrieve data : ', error);
           });
       }).catch((err) => { console.log(err); });
   }).catch((err) => { console.log(err); });
}).catch((error) => {
   console.error('Unable to create table : ', error);
});