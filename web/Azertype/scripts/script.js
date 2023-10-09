// let to_type = "banana";
// let buffer = prompt("To type : " + to_type + " :");
// switch (buffer) {
//     case to_type:
//         console.log("Bravo !")
//         break
//     case "Gredin":
//         console.log("Restez correct !")
//         break
//     case "Mécréant":
//         console.log("Restez correct !")
//         break
//     case "Vilain":
//         console.log("Soyez gentil !")
//         break
//     default:
//         console.log("Vous avez fait une erreur de frappe.")
// }
function print_result(score, tries)
{
    let tmp = "score de " + score + "/" + tries + " !";
    let _score = document.getElementById("score");
    _score.innerText = tmp;

}
function choose_option(buffer)
{
    if (buffer === "mots")
        return 1;
    if (buffer === "phrases")
        return 2;
    return 0;
}

function print_proposition(to_type)
{
    let type_prop = document.querySelector(".zoneProposition");
    type_prop.innerText = to_type;
}

function get_props()
{
    let score = 0;
    let i = 0;
    let envoyer = document.getElementById("btnValiderMot");
    let tmp;
    let input = document.getElementById("inputEcriture");
    envoyer.addEventListener("click", (event)=> {
        if (i < listprop.length){
            console.log("j'envoie");
            tmp = input.value;
            if (tmp === listprop[i])
                score ++;
            input.value = "";
            i++;
            print_result(score, i);
            if (i === listprop.length)
            {
                print_proposition("Le jeu est fini !");
                envoyer.disabled = true;
            }
            else
            {
                print_proposition(wordlist[i]);
                input.focus();
            }
        }
    })
    document.addEventListener("keypress", (event)=> {
        if (event.key !== "Enter")
            return ;
        if (i < listprop.length){
            console.log("j'envoie");
            tmp = input.value;
            if (tmp === listprop[i])
                score ++;
            input.value = "";
            i++;
            print_result(score, i);
            if (i === listprop.length)
            {
                print_proposition("Le jeu est fini !");
                envoyer.disabled = true;
            }
            else
            {
                print_proposition(listprop[i]);
                input.focus();
            }
        }
    })
}

let listprop = wordlist;
function launch_game()
{
    let buffer = "salut";
    let score = 0;
    let i = 0;
    print_proposition(listprop[0]);
    let listradio = document.querySelectorAll(".optionSource input");
    for (let i=0; i<listradio.length; i++){
        listradio[i].addEventListener("change", ()=> {
            if (listradio[i].value === "1")
                listprop = wordlist
            else
                listprop = sentencelist;
        })
    }
    get_props();
    // print_result(score, 3);
}