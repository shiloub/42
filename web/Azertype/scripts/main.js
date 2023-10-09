// let intput_field = document.getElementById("inputEcriture");
// let validation_button = document.getElementById("btnValiderMot");
// let to_type_word = document.querySelector(".zoneProposition");
// let score = document.getElementById("score");
// let button_list = document.querySelectorAll(".zoneOption input");
// console.log(intput_field);
// console.log(validation_button);
// console.log(to_type_word);
// console.log(score);
// console.log(button_list);

// let titre_site = "AZEERTYPE";

// let h1 = document.createElement("h1");
// h1.innerText = titre_site;
// let body = document.querySelector("body");
// body.appendChild(h1);

// launch_game(wordlist, sentencelist);
let black = 0;
let h = 0;
let button = document.getElementById("boutton");
button.addEventListener("click", function() {
    if (!black) {
        button.classList.add("clic");
        black = true;
    }
    else
    {
        button.classList.remove("clic");
        black = false;
    }
})


document.addEventListener('keypress', (event) => {
    if (event.key === 'h' && !h)
    {
        h = 1;
        let to_add = document.createElement("div");
        to_add.innerHTML = `<p>salut merci d'avoir cliqué</p>`;
        let aside = document.querySelector("aside");
        aside.appendChild(to_add);
    }
})

launch_game();
