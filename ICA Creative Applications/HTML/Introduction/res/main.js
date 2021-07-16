$(document).ready(function() {
  date = (new Date()).toISOString();
  $("#time").text(date)

  for (i = 0; i < 999; i++) {
    let append;
    if (i == 665) {
      append = "<li>Satan</li>";
    } else {
      append = "<li>"+Math.round(Math.random()*1000)+"</li>";
    }
    $("#list").append(append);
  }
}
)