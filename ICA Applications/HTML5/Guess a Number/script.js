var globalRandom = undefined;
var guessCount   = undefined;
var parNumber    = undefined;
var minNumber    = undefined;
var maxNumber    = undefined;

function initiatePlay() {
  let x = document.querySelector("input[name*='min']").value;
  let y = document.querySelector("input[name*='max']").value;

  console.log(`Requested parameters min ${x}, max ${y}`);

  if (!randomNumberCheck(x, y)) {
    writeMessage("#status", "Invalid parameters! Please verify that your minimum number is less than your maximum.", "#ff8787");
  } else {
    writeMessage("#status", "Valid parameters. The game will begin!", "#4fca4f");

    // Update data in the DOM and lock parameters

    globalRandom = randomNumber(parseInt(x), parseInt(y));
    guessCount   = 0;
    parNumber    = parGuesses(parseInt(x), parseInt(y), parseInt(y)-parseInt(x)+1);
    minNumber    = parseInt(x);
    maxNumber    = parseInt(y);

    document.querySelectorAll("span:nth-child(2)")[0].innerText = x;
    document.querySelectorAll("span:nth-child(2)")[1].innerText = y;
    document.querySelectorAll("span:nth-child(2)")[2].innerText = parseInt(y)-parseInt(x)+1;
    document.querySelectorAll("span:nth-child(2)")[3].innerText = parGuesses(parseInt(x), parseInt(y), parseInt(y)-parseInt(x)+1);
    document.querySelectorAll("span:nth-child(2)")[4].innerText = guessCount;

    document.querySelector(".button-play").style.display = "none";
    document.querySelector(".button-cancel").style.display = "inline-block";
    document.querySelector(".button-guess").removeAttribute("disabled");
    document.querySelector("input[name*='min']").disabled = "disabled";
    document.querySelector("input[name*='max']").disabled = "disabled";
    document.querySelector("input[name*='guess']").removeAttribute("disabled");

    document.querySelector("input[name*='guess']").min = x;
    document.querySelector("input[name*='guess']").max = y;
  
    document.querySelector("#guess-history").innerHTML = "";
    writeMessage("#game-status", "Please make a guess!", "#f8f9fa");
  }
}

function exitPlay(message) {
  // Update data in the DOM and unlock parameters
  writeMessage("#status", message, "#f8f9fa");
  
  globalRandom = undefined;
  guessCount   = undefined;
  parNumber    = undefined;
  maxNumber    = undefined;
  minNumber    = undefined;

  document.querySelectorAll("span:nth-child(2)")[0].innerText = "N/A";
  document.querySelectorAll("span:nth-child(2)")[1].innerText = "N/A";
  document.querySelectorAll("span:nth-child(2)")[2].innerText = "N/A";
  document.querySelectorAll("span:nth-child(2)")[3].innerText = "N/A";
  document.querySelectorAll("span:nth-child(2)")[4].innerText = "N/A";

  document.querySelector(".button-play").style.display = "inline-block";
  document.querySelector(".button-cancel").style.display = "none";
  document.querySelector(".button-guess").disabled = "disabled";
  document.querySelector("input[name*='min']").removeAttribute("disabled");
  document.querySelector("input[name*='max']").removeAttribute("disabled");
  document.querySelector("input[name*='guess']").disabled = "disabled";

  document.querySelector("input[name*='guess']").value = "";
}

function writeMessage(id, message, color) {
  let element = document.querySelector(id);
  element.innerText = message;
  element.style.color = color;
}

function randomNumberCheck(x, y) {
  let xi = parseInt(x);
  let yi = parseInt(y);
  if (isNaN(xi) || isNaN(yi)) {
    return false;
  } else {
    if (xi >= yi) {
      return false;
    } else {
      return true;
    }
  }
}

function randomNumber(min, max) {
  let seed = Math.random();
  let inclusiveRange = max - min + 1;

  return Math.floor(seed * inclusiveRange) + min;
}

function parGuesses(x, y) {
  let log2 = Math.log(parseInt(y)-parseInt(x)) / Math.log(2);
  return Math.floor(log2) + 1;
}

function initiateGuess() {
  let input = document.querySelector("input[name*='guess']").value;

  if (isNaN(parseInt(input)) || parseInt(input) < minNumber || parseInt(input) > maxNumber) {
    writeMessage("#game-status", "Invalid guess! Please verify that you're within range!", "#ff8787");
    document.querySelector(".button-guess").disabled = "disabled";
    window.setTimeout(function() {
      document.querySelector(".button-guess").removeAttribute("disabled")
    }, 1000);
  } else {
    guessCount += 1;
    document.querySelectorAll("span:nth-child(2)")[4].innerText = guessCount;
    document.querySelector("#guess-history").innerHTML += `<li>${input}</li>`;

    let inputInt = parseInt(input);
    let direction;

    if (inputInt < globalRandom) {
      direction = "up";
    } else if (inputInt > globalRandom) {
      direction = "down"
    }

    if (direction) {
      writeMessage("#game-status", `You guessed wrong; go ${direction}!`, "#ff8787");
      document.querySelector(".button-guess").disabled = "disabled";
      window.setTimeout(function() {
        document.querySelector(".button-guess").removeAttribute("disabled")
      }, 1000);
    } else {
      let parDirection;
      let parDescription;

      if (guessCount < parNumber) {
        parDirection = "below";
        parDescription = "awesome"
      } else if (guessCount == parNumber) {
        parDirection = "equal to";
        parDescription = "okay";
      } else {
        parDirection = "above";
        parDescription = "terrible";
      }

      writeMessage("#game-status", `Victory! You guessed the correct number, ${globalRandom} after ${guessCount} attempts! This is ${parDirection} par, which means you're ${parDescription}!`, "#4fca4f");
      exitPlay("Please enter in your parameters and hit \"Play Game\"!");
    }
  }
}

document.querySelector(".button-play").addEventListener("click", initiatePlay);
document.querySelector(".button-cancel").addEventListener("click", function() {exitPlay("The game has been canceled.")});
document.querySelector(".button-guess").addEventListener("click", initiateGuess);