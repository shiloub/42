import './social.css'
import Channels from './components/channel'
import Chat from './components/chat'
import Friends from './components/friends'
import { useEffect, useState } from 'react'
import { io } from 'socket.io-client'
import axios from 'axios'


export default function Social() {
    const [currentChan, setCurrentChan] = useState(null);
    const [input, setInput] = useState('');
    const [login, setLogin] = useState('');
    const [socket, setSocket] = useState(null);
    const [blockeds, setBlocked] = useState([]);


    useEffect(() => {
        const url_blocked = "http://localhost:3333/users/blocked?login=" + login;
        axios.get(url_blocked)
        .then((response) => {
            if (response.data.users) {
                // console.log("blocked : ", response.data.users);
                setBlocked(response.data.users);
            }
            else
                console.log(response.data.error);
        })
    })

    function handleBlock(user: string) {
        const temp = [...blockeds];
        temp.push(user);
        console.log("je suis jusque la = je bloque :" , user);
        setBlocked(temp);
    }

    function handleUnblock(user: string) {
        const temp = [...blockeds];
        const temp2 = temp.filter((userLogin) => userLogin !== user);
        console.log("je suis jusque la = je debloque total");
        setBlocked(temp2);
    }

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
                <Chat channel={currentChan} login={login} socket={socket} handleLeave={handleLeave} handleDelete={handleDelete} blockeds={blockeds}/>
                <Friends login={login} blockeds={blockeds} handleBlock={handleBlock} handleUnblock={handleUnblock}/>
            </div> }
        </div>
    )
}