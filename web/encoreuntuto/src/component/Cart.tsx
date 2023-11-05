import { useEffect, useState } from "react"
import "../styles/cart.css"


function getTotal(tab: any[]){
  let count = 0;

  tab.map((plant: any) => {
    return (count += plant.price);
  }
  )
  console.log(count);
  return count;

}
export default function Cart({cart, emptyCart, deletePlant}:{cart:any, emptyCart: any, deletePlant:any}) {

    const total = getTotal(cart);
    const [isOpen, setIsOpen] = useState(false);
    useEffect(() => {
      if (total !== 0)
        document.title = (`LMJ panier: ${total}€`);
    }, [total]);
    return (
      isOpen ? (
        <div className="lmj_cart">
          <button className="lmj_cart_toggle_button" onClick={() => setIsOpen(false)}>Fermer</button>
            <h2>Panier</h2>
            <ul>
              {cart.map((plant: any, index:number) => (
                <div key={index}>
                  <li key={index}>{plant.name} : {plant.price}€ <button onClick={() => {deletePlant(index)}}>X</button></li>
                  {/* <button onClick={() => {deletePlant(index)}}>Supprimer</button> */}
                </div>
              ))
        }
            </ul>
            <h3>Total : {getTotal(cart)}€</h3>
            <button onClick={() => {emptyCart()}}>Vider</button>
        </div>
      ) : (
        <div className="lmj_cart_closed">
            <button onClick={() => setIsOpen(true)}>panier</button>
        </div>
      )
      )
    }