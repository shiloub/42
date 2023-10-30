import { useState , useEffect} from 'react';
import Auth_field from './Auth'
import Home from './Home'
import './App.css';
import io from 'socket.io-client';

function getCookie(name: String) {
  const value = `; ${document.cookie}`;
  const parts = value.split(`; ${name}=`);
  if (parts.length === 2) return parts.pop().split(';').shift();
}



function App() {
  const [isLogin, setIsLogin] = useState(false);
  const [socket, setSocket] = useState(null);
  function handleLogin(){
    setIsLogin(true);
    
  }
  useEffect(() => {
    const socket = io('http://localhost:3333');
    setSocket(socket);
    socket.on('notification', (data) => {
      console.log('nouvelle notif :', data);
    })

    return () => {
      socket.disconnect();
    };
  }, []);

  function handleMessage(){
    console.log('nouveau message recu !');
  }
  return (
    <>
      <h1>TRANSCENDANCE</h1>
      <main>
        <div className='app'>
          {!isLogin ? (<Auth_field onLogin={() => handleLogin()} socket={socket}/>)
            : (<Home socket={socket}/>)
          }
        </div>
      </main>
    </>
  );
}

export default App;
