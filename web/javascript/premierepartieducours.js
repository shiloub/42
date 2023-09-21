//declaration de variable

let n = 8;
let ticket = {
    prix: 8,
    nomFilm: "salut"
}
ticket.ajouterVariable = 7;

//tableaux
//const maCollectionDeFilms = ["Titanic", "Jurassic Park", "Le Seigneur des Anneaux"]

const monFilmPrefere = "Titanic"
const monPremierFilm = "Le Seigneur des Anneaux"

let maCollectionDeFilms = [monFilmPrefere, monPremierFilm];
const film_nb = maCollectionDeFilms.length;
 //methodes
maCollectionDeFilms.push("fatal");
maCollectionDeFilms.pop();

//copie par reference ; let compexe2 = [...complexe1];
// maCollectionDeFilms vaut ["Titanic", "Le Seigneur des Anneaux"]
