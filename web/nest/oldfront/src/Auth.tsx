import axios from "axios";
import { useState } from "react";
import io from 'socket.io-client';
import Cookies from 'js-cookie'

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
  function AddTokenCookie( token : string){
    Cookies.set('token', token, {expires: 7});
  }
  
  
  function Auth_field({ onLogin , socket }){
    const [pseudo, setPseudo] = useState('');
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
  
    function signin(){
      const url_signin = "http://localhost:3333/auth/signin"
      const userData = {
        email: email,
        login: pseudo,
        password: password,
      }
      axios.post(url_signin, userData)
      .then (function (reponse) {
        AddTokenCookie(reponse.data.access_token);
        onLogin();
        if (socket) {
          socket.emit('authenticate', { token:  reponse.data.access_token, email: email});
        }
      })
      .catch (function(error) {
        console.error('erreur de signin : ', error);
      });
    }
    async function signup(){
      const url_signup = "http://localhost:3333/auth/signup"
      const userData = {
        email: email,
        login: pseudo,
        password: password,
      }
      axios.post(url_signup, userData)
        .then(function (response) {
        console.log('Réponse du serveur :', response.data);
      })
        .catch(function (error) {
          console.error('erreur de la requete :', error);
        });
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

  export default Auth_field