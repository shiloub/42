import "../styles/PlantItem.css"
import CareScale from './CareScale'

interface PlantItemProps {
    name: string,
    cover: any,
    id: string,
    light: number,
    water: number,
    price: number,
}
export default function PlantItem({name, cover, id, light, water, price}: PlantItemProps) {
    function handleClick(type: string, scaleValue: number){
        const intensity = scaleValue === 1 ? 'peu' : scaleValue === 2 ? 'modérément' : scaleValue === 3 ? 'beaucoup' : 'undefined';
        const elem = type === 'sun' ? 'de lumière' : "d'eau";
        const alert_string = "Cette plante requiert " + intensity + " " + elem;
        alert(alert_string);

    }
    return (
        <>
            <li key={id} className='lmj_plant_item'>
                <img className='lmj_plant_item_cover' src={cover} alt={`${name} cover`} />
                {name}
                <div>
                    prix: {price}€
                    <CareScale scaleValue={light} type='sun' onClick={handleClick}/>
                    <CareScale scaleValue={water} type='water' onClick={handleClick}/>
                </div>
            </li>
        </>
    )

}