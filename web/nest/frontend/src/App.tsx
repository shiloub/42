import { useState } from 'react';
import axios from 'axios';
import './App.css';

function Input_field({text, value, onChange}){
  return (
    <>
      <input type="text" placeholder={text} value={value} onChange={onChange}/>
    </>
  );
}

function Button({ value, handleClick })
{
  return (
    <button className='connection_button' onClick={handleClick}>
      {value}
    </button>
  )
}


function Auth_field(){
  const [pseudo, setPseudo] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');

  function signin(){
    const userData = {
      email: email,
      pseudo: pseudo,
      password: password,
    }
    console.log('signin', pseudo, email, password);
    axios.post('')
  }
  function signup(){
    console.log('signup', pseudo, email, password);
  }

  return (
    <div className='auth_field'>
      <div className='pseudo_field'>
        <Input_field text="pseudo" value={pseudo} onChange={(e) => setPseudo(e.target.value)}/>
      </div>
      <div className='email_field'>
        <Input_field text="email" value={email} onChange={(e) => setEmail(e.target.value)}/>
      </div>
      <div className='password_field'>
        <Input_field text="password" value={password} onChange={(e) => setPassword(e.target.value)}/>
      </div>
      <div className='auth_selection'>
        <Button value={"Login"} handleClick={() => signin()}/>
        <Button value={"Signup"} handleClick={() => signup()}/>
      </div>
    </div>
  );
}

function App() {
  return (
    <>
      <h1>TRANSCENDANCE</h1>
      <main>
        <div className='app'>
          <Auth_field />
        </div>
      </main>
    </>
  );
}

export default App;
