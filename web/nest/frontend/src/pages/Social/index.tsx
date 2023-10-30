import './social.css'
import Channels from './components/channel'
import Chat from './components/chat'
import Friends from './components/friends'
import { useState } from 'react'
import { io } from 'socket.io-client'
import axios from 'axios'


export default function Social() {
    const [currentChan, setCurrentChan] = useState(null);
    const [input, setInput] = useState('');
    const [login, setLogin] = useState('');
    const [socket, setSocket] = useState(null);

    function handleLogin (){
        console.log('je crée une co socket !');
        const newsocket = io('http://localhost:3333', {
            query: {
                login:input
            }
        });
        setSocket(newsocket);
        setLogin(input);
    }

    function handleLeave() {
        const url = "http://localhost:3333/channel/leave";
        const data = {
            login: login,
            name: currentChan.name,
        }
        axios.post(url, data)
        .then(() => {
            setCurrentChan(null);
        })
        .catch(() => {
            console.log("erreur durant le leave");
        })
    }

    function handleDelete() {
        const url = "http://localhost:3333/channel/delete";
        const data = {
            name: currentChan.name,
        }
        axios.post(url, data)
        .then(() => {
            setCurrentChan(null);
        })
        .catch(() => {
            console.log("erreur durant le delete");
        })
    }
    function selectChan(channel: any){
        setCurrentChan(channel);
    }
    return (
        <div>
            <input type="text" placeholder="login" value={input} onChange={(e) => setInput(e.target.value)} />
            <button onClick={() => handleLogin()}>login</button>
            {login !== '' && <div className="social">
                <Channels handleSelect={(channel: any) => selectChan(channel)} login={login} currentChan={currentChan} socket={socket}/>
                <Chat channel={currentChan} login={login} socket={socket} handleLeave={handleLeave} handleDelete={handleDelete}/>
                <Friends />
            </div> }
        </div>
    )
}