import axios from "axios";
import { useEffect, useState } from "react"
import "../channel/form.css"


function SelectDefault({defaultUsers, setSelected}) {
    return (
        <select name="witchUser" onChange={(e) => setSelected(e.target.value)}>
            <option value="">Sélectionnez un utilisateur</option>
            {defaultUsers.map((user: any) => (
                <option key={user.id} value={user.login}>{user.login}</option>
            ))}
        </select>
    )
}

function SelectAll({users, setSelected}) {
    return (
        <select name="witchUser" onChange={(e) => setSelected(e.target.value)}>
            <option value="">Sélectionnez un utilisateur</option>
            {users.map((user: any) => (
                <option key={user.id} value={user.login}>{user.login}</option>
            ))}
        </select>
    )
}

export default function SettingForm({role, handleLeave, handleDelete, channel}){
    const [password, setPassword] = useState('');
    const [invited, setInvited] = useState('');
    const [defaultUsers, setDefaultUsers] = useState([]);
    const [users, setUsers] = useState([]);
    const [selectedUserDefault, setSelectedUserDefault] = useState('');
    const [selectedUser, setSelectedUser] = useState('');

    useEffect (() => {
        const url_default = "http://localhost:3001/channel/default?name=" + channel.name;
        axios.get(url_default, {withCredentials: true}).then((reponse) =>{
            if (reponse.data.users)
                setDefaultUsers(reponse.data.users);
            else
                console.log(reponse.data.error);
        })

        const url_all = "http://localhost:3001/channel/all?name=" + channel.name;
        axios.get(url_all, {withCredentials: true}).then((reponse) =>{
            if (reponse.data.users)
                setUsers(reponse.data.users);
            else
                console.log(reponse.data.error);
        })


    }, [channel])

    function handlepswDelete() {
        const url = "http://localhost:3001/channel/setPassword";
        const data = {
            name: channel.name,
            password: ""
        }

        axios.post(url, data, {withCredentials: true})
        .then(() => {
            console.log("password succesfully deleted");
        })
        
    }

    function handlepswSet() {
        const url = "http://localhost:3001/channel/setPassword";
        const data = {
            name: channel.name,
            password: password
        }

        axios.post(url, data, {withCredentials: true})
        .then(() => {
            console.log("password succesfully changed");
        })
        
    }

    function handleSetAdmin() {
        if (selectedUserDefault !== ''){
            const url = "http://localhost:3001/channel/setAdmin";
            const data = {
                login: selectedUserDefault,
                name: channel.name,
            }
            console.log(data);

            axios.post(url, data, {withCredentials: true})
            .then(() => {
                console.log("admin ajouté");
            })
            .catch(() => {
                console.log("erreur lors de l'ajout d'admin");
            })
        }
    }

    function handleKick(){
        const url = "http://localhost:3001/channel/kick";
        const data = {
            login: selectedUser,
            name: channel.name,
        }

        console.log(data);
        axios.post(url, data, {withCredentials: true})
        .then(() => {
        })
        .catch(() => {
            console.log("erreur durant le leave");
        })
    }

    function handleBan(){
        const url = "http://localhost:3001/channel/ban";
        const data = {
            login: selectedUser,
            name: channel.name,
        }

        console.log(data);
        axios.post(url, data, {withCredentials: true})
        .then(() => {
        })
        .catch(() => {
            console.log("erreur durant le ban");
        })
    }

    function handleInvite() {
        const url = "http://localhost:3001/channel/invite";
        const data = {
            login: invited,
            name: channel.name,
        }
        axios.post(url, data, {withCredentials: true})
        .then(() => {
        })
        .catch(() => {
            console.log("erreur durant le mute");
        })
    }

    function handleMute(){
        const url = "http://localhost:3001/channel/mute";
        const data = {
            login: selectedUser,
            name: channel.name,
        }

        axios.post(url, data, {withCredentials: true})
        .then(() => {
        })
        .catch(() => {
            console.log("erreur durant le mute");
        })
    }



    return (
        <div className="form">
            <div>
                <button onClick={handleLeave}>Leave</button>
                {role === 'OWNER' && <button onClick={handleDelete}>Delete</button>}
            </div>
            {role === 'OWNER' && 
            <div>
                <input type="text" placeholder="new password" value={password} onChange={(e) => setPassword(e.target.value)}/>
                <button onClick={() => handlepswSet()}>Change</button>
                <button onClick={() =>handlepswDelete()}>Delete</button>
            </div>}
            {channel.type === 'PRIVATE' &&
            <div>
                <input type="text" placeholder="target" value={invited} onChange={(e) => setInvited(e.target.value)} />
                <button onClick={() => handleInvite()}>invite</button>

            </div>}
            {(role === 'OWNER' || role === 'ADMIN') &&
            <div>
                {defaultUsers.length !== 0 &&
                <div>
                    <SelectDefault defaultUsers={defaultUsers} setSelected={setSelectedUserDefault}/>
                    <button onClick={handleSetAdmin}>Set admin</button>
                </div>}
                {users.length !== 0 &&
                <div>
                <SelectAll users={users} setSelected={setSelectedUser}/>
                <button onClick={handleKick}>Kick</button>
                <button onClick={handleBan}>Ban</button>
                <button onClick={handleMute}>Mute</button>
                </div>}
            </div>}


        </div>
    )
}