export default function Categories({categories, handleSelect}:{categories: string[], handleSelect: any}) {
    function handleChange(event: any) {
        handleSelect(event.target.value);
    }
    return (
        <div>
            Catégorie de plante<br/>
            <select name="Category" defaultValue="all" onChange={handleChange}>
                {categories.map((categorie, index) => (
                     <option key={categorie + index} value={categorie}>{categorie}</option>
                ))}
                <option value='all'>toutes</option>
            </select>
        </div>
    )
}