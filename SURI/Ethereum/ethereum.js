const Web3 = require('web3')
const rpcURL = 'https://app.infura.io/key/2585defde39a4d0e93c4e95bdfe8ea0c' // Your RPC URL goes here
const web3 = new Web3(rpcURL)
const address = '0x90e63c3d53E0Ea496845b7a03ec7548B70014A91' // Your account address goes here
Web3.eth.getBalance(address, (err, wei) => {
  balance = web3.utils.fromWei(wei, 'ether')
})