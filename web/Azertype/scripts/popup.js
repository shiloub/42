function waitpopup() {
    let btnPartage = document.getElementById("btnPartager");
    let popup = document.querySelector(".popupBackground");
    btnPartage.addEventListener("click", (event)=>{
        if (!popup.classList.contains("active"))
            popup.classList.add("active");
        else
            popup.classList.remove("active");
    })
    let backgroud = document.querySelector(".popupBackground");
    backgroud.addEventListener("click", (event)=>{
        if (event.target === backgroud)
            popup.classList.remove("active");
    })
}