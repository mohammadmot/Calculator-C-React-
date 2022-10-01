import React from 'react'
import logo from './logo.svg';
import './App.css';

import Calculator from './Calculator';
import CalculatorApi from './CalculatorApi';

function App() {
  return (
    <div className="App">
      <header className="App-header">
         
        <Calculator CalculatorApi={new CalculatorApi('http://31.7.67.227:3002')} />
        
      </header>
    </div>
  );
}

export default App;
