var areas = document.querySelectorAll("area");

for (i of areas) {
  i.addEventListener("click", function() {
    let territory = this.getAttribute("territory");
    let suffix = "";
    let dataKey = 0;

    document.querySelector(".clicked-territory").innerText = territory;

    let territoryNameMod = territory.toLowerCase().replace(" ","-");

    document.querySelector(".wikipage").setAttribute("url", `https://www.nytimes.com/interactive/2020/11/03/us/elections/results-${territoryNameMod}.html`);
    
    for (j of data) {
      if (j["id"] == this.getAttribute("tid")) {
        break;
      } else {
        dataKey++;
      }
    }

    if (data[dataKey]["trump"] > data[dataKey]["biden"]) {
      document.querySelector(".clicked-party").innerText = "Unfortunately,";
      document.querySelector(".clicked-politics").innerText = "Donald Trump";
    } else {
      document.querySelector(".clicked-party").innerText = "Fortunately,";
      document.querySelector(".clicked-politics").innerText = "Joe Biden";
    }

    let bidenProp = data[dataKey]["biden"] / data[dataKey]["total"];
    let trumpProp = data[dataKey]["trump"] / data[dataKey]["total"];

    let rawMargin = Math.abs(bidenProp-trumpProp);
    let rawMarginQD = "";

    document.querySelector(".clicked-politics-margin").innerText = (rawMargin*100).toPrecision(2)+"%";

    if (rawMargin > 0.30) {
      rawMarginQD = "whopping";
    } else if (rawMargin > 0.20) {
      rawMarginQD = "huge";
    } else if (rawMargin > 0.10) {
      rawMarginQD = "large";
    } else if (rawMargin > 0.05) {
      rawMarginQD = "moderate";
    } else if (rawMargin > 0.03) {
      rawMarginQD = "slim";
    } else if (rawMargin > 0.01) {
      rawMarginQD = "small";
    } else {
      rawMarginQD = "razor-thin";
    }

    document.querySelector(".clicked-politics-mqd").innerText = rawMarginQD

    document.querySelector(".clicked-data").style = "display: block";
  });
}

document.querySelector(".nojs").parentNode.removeChild( document.querySelector(".nojs") );
for (j of data) {
  let tr = document.createElement("tr");
  let tdk = ["state", "id", "trump", "biden", "total"];
  let td = [];

  if ( j[tdk[3]] > j[tdk[2]] ) {
    tr.classList.add("tr-democratic");
  } else {
    tr.classList.add("tr-republican");
  }

  for (k = 0; k <= tdk.length; k++) {
    let tdx = document.createElement("td");
    
    switch (k) {
      case 0:
        tdx.innerText = j[tdk[0]];
        break;
      case 1:
        if ( j[tdk[3]] > j[tdk[2]] ) {
          tdx.innerText = "Democratic";
        } else {
          tdx.innerText = "Republican";
        }
        break;
      case 2:
        tdx.innerText = j[tdk[3]].toLocaleString()
        break;
      case 3:
        tdx.innerText = j[tdk[2]].toLocaleString()
        break;
      case 4:
        tdx.innerText = (( j[tdk[3]] / j[tdk[4]] )*100).toFixed(1)+"%"
        break;
      case 5:
        tdx.innerText = (( j[tdk[2]] / j[tdk[4]] )*100).toFixed(1)+"%"
        break;
      default:
        tdx.innerText = "WTF";
    }

    td.push(
      tdx
    )
  }

  for (l of td) {
    tr.appendChild(l);
  }

  document.querySelector("tbody").appendChild(tr);
}

document.querySelector(".wikipage").addEventListener("click", function() {
  window.open(this.getAttribute("url"));
});