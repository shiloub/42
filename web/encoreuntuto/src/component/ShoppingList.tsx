import { useState } from 'react';
import { plantList }  from '../datas/plantList'
import "../styles/shoppingList.css"
import Categories from './Categories';
import PlantItem from './PlantItem';


export default function ShoppingList({addCart, cart}: {addCart:any, cart:any}) {
    const [categorie, setCategorie] = useState('all')
    const categories = plantList.reduce((acc: string[], plant) => {
        if (!acc.includes(plant.category))
            acc.push(plant.category);
        return (acc);
    }, []);
    return (
        <div className='shopping'>
            <Categories categories={categories} handleSelect={setCategorie}/>
            <ul className='lmj_plant_list'>
                {plantList.map(({name, id, cover, light, water, price, category}, index) => (
                    (categorie === category || categorie === 'all') && (
                    <div key={id + index}>
                        <PlantItem key={id} name={name} id={id} cover={cover} water={water} light={light} price={price}/>
                        <button onClick={()=> addCart({name, price})}>Ajouter</button>
                    </div>
                    )
                ))} 
            </ul>
        </div>

    )
}