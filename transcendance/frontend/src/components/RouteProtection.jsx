import React, { useEffect, useState } from 'react';
import { Navigate } from 'react-router-dom'
import axios from 'axios';

const RouteProtection = (props) => {

    const [isAuthenticated, setIsAuthenticated] = useState(null);

    useEffect(() => {

        const checkAuthentication = async () => {

            try {
                await axios.get('http://localhost:3001/auth/check_auth_cookie', { withCredentials: true });
				await axios.get('http://localhost:3001/auth/check_2fa_cookie', { withCredentials: true });
				setIsAuthenticated(true);
            } catch (error) {
                console.log("RouteProtection : route interdite");
                setIsAuthenticated(false);
            }

        };

        checkAuthentication();
    }, []);

    if (isAuthenticated === null) {
        return <p>Vérification en cours...</p>;  // Affiche un message pendant la vérification
    }

	if (isAuthenticated)
		return props.children;

	else
		return <Navigate to="/login" replace /> 

}

export default RouteProtection;
