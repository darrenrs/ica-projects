const stylesheetPairs = [
  {
    "name": "Darren Skidmore",
    "url": "https://css-zen-garden.darrenskidmore.repl.co/zg.css",
    "time": 1603597320
  },
  {
    "name": "Adam Hendrickson",
    "url": "https://zengarden.adamhendrickson.repl.co/style.css",
    "time": 1603597320
  },
  {
    "name": "Jaxon Kern",
    "url": "https://zengarden.jaxonkern.repl.co/style.css",
    "time": 1603597320
  },
  {
    "name": "Thatcher Eames",
    "url": "https://ica-app-zen-garden.eamesth.repl.co/style.css",
    "time": 1603597320
  },
  {
    "name": "Preston Jacobs",
    "url": "https://zengarden.prestonjacobs.repl.co/style.css",
    "time": 1603597320
  },
  {
    "name": "Jake Malone",
    "url": "https://disastrousspitefuladvance.helpmepls123.repl.co/style.css",
    "time": 1603597320
  },
  {
    "name": "Averi McEwen",
    "url": "https://csszengarden.averymcewen.repl.co/style.css",
    "time": 1603597320
  },
  {
    "name": "Ari Taylor",
    "url": "https://css-zen-garden.aritaylor.repl.co/style.css",
    "time": 1603597320
  },
  {
    "name": "Dylan Yarbrough",
    "url": "https://css-zen-guarden.dylanyarbrough.repl.co/style.css",
    "time": 1603597320
  },
  {
    "name": "Dallon Arave",
    "url": "https://css-zen-garden.dallonarave.repl.co/style.css",
    "time": 1603597348
  },
  {
    "name": "Diana Davies (not started)",
    "url": "https://zengarden.dianadavies.repl.co/style.css",
    "time": 1603597502
  },
  {
    "name": "Griffin Ekstrom",
    "url": "https://zengarden.griffinekstrom.repl.co/griffinstyle.css",
    "time": 1603597658
  },
  {
    "name": "Joshua Hadlock (incomplete)",
    "url": "https://css-zen-garden.hadlockjo.repl.co/style.css",
    "time": 1603597801
  },
  {
    "name": "Kevin Morrison (incomplete)",
    "url": "https://le-2-css-zen-garden.kevinmorrison.repl.co/style.css",
    "time": 1603597919
  },
  {
    "name": "Mathieu Lebaron",
    "url": "https://zengarden.mathieulebaron.repl.co/style.css",
    "time": 1603598289
  },
  {
    "name": "Max Mucha",
    "url": "https://Zengarden-CSS-Project.maxmucha1.repl.co/style.css",
    "time": 1603598380
  },
  {
    "name": "Ty Post",
    "url": "https://zengarden.typost.repl.co/style.css",
    "time": 1603598482
  }
];

/*
  CLASS ROSTER

  Name                  repl.it Account Name  Verified?
  Adam Hendrickson      AdamHendrickson       ✔
  ALEXANDER EREKSON     ?                     ✘
  ARI TAYLOR            ARITAYLOR             ✔
  AVERY MCEWEN          AVERYMCEWEN           ✔
  DALLON ARAVE          DALLONARAVE           ✔
  DARREN SKIDMORE       DARRENSKIDMORE        ✔
  DIANA DAVIES          DIANADAVIES           ✔
  DYLAN YARBROUGH       DYLANYARBROUGH        ✔
  GAVIN REESE           ?                     ✘
  GRIFFIN EKSTROM       GRIFFINEKSTROM        ✔
  GAVIN REESE           ?                     ✘
  JACOB MALONE          Helpmepls123          ✔
  JAXON KERN            JAXONKERN             ✔
  GAVIN REESE           ?                     ✘
  JOSHUA HADLOCK        hadlockjo             ✔
  KEVIN MORRISON        KEVINMORRISON         ✔
  MATHIEU LEBARON       MATHIEULEBARON        ✔
  MAX MUCHA             MAXMUCHA1             ✔
  PRESTON JACOBS        PRESTONJACOBS         ✔
  SAMUEL CHARD          ?                     ✘
  SAMUEL WISER          ?                     ✘
  TALEN CHADBURN        TALENCHADBURN         ✔
  THATCHER EAMES        eamesth               ✔
  TRACE KOFORD          ?                     ✘
  TY POST               TYPOST                ✔
  WESTON STEPHENSON     ?                     ✘


*/

function swapStylesheet(sheet){
  document.getElementById("stylesheet").setAttribute("href", sheet); 
}

(function() {
  for (let i of stylesheetPairs) {
    let addedNodeP1 = document.createElement("li");
    let addedNodeP2 = document.createElement("a");

    addedNodeP2.addEventListener("click", function() {
      swapStylesheet(i["url"]);
    });
    addedNodeP2.innerText = i["name"];

    addedNodeP1.appendChild(addedNodeP2);

    document.querySelector(".section4 ul").appendChild(addedNodeP1);
  }
})();