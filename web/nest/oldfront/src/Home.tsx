import axios from "axios";
import { useState , useEffect} from "react";

function getCookie(name: String) {
  const value = `; ${document.cookie}`;
  const parts = value.split(`; ${name}=`);
  if (parts.length === 2) return parts.pop().split(';').shift();
}

function Input_field({text, value, onChange}){
    return (
      <>
        <input type="text" placeholder={text} value={value} onChange={onChange}/>
      </>
    );
}

function Button({ value, handleClick }){
  return (
    <button className='send_friendship_button' onClick={handleClick}>
      {value}
    </button>
  )
}



function Home({ socket }) {
    const token = getCookie('token');
    const [friend, setFriend] = useState('');
    const [me, setMe] = useState(null);
    const [error, setError] = useState(null);
    const [requestStatus, setRequestStatus] = useState(null);

    useEffect(() => {
      const url_get_me = "http://localhost:3333/users/me";
      axios.get(url_get_me, {
        headers: {
          "Authorization": `Bearer ${token}`
        }
      }).then(response => {
        const user = response.data;
        console.log("Données de l'utilisateur :", user);
        setMe(user);
      }).catch(error => {
        console.error("Erreur lors de la récupération des données de l'utilisateur :", error);
        setError(error.message);
      });
    }, []);
    function send_friendship() {
      const url_request = "http://localhost:3333/friend/request";
      const token = getCookie('token');
      const userData = {
        sender: me.login,
        login: friend,
      };
      axios.post(url_request, userData, {
        headers: {
          "Authorization": `Bearer ${token}`,
        }
      }).then((friend) => {
        setRequestStatus('Demande envoyée');
        console.log('demande envoyée')
      }).catch(() => {
        setRequestStatus('utilisateur introuvable')
        console.log('erreur lors de l envoie de la demande');
      })
      ;
    }
    return (
        <div className='Social'>
          {error ? (
        <p>Une erreur s'est produite : {error}</p>
      ) : me ? (
        <div>
          <h1> Bienvenue {me.login} !</h1>
          <div className='friend_request'>
            <Input_field text='Ajouter un ami' value={friend} onChange={e => setFriend(e.target.value)} />
            <Button value='Envoyer une demande' handleClick={send_friendship} />
            {requestStatus && <p>{requestStatus}</p>} {requestStatus}
          </div>
        </div>
      ) : (
        <p>Chargement en cours...</p>
      )}
        </div>
        
    )
}
export default Home