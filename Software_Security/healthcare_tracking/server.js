const express = require('express');
const cors = require('cors');
const { MongoClient, ServerApiVersion } = require('mongodb');


const app = express();
const healthRoutes = require('./back-end/routes/healthRoutes');
const uri = "mongodb+srv://ekoundjou:Jumpman17@bulldogtech.4jqqrrx.mongodb.net/?retryWrites=true&w=majority&appName=BulldogTech";

// Middleware
app.use(cors()); // Allow cross-origin requests
app.use(express.json()); // Parse JSON request bodies
app.use('/api/health', healthRoutes);

// Create a MongoClient with a MongoClientOptions object to set the Stable API version
const client = new MongoClient(uri, {
  serverApi: {
    version: ServerApiVersion.v1,
    strict: true,
    deprecationErrors: true,
  }
});
async function run() {
  try {
    // Connect the client to the server	(optional starting in v4.7)
    await client.connect();
    // Send a ping to confirm a successful connection
    await client.db("admin").command({ ping: 1 });
    console.log("Pinged your deployment. You successfully connected to MongoDB!");
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}
run().catch(console.dir);
// Your routes go here
app.post('/api/health-data', (req, res) => {
  const { name, age, gender, healthStatus, exposureDate, vaccinationStatus, contactHistory } = req.body;
  console.log('Health Data Received:', req.body);

  res.status(200).send('Health data submitted successfully.');
});

// Start server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
