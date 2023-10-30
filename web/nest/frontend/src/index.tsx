import React from 'react';
import ReactDOM from 'react-dom/client';
import Home from './pages/Home';
import {BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Social from './pages/Social';
import Game from './pages/Game';
import Header from './components/Header';


const root = ReactDOM.createRoot(
  document.getElementById('root') as HTMLElement
);
root.render(
  <React.StrictMode>
    <Router>
      <Header />
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/social" element={<Social/>} />
        <Route path="/game" element={<Game/>} />
      </Routes>
    </Router>
  </React.StrictMode>,
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
