
function print_score(score, tries)
{
    let tmp = "score de " + score + "/" + tries + " !";
    let _score = document.getElementById("score");
    _score.innerText = tmp;

}

function print_proposition(to_type)
{
    let type_prop = document.querySelector(".zoneProposition");
    type_prop.innerText = to_type;
}

function launch_game()
{
    let listprop = wordlist;
    let i = 0;
    let score = 0;

    waitpopup();
    let envoyer = document.getElementById("btnValiderMot");
    let input = document.getElementById("inputEcriture");
    print_proposition(listprop[0]);
    envoyer.addEventListener("click", (event)=> {
        if (input.value === listprop[i])
            score ++;
        i++;
        print_proposition(listprop[i]);
        print_score(score, i);
        if (i >= listprop.length)
        {
            envoyer.disabled = true;
            print_proposition("Le jeu est fini");
        }
        input.value = "";
        input.focus();
    })
    let radiolist = document.querySelectorAll(".zoneOption input");
    for (let j = 0; j < radiolist.length; j++){
        radiolist[j].addEventListener("change", (event) => {
            if (radiolist[j].value === "1")
                listprop = wordlist;
            else
                listprop = sentencelist;
            print_proposition(listprop[i]);
            input.focus();
        })
    }
}