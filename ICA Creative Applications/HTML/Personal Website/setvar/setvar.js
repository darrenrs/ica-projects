var strings = {
  "noreq": "<span style='background-color: maroon; color: white'>NOT IN REQUEST</span>",
  "nochg": "<span style='background-color: yellow; color: black'>NO CHANGE FROM</span> ",
  "change": " <span style='background-color: lime; color: black'>CHANGED TO</span> ",
  "illegalbool": "<span style='background-color: orange; color: black'>BOOLEAN MUST BE true OR false</span>"
}

var data;

$(document).ready(function() {
  let url = new URL(window.location.href);
  setData(url);

  for (i = 0; i < data.length; i++) {
    let txt;

    if (!data[i][0]) {
      txt = strings['noreq']
    } else if (localStorage.getItem(data[i][2]) == data[i][0].trim()) {
      txt = `${strings['nochg']} ${data[i][0].trim()}`
    } else {
      if (i == 2 && (data[i][0] != 'true' && data[i][0] != 'false')) {
        txt = strings['illegalbool']
      } else {
        txt = `${localStorage.getItem(data[i][2])} ${strings['change']} ${data[i][0]}`
        localStorage.setItem(data[i][2], data[i][0])
      }
    }
    $(data[i][1]).html(txt)
  }
});

function setData(url) {
  data = [
    [
      url.searchParams.get('fb'), '#setvar-fb', 'font-body'
    ],
    [
      url.searchParams.get('fm'), '#setvar-fm', 'font-mono'
    ],
    [
      url.searchParams.get('dm'), '#setvar-dm', 'dm'
    ]
  ]
}