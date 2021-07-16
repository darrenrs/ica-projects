var exitWarning = false;

document.querySelector("#address-master").style.display = "none";
document.querySelector("#job-master").style.display = "none";
document.querySelector("#brother-count").disabled = "disabled";
document.querySelector("#sister-count").disabled = "disabled";
document.querySelector("#dependent-count").disabled = "disabled";

function checkForUpdates() {
  // Address should only be visible if they have a permanent residence
  if (document.querySelector("#home-owner").checked || 
      document.querySelector("#home-renter").checked) {
    document.querySelector("#address-master").style.display = "block";
  } else {
    document.querySelector("#address-master").style.display = "none";
    for (let i of document.querySelectorAll("#address-master input")) {
      i.value = "";
    }
  }
  
  // Brothers, sisters, children can't be > 0 if not checked
  if (document.querySelector("#brother").checked) {
    document.querySelector("#brother-count").removeAttribute("disabled");
  } else {
    document.querySelector("#brother-count").disabled = "disabled";
    document.querySelector("#brother-count").value = "0";
  }

  if (document.querySelector("#sister").checked) {
    document.querySelector("#sister-count").removeAttribute("disabled");
  } else {
    document.querySelector("#sister-count").disabled = "disabled";
    document.querySelector("#sister-count").value = "0";
  }

  if (document.querySelector("#children").checked) {
    document.querySelector("#dependent-count").removeAttribute("disabled");
  } else {
    document.querySelector("#dependent-count").disabled = "disabled";
    document.querySelector("#dependent-count").value = "0";
  }

  // Job should only be visible if they are employed
  if (document.querySelector("#employed").checked) {
    document.querySelector("#job-master").style.display = "block";
  } else {
    document.querySelector("#job-master").style.display = "none";
    for (let i of document.querySelectorAll("#job-master input")) {
      i.value = "";
    }
  }

  let usernameLast = document.querySelector("#name-legal-last").value.toLowerCase().replace(/\W/g, '')
  
  document.querySelector("#username").value = document.querySelector("#name-legal-first").value.toLowerCase().substr(0,1) + usernameLast;
}

window.onbeforeunload = function() {
  if (exitWarning) {
    return true;
  }
};

document.querySelector("#form").addEventListener("submit", function() {
   window.unbind("beforeunload");
});

document.querySelector("#form").addEventListener("change",
  function() {
    checkForUpdates();
    exitWarning = true;
  }
)

document.querySelector("#form").addEventListener("submit",
  function() {
    window.onbeforeunload = null;
  }
)