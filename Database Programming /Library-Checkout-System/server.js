require("dotenv").config(); // Load environment variables
const express = require("express");
const bodyParser = require("body-parser");
const session = require("express-session");
const bcrypt = require("bcrypt");
const { User } = require("./backend/models"); // Sequelize User model
const { body, validationResult } = require("express-validator");

const app = express();

// Middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("./frontend")); // Serve static files

// Set up sessions securely
app.use(session({
  secret: process.env.SESSION_SECRET || '085gbjgd568%%$dS', // Default only for development
  resave: false,
  saveUninitialized: true,
  cookie: { secure: process.env.NODE_ENV === 'production', httpOnly: true } // Secure cookie in production
}));

// REGISTER ROUTE
app.post("/register", 
  // Input validation and sanitization
  [
    body("username").trim().notEmpty().withMessage("Username is required"),
    body("password").isLength({ min: 6 }).withMessage("Password must be at least 6 characters long"),
  ],
  async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).json({ errors: errors.array() });
    }

    const { username, password } = req.body;

    try {
      // Check if user already exists
      const existingUser = await User.findOne({ where: { username } });
      if (existingUser) {
        return res.status(400).send("Username already exists.");
      }

      // Hash password before saving
      const hashedPassword = await bcrypt.hash(password, 10);

      // Create new user
      await User.create({ username, password: hashedPassword });

      res.redirect("./frontend/login.html");
    } catch (err) {
      console.error("Error during registration:", err.message);
      res.status(500).send("Registration failed. Please try again later.");
    }
  }
);

// LOGIN ROUTE
app.post("/login", 
  [
    body("username").trim().notEmpty().withMessage("Username is required"),
    body("password").notEmpty().withMessage("Password is required"),
  ],
  async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).json({ errors: errors.array() });
    }

    const { username, password } = req.body;

    try {
      const user = await User.findOne({ where: { username } });

      if (!user) {
        return res.status(400).send("Incorrect username or password.");
      }

      const isMatch = await bcrypt.compare(password, user.password);
      if (!isMatch) {
        return res.status(401).send("Incorrect username or password.");
      }

      // Store session on successful login
      req.session.user = user.username;
      res.redirect("/dashboard");
    } catch (err) {
      console.error("Error during login:", err.message);
      res.status(500).send("Login failed. Please try again later.");
    }
  }
);

// DASHBOARD ROUTE
app.get('/dashboard', (req, res) => {
  if (!req.session.user) {
    return res.redirect('/login.html'); // Redirect to login page
  }
  res.sendFile(__dirname + '/frontend/dashboard.html');
});

// GET USER SESSION DATA
app.get('/get-user', (req, res) => {
  if (req.session.user) {
    return res.json({ username: req.session.user });
  }
  return res.status(401).json({ username: null });
});

// LOGOUT ROUTE
app.post("/logout", (req, res) => {
  req.session.destroy((err) => {
    if (err) {
      console.error("Logout error:", err.message);
      return res.status(500).send("Could not log out.");
    }
    res.redirect("/login.html");
  });
});

// START SERVER
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});
