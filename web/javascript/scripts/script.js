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
    console.log("score de " + score + "/" + tries + " !");
}
function choose_option(buffer)
{
    if (buffer === "mots")
        return 1;
    if (buffer === "phrases")
        return 2;
    return 0;
}
function launch_game(wordlist, sentencelist)
{
    let buffer = "";
    let to_type = "";
    let score = 0;
    let mode = 0;
    
    for (let i = 0; i < 3; i++)
    {
        while (mode === 0)
        {
            buffer = prompt("choisis un mode : mots ou phrases ?");
            mode = choose_option(buffer);
        }
        if (mode === 1)
            to_type = wordlist[i];
        else
            to_type = sentencelist[i];
        buffer = prompt(to_type + " :");
        if (buffer === to_type)
        {
            console.log("bravo !");
            score ++;
        }
        else
            console.log("oups");
    }
    console.log(score);
}