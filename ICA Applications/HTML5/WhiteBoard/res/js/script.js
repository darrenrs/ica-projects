function checkStorage() {
  if (typeof Storage !== "undefined") {
    console.warn("LocalStorage is supported.");

    return true;
  } else {
    return false;
  }
}

function setStorage() {
  if (!localStorage.getItem("dark-mode")) {
    localStorage.setItem("dark-mode", "false");
  }

  darkMode = JSON.parse(localStorage.getItem("dark-mode"));
}

function toggleDarkMode() {
  if (darkMode) {
    darkMode = false;
  } else {
    darkMode = true;
  }

  localStorage.setItem("dark-mode", darkMode);
  setDarkMode();
}

function setDarkMode() {
  for (let i of document.querySelectorAll(".dark-state-enabled")) {
    if (darkMode) {
      i.classList.add("dark");
    } else {
      i.classList.remove("dark");
    }
  }
  
  if (darkMode) {
    document.querySelector("#dark-mode").innerText = String.fromCodePoint(0x1f31c);
    document.querySelector("link[rel=manifest]").href = "/manifest_dark.json";
    document.querySelector("meta[name=apple-mobile-web-app-status-bar-style]").setAttribute("content", "black");
  } else {
    document.querySelector("#dark-mode").innerText = String.fromCodePoint(0x1f31e);
    document.querySelector("link[rel=manifest]").href = "/manifest.json";
    document.querySelector("meta[name=apple-mobile-web-app-status-bar-style]").setAttribute("content", "white");
  }
}

if (checkStorage()) {
  setStorage();
  setDarkMode();
}

document.querySelector("#dark-mode").addEventListener("click", toggleDarkMode);

// https://developers.google.com/web/ilt/pwa/introduction-to-service-worker
if ("serviceWorker" in navigator) {
  navigator.serviceWorker.register("/sw.js", {
    scope: "/"
  })
  .then(function(registration) {
    console.log(`Registration successful, scope is ${registration.scope}`);
  })
  .catch(function(error) {
    console.error(`Service worker registration failed, error is ${error}`);
  });
}