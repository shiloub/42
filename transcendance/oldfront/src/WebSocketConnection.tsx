import React, { useEffect, useState } from 'react';
import io from 'socket.io-client';

function WebSocketConnection({ onMessage }) {
  const [socket, setSocket] = useState(null);

  useEffect(() => {
    const socket = io('http://localhost:3333'); // Remplacez l'URL par l'URL de votre serveur WebSocket

    socket.on('connect', () => {
      console.log('Connected to WebSocket server');
    });

    socket.on('onMessage', (data) => {
      onMessage(data);
    });

    setSocket(socket);

    return () => {
      socket.disconnect();
    };
  }, [onMessage]);

  return <div></div>;
}

export default WebSocketConnection;