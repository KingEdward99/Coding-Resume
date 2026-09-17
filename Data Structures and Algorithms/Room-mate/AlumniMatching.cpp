// Alumni Matching 

//Template of creating users
template <typename Character>
class User{
    public:
        string name;
        string major;
        string career; // career title or student
    
        // Constructor for the data
        User(string n, string m, string c)
            : name(n), major(m), career(c) {}
};

//Template of matching students with alumni
template <typename firstUser, typename secondUser>
bool isMatch (const firstUser& student, const secondUser& alumni) {
    return student.major == alumni.major;
};
