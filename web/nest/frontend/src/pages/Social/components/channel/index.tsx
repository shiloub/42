import { useEffect, useState } from "react"
import ChanZone from "./chanZone";
import DirectZone from "./directZone";
import "./chanZone.css"

function Button({value, handleClick}) {
    return (
        <button onClick={handleClick}>{value}</button>
    )
}

export default function Channels({handleSelect, login, currentChan, socket}){
    const [chanBool, setChanBool] = useState(true);

    useEffect(() => {
        const kickHandler = () => {
            console.log("je me suis fait kicked !!!!");
            handleSelect(null);
          }
      
        socket.on('kicked', kickHandler);
      
        return () => {
          socket.off('message', kickHandler);
        };
      }, [socket, handleSelect]);

    return (
        <div className="chanZone">
            <Button value="Channels" handleClick={() => setChanBool(true)}/>
            <Button value="Direct chat" handleClick={() => setChanBool(false)} />
            {chanBool? <ChanZone handleSelect={handleSelect} login={login} currentChan={currentChan}/> : <DirectZone handleSelect={handleSelect} login={login}/>}
        </div>
    )
}