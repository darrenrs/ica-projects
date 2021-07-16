var tally = undefined;

function increment() {
  tally += 1;
  localStorage.setItem("tally", tally);
  
  setText();
}

function createText() {
  let tallyString = tally.toString();
  let tallyArray = tallyString.split("");

  for (i of tallyArray) {
    let span = document.createElement("span");
    span.innerText = i;
    span.className = "click-tally-fancy-number";
    document.querySelector('.click-tally-fancy').appendChild(span);
  }
}

function setText() {
  document.querySelector('.click-tally-fancy').innerHTML = "";
  createText();
}

function checkStorage() {
  if (typeof Storage !== "undefined") {
    console.warn("LocalStorage is supported.");

    if (!localStorage.getItem("tally")) {
      localStorage.setItem("tally", 0);
    }

    tally = parseInt(localStorage.getItem("tally"));
  } else {
    console.warn("LocalStorage is NOT supported.");
    tally = 0;
  }
}

function resetStorage() {
  if (typeof Storage !== "undefined") {
    console.warn("LocalStorage is supported.");

    if (!localStorage.getItem("tally")) {
      localStorage.setItem("tally", -1);
    }

    tally = -1;
    document.querySelector(".cursor-button").click();
  } else {
    console.warn("LocalStorage is NOT supported.");
  }
}

// dgaf at this point so I'm being lazy
function changeImage() {
  let currentUrl = document.querySelector(".cursor-button").src;

  if (currentUrl == "https://button-fun.darrenskidmore.repl.co/cursor.png") {
    document.querySelector(".cursor-button").src = "https://upload.wikimedia.org/wikipedia/en/9/9a/Trollface_non-free.png"
  }
}

// dgaf at this point so I'm being lazy
function changeStyle() {
  let backgroundDec = Math.floor(Math.random() * 16777216);
  // TOTALLY not copied from a script I used to troll Ben with back in the day
  document.querySelector("body").style.backgroundColor = "#"+("000000" + (Math.floor(backgroundDec)%16777216).toString(16)).slice(-6);
}

// Execution block
(function() {
  document.querySelector(".cursor-button").addEventListener("click", increment);
  document.querySelector(".reset").addEventListener("click", resetStorage);
  document.querySelector(".change-image").addEventListener("click", changeImage);
  document.querySelector(".change-style").addEventListener("click", changeStyle);

  checkStorage();
  createText();
})();