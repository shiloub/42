import Banner from './Banner';
import Cart from './Cart';
import ShoppingList from './ShoppingList';
import logo from '../assets/logo.png'
import Footer from './Footer';
import { useEffect, useState } from 'react';
import "../styles/layout.css"

interface plant {
    price: number,
    name: string,
}

function App() {
    const savedCart = localStorage.getItem("cart");
    const [cart, setCart] = useState<plant[]>(savedCart ? JSON.parse(savedCart) : []);
    useEffect (() => {
        localStorage.setItem("cart", JSON.stringify(cart))
    }, [cart])

    function addPlant(plant: plant) {
        setCart([...cart, plant]);
    }
    function deleteAll() {
        setCart([]);
    }
    function deletePlant(index: number){
        const copy=[...cart];
        copy.splice(index, 1);
        setCart(copy);
    }

 return (
    <>
        <Banner>
            <img src={logo} alt='La maison jungle' className='lmj-logo' />
			<h1 className='lmj-title'>La maison jungle</h1>
        </Banner>
        <div className='layout_inner'>
            <Cart cart={cart} emptyCart={deleteAll} deletePlant={deletePlant}/>
            <ShoppingList cart={cart} addCart={addPlant}/>

        </div>
        <Footer />
    </>
 )
}

export default App;
